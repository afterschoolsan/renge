#include "memory.h"
#include "renge/core/defines.h"

void *rn_memcpy(void *dst, const void *src, usize size)
{
    if(!dst) return RN_NULL;
    if(!src) return RN_NULL;

    for(usize i = 0; i < size; ++i)
        RN_CAST(u8 *, dst)[i] = RN_CAST(u8 *, src)[i];
    return dst;
}

void *rn_memset(void *dst, const int value, usize size)
{
    if(!dst) return RN_NULL;

    for(usize i = 0; i < size; ++i)
        RN_CAST(u8 *, dst)[i] = RN_CAST(u8, value);
    return dst;
}

#if defined(RN_PLATFORM_WINDOWS)
#include <windows.h>
#define INV_HANDLE(p) (((p) == 0) || (p) == INVALID_HANDLE_VALUE)

i32 rn_init_native_heap_buffer(rn_heap_buffer *buffer, usize wanted_size)
{
    if(!buffer) return RN_NULL_ARGUMENT;
    void *result = VirtualAllocEx(
            GetCurrentProcess(),
            0,
            wanted_size,
            MEM_COMMIT | MEM_RESERVE,
            PAGE_READWRITE);
    if(INV_HANDLE(result)) return RN_ALLOCATION_FAILED;
    buffer->ptr = result;
    buffer->size = wanted_size;
    return RN_OK;
}

void rn_deinit_native_heap_buffer(rn_heap_buffer buffer)
{
    if(INV_HANDLE(buffer.ptr)) return;

    VirtualFreeEx(
            GetCurrentProcess(),
            (LPVOID)buffer.ptr,
            buffer.size,
            MEM_RELEASE);
}
#endif
