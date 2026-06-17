// TypeScript peer of bench/str_concat/str_concat.vader. Same algorithm (build
// a 13-byte string by repeated +, 300 000 times), same checksum. The Vader
// checksum sums bytes().len() ; for this ASCII payload that equals the JS
// string length.

let total = 0;
for (let i = 0; i < 300_000; i++) {
  let s = "a";
  s = s + "bcd";
  s = s + "efgh";
  s = s + "ijklm";
  total += s.length;
}
console.log(`str_concat ${total}`);
