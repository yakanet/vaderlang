/* DEMO (main), library demo: <demo.h> */
void demo_count(const uint32_t* n);  // main$demo_count
int64_t demo_fill(void* buf, uint64_t size);  // main$demo_fill
int32_t demo_now(struct timespec* t);  // main$demo_now
void demo_read(const unsigned int* cells);  // main$demo_read
size_t demo_size(size_t n);  // main$demo_size

/* no CLibrary, no header: the compiler writes the prototype */
int32_t puts(const char* s);  // main$c_puts
const char* ttyname(int32_t fd);  // main$terminal_name

/* no CLibrary: <fcntl.h> */
int32_t fcntl(int32_t fd, int32_t command, ...);  // main$set_flags, variadic: int32_t flags
