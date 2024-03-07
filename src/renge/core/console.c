#include "renge/core/console.h"
#include "renge/core/memory.h"
#include "renge/core/defines.h"
#include "renge/core/string.h"

void rn_printf(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    char buffer[RN_LOGGING_BUFFER_CAPACITY];
    rn_memset(buffer, 0, sizeof(buffer));
    i32 written = rn_string_format_v(buffer, sizeof(buffer), fmt, ap);
    rn_console_write(buffer, written);
    va_end(ap);
}

void rn_eprintf(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    char buffer[RN_LOGGING_BUFFER_CAPACITY];
    rn_memset(buffer, 0, sizeof(buffer));
    i32 written = rn_string_format_v(buffer, sizeof(buffer), fmt, ap);
    rn_console_error(buffer, written);
    va_end(ap);
}

#if defined(RN_PLATFORM_WINDOWS)
#include <windows.h>

void rn_console_write(const char *message, usize message_length)
{
    if(!message) return;

    HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD number_written = 0;
    WriteConsoleA(console_handle, 
            message, 
            (DWORD)message_length, 
            &number_written, 0);
}

void rn_console_error(const char *message, usize message_length)
{
    if(!message) return;

    HANDLE console_handle = GetStdHandle(STD_ERROR_HANDLE);
    DWORD number_written = 0;
    WriteConsoleA(console_handle,
            message, 
            (DWORD)message_length, 
            &number_written, 0);
}

#endif
