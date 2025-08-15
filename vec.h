#if !defined(VEC_H)
#define VEC_H

#include <stddef.h>

struct vector;
struct allocator {
    void *(*const allocate)(size_t size);
    void (*const deallocate)(void *ptr);
};

enum vector_status {
    VECTOR_SUCCESS,
    VECTOR_INVALID_ARGUMENT,
    VECTOR_OUT_OF_MEMORY,
    VECTOR_EMPTY,
    VECTOR_INDEX_OUT_OF_BOUNDS,
};

enum vector_status vector_init(struct vector *const self, const size_t esize, const size_t cap, const struct allocator *const allocator);
enum vector_status vector_deinit(struct vector *const self);
enum vector_status vector_push(struct vector *const self, const void *const elem);
enum vector_status vector_pop(struct vector *const self, void *const elem);
enum vector_status vector_get(const struct vector *const self, const size_t index, void *const elem);
enum vector_status vector_set(struct vector *const self, const size_t index, const void *const elem);

#endif