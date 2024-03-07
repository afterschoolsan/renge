#ifndef RENGE_DEFINES_H_
#define RENGE_DEFINES_H_

#if defined(_MSC_VER)
    #define RN_COMPILER_MSVC
#elif defined (__gcc__) || defined(__GCC__)
    #define RN_COMPILER_GCC
#elif defined (__clang__)
    #define RN_COMPILER_CLANG
#else
    #define RN_COMPILER_UNKNOWN
#endif

/** Platform detection */
#if defined(_WIN32) || defined(__WIN32__)
    #define RN_PLATFORM_WINDOWS
    #define RN_PLATFORM_DESKTOP
#elif defined(__ANDROID__)
    #define RN_PLATFORM_ANDROID
    #define RN_PLATFORM_MOBILE
#elif defined(__linux__) || defined(__gnu_linux__)
    #define RN_PLATFORM_LINUX
    #define RN_PLATFORM_DESKTOP
#else
    #define RN_PLATFORM_UNKNOWN
#endif

#ifndef RN_STATIC_ASSERT
    #ifdef RN_COMPILER_MSVC
        #define RN_STATIC_ASSERT _Static_assert
    #else
        #define RN_STATIC_ASSERT static_assert
    #endif
#endif

#ifndef RN_VA_LIST
#define RN_VA_LIST
    #ifdef RN_COMPILER_MSVC
        typedef __builtin_va_list rn_va_list;
        #define rn_va_start(ap, param) __builtin_va_start(ap, param)
        #define rn_va_end(ap) __builtin_va_end(ap)
        #define rn_va_arg(ap, type) __builtin_va_arg(ap, type)
    #else
        typedef __builtin_va_list rn_va_list;
        #define rn_va_start(ap, param) __builtin_va_start(ap, param)
        #define rn_va_end(ap) __builtin_va_end(ap)
        #define rn_va_arg(ap, type) __builtin_va_arg(ap, type)
    #endif

    #ifndef _VA_LIST
    #define _VA_LIST
        typedef rn_va_list va_list;
        #define va_start(ap, param) rn_va_start(ap, param)
        #define va_end(ap) rn_va_end(ap)
        #define va_arg(ap, type) rn_va_arg(ap, type)
    #endif
#endif

#define RN_LOGGING_BUFFER_CAPACITY (32*1024)

#ifndef RN_CAST
    #define RN_CAST(T, v) ((T)(v))
#endif

typedef signed char       i8;
typedef signed short      i16;
typedef signed int        i32;
typedef signed long long  i64;
RN_STATIC_ASSERT(sizeof(i8) == 1, "Expecting sizeof(i8) == 1");
RN_STATIC_ASSERT(sizeof(i16) == 2, "Expecting sizeof(i16) == 2");
RN_STATIC_ASSERT(sizeof(i32) == 4, "Expecting sizeof(i32) == 4");
RN_STATIC_ASSERT(sizeof(i64) == 8, "Expecting sizeof(i64) == 8");

typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned int        u32;
typedef unsigned long long  u64;
RN_STATIC_ASSERT(sizeof(u8) == 1, "Expecting sizeof(u8) == 1");
RN_STATIC_ASSERT(sizeof(u16) == 2, "Expecting sizeof(u16) == 2");
RN_STATIC_ASSERT(sizeof(u32) == 4, "Expecting sizeof(u32) == 4");
RN_STATIC_ASSERT(sizeof(u64) == 8, "Expecting sizeof(u64) == 8");

// TODO: check platform first
typedef u64 usize;

#define RN_NULL RN_CAST(void *, 0)

#define RN_OK 0
#define RN_NULL_ARGUMENT -1
#define RN_ALLOCATION_FAILED -2

#endif // RENGE_DEFINES_H_
