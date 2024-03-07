#ifndef RENGE_STRING_H_
#define RENGE_STRING_H_

#include "renge/core/defines.h"

i32 rn_string_format(char *writable, size_t writable_capacity, const char *fmt, ...);
i32 rn_string_format_v(char *writable, size_t writable_capacity, const char *fmt, va_list ap);

usize rn_strlen(const char *cstr);

#endif // RENGE_STRING_H_
