/* CLOCK (system/posix): <time.h> */
int32_t clock_gettime(int32_t clock_id, void* ts);  // system_posix$sys_clock_gettime
int32_t nanosleep(const void* req, void* rem);  // system_posix$sys_nanosleep

/* DARWIN (system/darwin): <mach-o/dyld.h>, <mach/mach.h> */
int32_t _NSGetExecutablePath(void* buf, void* size);  // system_darwin$ns_get_executable_path
uint32_t mach_task_self(void);  // system_darwin$mach_task_self
int32_t task_info(uint32_t task, uint32_t flavor, void* info, void* count);  // system_darwin$task_info

/* FILE_SYSTEM (system/posix): <dirent.h>, <fcntl.h>, <stdlib.h>, <sys/stat.h> */
int32_t closedir(void* dir);  // system_posix$sys_closedir
int32_t mkdir(const char* path, uint32_t mode);  // system_posix$sys_mkdir
int32_t open(const char* path, int32_t flags, ...);  // system_posix$sys_open, variadic: int32_t mode
void* opendir(const char* path);  // system_posix$sys_opendir
void* readdir(void* dir);  // system_posix$sys_readdir
void* realpath(const char* path, void* resolved);  // system_posix$sys_realpath

/* KERNEL32 (system/windows), library kernel32: <windows.h> */
bool CloseHandle(void* h);  // system_windows$close_handle
bool CreateDirectoryW(const void* path, void* security);  // system_windows$create_directory
void* CreateFileW(const void* path, uint32_t access, uint32_t share, void* security, uint32_t disposition, uint32_t flags, void* template);  // system_windows$create_file_w
bool CreateProcessA(void* application, void* command_line, void* proc_attrs, void* thread_attrs, bool inherit, uint32_t flags, void* environment, void* directory, STARTUPINFOA* startup, PROCESS_INFORMATION* info);  // system_windows$create_process
int32_t DeleteFileW(const void* path);  // system_windows$delete_file
bool FindClose(void* handle);  // system_windows$find_close
void* FindFirstFileW(const void* pattern, void* data);  // system_windows$find_first_file
bool FindNextFileW(void* handle, void* data);  // system_windows$find_next_file
bool FlushConsoleInputBuffer(void* h);  // system_windows$flush_console_input_buffer
uint32_t GetActiveProcessorCount(uint16_t group);  // system_windows$get_active_processor_count
bool GetConsoleMode(void* h, void* mode);  // system_windows$get_console_mode
bool GetConsoleScreenBufferInfo(void* h, CONSOLE_SCREEN_BUFFER_INFO* info);  // system_windows$get_console_screen_buffer_info
uint32_t GetCurrentDirectoryW(uint32_t size, void* buf);  // system_windows$get_current_directory
bool GetExitCodeProcess(void* h, void* code);  // system_windows$get_exit_code_process
bool GetFileAttributesExW(const void* path, int32_t level, void* data);  // system_windows$get_file_attributes_ex
uint32_t GetFileAttributesW(const void* path);  // system_windows$get_file_attributes
bool GetFileSizeEx(void* h, void* size);  // system_windows$get_file_size_ex
uint32_t GetFileType(void* h);  // system_windows$get_file_type
uint32_t GetFinalPathNameByHandleW(void* h, void* buf, uint32_t size, uint32_t flags);  // system_windows$get_final_path_name_by_handle_w
uint32_t GetLastError(void);  // system_windows$get_last_error
uint32_t GetModuleFileNameW(void* module, void* buf, uint32_t size);  // system_windows$get_module_file_name
void* GetStdHandle(uint32_t which);  // system_windows$get_std_handle
void GetSystemTimePreciseAsFileTime(void* ft);  // system_windows$get_system_time_precise_as_file_time
uint32_t GetTempPathW(uint32_t size, void* buf);  // system_windows$get_temp_path
int32_t MultiByteToWideChar(uint32_t code_page, uint32_t flags, const char* src, int32_t src_len, void* dst, int32_t dst_len);  // system_windows$multi_byte_to_wide_char
bool PeekNamedPipe(void* h, void* buf, uint32_t size, void* read, void* available, void* message);  // system_windows$peek_named_pipe
bool QueryPerformanceCounter(void* counter);  // system_windows$query_performance_counter
bool QueryPerformanceFrequency(void* freq);  // system_windows$query_performance_frequency
bool ReadFile(void* h, void* buf, uint32_t count, void* read, void* overlapped);  // system_windows$read_file
bool SetConsoleMode(void* h, uint32_t mode);  // system_windows$set_console_mode
int32_t SetCurrentDirectoryW(const void* path);  // system_windows$set_current_directory
uint32_t SetFilePointer(void* h, int32_t low, void* high, uint32_t method);  // system_windows$set_file_pointer
void Sleep(uint32_t ms);  // system_windows$sleep_ms
bool TerminateProcess(void* h, uint32_t code);  // system_windows$terminate_process
uint32_t WaitForSingleObject(void* h, uint32_t timeout_ms);  // system_windows$wait_for_single_object
int32_t WideCharToMultiByte(uint32_t code_page, uint32_t flags, const void* src, int32_t src_len, void* dst, int32_t dst_len, void* default_char, void* used_default);  // system_windows$wide_char_to_multi_byte
bool WriteConsoleW(void* h, const void* text, uint32_t count, void* written, void* reserved);  // system_windows$write_console_w
bool WriteFile(void* h, const void* buf, uint32_t count, void* written, void* overlapped);  // system_windows$write_file

/* LIBC (system/libc): <stdio.h>, <stdlib.h> */
int32_t fclose(void* stream);  // system_libc$sys_fclose
int32_t ferror(void* stream);  // system_libc$sys_ferror
void* fopen(const char* path, const char* mode);  // system_libc$sys_fopen
int64_t fread(void* buf, int64_t size, int64_t count, void* stream);  // system_libc$sys_fread
void free(void* p);  // system_libc$sys_free
int64_t fwrite(const void* buf, int64_t size, int64_t count, void* stream);  // system_libc$sys_fwrite
const char* getenv(const char* name);  // system_libc$sys_getenv

/* LIBM (std/math): <math.h> */
double acos(double x);  // std_math$acos
double asin(double x);  // std_math$asin
double atan(double x);  // std_math$atan
double atan2(double y, double x);  // std_math$atan2
double ceil(double x);  // std_math$ceil
double cos(double x);  // std_math$cos
double exp(double x);  // std_math$exp
double floor(double x);  // std_math$floor
double hypot(double x, double y);  // std_math$hypot
double log(double x);  // std_math$log
double log10(double x);  // std_math$log10
double log2(double x);  // std_math$log2
double pow(double x, double n);  // std_math$pow
double round(double x);  // std_math$round
double sin(double x);  // std_math$sin
double sqrt(double x);  // std_math$sqrt
double tan(double x);  // std_math$tan
double trunc(double x);  // std_math$trunc

/* POLL (system/posix): <poll.h> */
int32_t poll(struct pollfd* fds, uint64_t nfds, int32_t timeout_ms);  // system_posix$sys_poll_one

/* RESOURCE (system/posix): <sys/resource.h> */
int32_t getrusage(int32_t who, void* usage);  // system_posix$sys_getrusage

/* SPAWN (system/posix): <signal.h>, <spawn.h>, <string.h>, <sys/wait.h> */
int32_t kill(int32_t pid, int32_t sig);  // system_posix$sys_kill
int32_t posix_spawn_file_actions_addclose(void* actions, int32_t fd);  // system_posix$sys_spawn_actions_addclose
int32_t posix_spawn_file_actions_adddup2(void* actions, int32_t fd, int32_t newfd);  // system_posix$sys_spawn_actions_adddup2
int32_t posix_spawn_file_actions_destroy(void* actions);  // system_posix$sys_spawn_actions_destroy
int32_t posix_spawn_file_actions_init(void* actions);  // system_posix$sys_spawn_actions_init
int32_t posix_spawnp(void* pid, const char* file, const void* actions, void* attrp, const void* argv, void* envp);  // system_posix$sys_posix_spawnp
void* strdup(const char* s);  // system_posix$sys_strdup
int32_t waitpid(int32_t pid, void* status, int32_t options);  // system_posix$sys_waitpid

/* TERMINAL (system/posix): <sys/ioctl.h>, <termios.h> */
void cfmakeraw(void* buf);  // system_posix$sys_cfmakeraw
int32_t ioctl(int32_t fd, uint64_t request, ...);  // system_posix$sys_ioctl_winsize, variadic: struct winsize* ws
int32_t tcgetattr(int32_t fd, void* buf);  // system_posix$sys_tcgetattr
int32_t tcsetattr(int32_t fd, int32_t action, const void* buf);  // system_posix$sys_tcsetattr

/* UNISTD (system/posix): <unistd.h> */
int32_t access(const char* path, int32_t mode);  // system_posix$sys_access
int32_t chdir(const char* path);  // system_posix$sys_chdir
int32_t close(int32_t fd);  // system_posix$sys_close
void* getcwd(void* buf, int64_t size);  // system_posix$sys_getcwd
int32_t isatty(int32_t fd);  // system_posix$sys_isatty
int64_t lseek(int32_t fd, int64_t offset, int32_t whence);  // system_posix$sys_lseek
int32_t pipe(void* fds);  // system_posix$sys_pipe
int64_t read(int32_t fd, void* buf, int64_t count);  // system_posix$sys_read
int64_t readlink(const char* path, void* buf, int64_t size);  // system_posix$sys_readlink
int64_t sysconf(int32_t name);  // system_posix$sys_sysconf
int32_t unlink(const char* path);  // system_posix$sys_unlink
int64_t write(int32_t fd, const void* buf, int64_t count);  // system_posix$sys_write

/* VADER_RUNTIME (system/posix): vader.h */
const char* vader_dirent_name(void* ent);  // system_posix$dirent_name
void* vader_environ(void);  // system_posix$sys_environ
int32_t vader_fd_kind(int32_t fd);  // system_posix$sys_fd_kind
int64_t vader_fd_size(int32_t fd);  // system_posix$sys_fd_size
int32_t vader_last_errno(void);  // system_posix$sys_last_errno
int32_t vader_path_kind(const char* path);  // system_posix$sys_path_kind
int64_t vader_path_mtime(const char* path);  // system_posix$sys_path_mtime
int64_t vader_stream_size(void* stream);  // system_posix$sys_stream_size

/* VADER_RUNTIME (system/windows): vader.h */
int64_t vader_console_read(void* buf, int64_t max);  // system_windows$console_read
const char* vader_find_data_name(const void* data);  // system_windows$find_data_name
bool vader_overlapped_pipe(void* read_end, void* write_end);  // system_windows$create_watched_pipe
void* vader_ptr_at(const void* base, int64_t i);  // system_windows$ptr_at
bool vader_stdin_await_reader(int32_t timeout_ms);  // system_windows$await_stdin_reader
