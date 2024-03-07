#include "renge/core/string.h"
#include "renge/core/defines.h"
#include "renge/external/stb/stb_sprintf.h"

usize rn_strlen(const char *cstr)
{
    if(!cstr) return 0;

    usize i = 0;
    while(cstr[i++] != '\0');
    return i;
}

i32 rn_string_format(char *writable, size_t writable_capacity, const char *fmt, ...)
{
    if(!fmt) return RN_NULL_ARGUMENT;

    va_list ap;
    va_start(ap, fmt);
    i32 result = rn_string_format_v(writable, writable_capacity, fmt, ap);
    va_end(ap);
    return result;
}

i32 rn_string_format_v(char *writable, size_t writable_capacity, const char *fmt, va_list ap)
{
    if(!writable) return RN_NULL_ARGUMENT;
    if(!writable_capacity) return RN_NULL_ARGUMENT;
    if(!fmt) return RN_NULL_ARGUMENT;

    return stbsp_vsnprintf(writable, (int)writable_capacity, fmt, ap);
}
