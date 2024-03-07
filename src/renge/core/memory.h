#ifndef RENGE_MEMORY_H_
#define RENGE_MEMORY_H_

#include "renge/core/defines.h"

typedef struct rn_heap_buffer {
    void *ptr;
    usize size;
} rn_heap_buffer;

/**
 * Platform spesific heap allocation. Using MMAP in unix-like system and VirtualAlloc in windows
 * Not recommended to be used directly please use some form of allocator
 */
i32 rn_init_native_heap_buffer(rn_heap_buffer *buffer, usize wanted_size);
void rn_deinit_native_heap_buffer(rn_heap_buffer buffer);


typedef struct rn_arena_allocator rn_arena_allocator;

rn_arena_allocator *rn_create_arena_allocator();
void rn_destroy_arena_allocator(rn_arena_allocator *allocator);
void rn_arena_alloc(rn_arena_allocator *allocator, usize size);
void rn_arena_reset(rn_arena_allocator *allocator);

void *rn_memcpy(void *dst, const void *src, usize size);
void *rn_memset(void *dst, const int value, usize size);

#endif // RENGE_MEMORY_H_
