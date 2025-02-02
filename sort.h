#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

/**
 * @brief Recursive implementation of a quicksort. The array is sorted in place.
 * @param list An array to sort.
 * @param *isGreater The pointer to a function that, given two elements, return true if the first element is strictly greater than the second.
 * @param elem_size The size of an element in the array.
 * @param size The sizew of the array.
 */
void rquicksort(void* array, int (*isGreater)(void*, void*), size_t elem_size,
                int size);

#endif
