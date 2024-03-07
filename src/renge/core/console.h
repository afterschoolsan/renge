#ifndef RENGE_CONSOLE_H_
#define RENGE_CONSOLE_H_

#include "renge/core/defines.h"

void rn_console_write(const char *message, usize message_length);
void rn_console_error(const char *message, usize message_length);

void rn_printf(const char *fmt, ...);
void rn_eprintf(const char *fmt, ...);

typedef enum rn_log_level {
    RN_LOG_INFO = 0,
    RN_LOG_WARN,
    RN_LOG_ERROR,
    RN_LOG_FATAL,
} rn_log_level;

void rn_tracelog(rn_log_level level, const char *fmt, ...);

#endif // RENGE_CONSOLE_H_
