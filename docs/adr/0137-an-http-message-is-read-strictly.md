# 0137: An HTTP/1.1 message is read strictly

## Status

Accepted (2026-11-13).

## Context

RFC 9112 lets a recipient forgive several things: a line feed alone for a line
break, whitespace where the grammar has none, a length written twice. Each of
them is also a way for two programs on one connection to disagree on where a
message ends, which is what request smuggling is. A server written in Vader
will sit behind proxies it does not choose.

The flaws published against other implementations show what the leniency
costs. The CVE records that name request smuggling, response splitting, chunk
extensions or llhttp were taken from the NVD (2026-11-13). Those that name one
of the servers and parsers in wide use were all read: Node.js (llhttp), Netty,
Tomcat, Jetty, Undertow, hyper, Go `net/http`, Waitress, Gunicorn, h11, Puma,
Uvicorn, WEBrick, Twisted, Squid, HAProxy, Apache httpd, Apache Traffic
Server, lighttpd. The records against other products were then searched by a
second pass for inputs the first had not met; it found the same classes
(cpp-httplib, libsoup, Tornado, aiohttp, tiny-http, Mint, Bandit, http4s,
Cap'n Proto, undici), and those whose text gives an input are listed below.
A record whose text describes an HTTP/1.1 endpoint reading or writing a
message was kept.

## Decision

- **`lib/http` takes no leniency the RFC only allows.** A line ends with CRLF.
  A field name is a token followed by its colon. A length is digits. A message
  with a transfer coding and a length, or a coding in HTTP/1.0, is refused.
  A request whose last coding is not `chunked` is refused.
- **What is written is checked as what is read is.** A name, a value or a
  target that could open a line is refused before a byte goes out.
- **Each family of published flaws has a test** in `lib/http/hardening.vader`
  that replays its input. A flaw with no test is supposed avoided, not shown.
- **Chunk extensions are bounded in total, not only per line.**
  `Limits.chunk_extensions` caps what the lines that open the chunks of one body
  take beyond the data of their chunk (RFC 9112, section 7.1.1, asks a server
  to limit their total length). The review found the gap:
  a body of 64 bytes could take hundreds of kilobytes to read, which `drain`
  would have read past.

## Consequences

A client that sends a bare line feed, a folded field or `Content-Length: +5`
gets a 400 where other servers answer. That is the intent.

What a proxy owes its two sides (forwarding, hop-by-hop fields, caches) and
what other protocols carry (HTTP/2, HTTP/3, AJP, FastCGI) is out of the
review: `lib/http` is an endpoint of HTTP/1.1. So are the records whose text
says nothing of the input, and what a server does with time and connections,
which belongs with the server.

One class is still open. `read_request` reads whatever follows the last head:
a body nobody read is taken for the next request (CVE-2026-34441,
CVE-2022-21826), and the same holds of a response on a connection a client
uses again. `persists` and `drain` close it only for a caller that remembers
to call them. It is to be closed by construction, in a record of its own.

## The review

Each test of `lib/http/hardening.vader`, unless another file is named, and the
records it answers.

| Test | Records |
|---|---|
| `test_a_line_feed_alone_hides_no_field` | CVE-2019-16785, CVE-2020-1935, CVE-2022-32214, CVE-2022-35256, CVE-2025-3110 |
| `test_a_carriage_return_alone_ends_no_line` | CVE-2023-30589, CVE-2025-23167, CVE-2026-28367 |
| `test_whitespace_before_a_colon_names_no_field` | CVE-2019-16869, CVE-2021-22959, CVE-2026-86146 |
| `test_whitespace_before_a_name_continues_no_field` | CVE-2020-7238, CVE-2022-32215, CVE-2024-27982, CVE-2026-28369, CVE-2026-86146 |
| `test_a_control_byte_is_part_of_no_name_and_no_value` | CVE-2015-5739, CVE-2019-16789, CVE-2020-10687, CVE-2021-20220, CVE-2021-43797, CVE-2023-38522, CVE-2024-52530 |
| `test_a_long_field_name_is_kept_whole` | CVE-2026-58155 |
| `test_a_content_length_is_digits_and_nothing_else` | CVE-2020-15049, CVE-2021-32715, CVE-2022-24761, CVE-2022-42252, CVE-2023-38697, CVE-2023-40167, CVE-2023-40175, CVE-2026-32239, CVE-2026-86146 |
| `test_two_content_lengths_that_differ_frame_nothing` | CVE-2019-16792, CVE-2026-23941 |
| `test_a_transfer_coding_and_a_length_frame_nothing` | CVE-2021-33037, CVE-2024-23452, CVE-2026-42581, CVE-2026-77756 |
| `test_chunked_is_the_last_coding_of_a_request_or_none_is` | CVE-2019-15605, CVE-2019-17569, CVE-2019-18277, CVE-2020-8287, CVE-2021-21299, CVE-2021-33037, CVE-2022-1705, CVE-2022-32213, CVE-2024-1135, CVE-2024-6827, CVE-2024-14029, CVE-2026-42585, CVE-2026-61642, CVE-2026-66752, CVE-2026-89044, CVE-2026-93562, CVE-2026-93573, CVE-2026-94194 |
| `test_a_request_carries_its_body_whatever_its_method` | CVE-2024-33452, CVE-2026-111809 |
| `test_a_line_feed_alone_ends_nothing_in_a_chunked_body` | CVE-2021-22960, CVE-2023-38697, CVE-2023-46846, CVE-2024-52304, CVE-2025-22871, CVE-2025-43859, CVE-2025-58056, CVE-2026-1801, CVE-2026-19203, CVE-2026-114216 |
| `test_a_chunk_size_is_hexadecimal_digits_and_nothing_else` | CVE-2022-24761, CVE-2023-38697, CVE-2026-69216, CVE-2026-82672, CVE-2026-93566, CVE-2026-93574 |
| `test_a_chunk_size_too_large_wraps_to_no_other_size` | CVE-2020-10719, CVE-2021-32714, CVE-2026-3945, CVE-2026-32240, CVE-2026-42580 |
| `test_a_quoted_string_of_an_extension_ends_on_its_line` | CVE-2026-2332, CVE-2026-24880, CVE-2026-33870 |
| `test_the_line_that_opens_a_chunk_is_bounded` (chunked.vader) | CVE-2012-3544, CVE-2024-21647, CVE-2024-22019 |
| `test_chunk_extensions_cost_a_body_no_more_than_it_carries` | CVE-2023-39326 |
| `test_trailer_fields_are_no_fields_of_the_request` | CVE-2025-12642, CVE-2026-86146 |
| `test_trailer_fields_are_bounded_and_checked_as_fields_are` | CVE-2023-40175, CVE-2023-45648, CVE-2023-46589 |
| `test_a_response_field_cannot_open_a_line` | CVE-2019-16254, CVE-2020-5247, CVE-2020-5249, CVE-2020-7695, CVE-2022-41915, CVE-2024-23644, CVE-2025-0825, CVE-2026-34715, CVE-2026-66753 |
| `test_a_message_is_written_with_one_length` | CVE-2026-1525 |
| `test_a_request_target_cannot_open_a_line` | CVE-2025-67735, CVE-2026-41417, CVE-2026-48861 |
| `test_an_interim_response_takes_the_place_of_no_final_one` | CVE-2026-100666 |
| `test_a_connection_that_leaves_http_carries_no_further_exchange` (connection.vader) | CVE-2026-94439 |
| `test_a_body_that_fails_ends_its_connection` | CVE-2022-22720, CVE-2026-55612 |

A record is listed under the test that replays the input its text describes.
Where the text names only a class of input ("invalid characters", "malformed
Transfer-Encoding"), the test covers the class as the RFC bounds it, not the
one input that was exploited.
