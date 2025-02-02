#include "sort.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rquicksort(void* array, int (*isGreater)(void*, void*), size_t elem_size,
          int size)
{
  if (size <= 1) return;
  if (size == 2)
  {
    if (!isGreater(array, array + elem_size)) return;
    void* temp = malloc(elem_size);
    memcpy(temp, array, elem_size);
    memcpy(array, array + elem_size, elem_size);
    memcpy(array + elem_size, temp, elem_size);
    free(temp);
    return;
  }
  int pivotIndex = rand() % size;
  void* tempPivot = malloc(elem_size);
  memcpy(tempPivot, array + pivotIndex * elem_size, elem_size);
  void* subArray1 = malloc(size * elem_size);
  void* subArray2 = malloc(size * elem_size);
  if (!subArray1 || !subArray2 || !tempPivot)
    {
      fprintf(stderr, "Failed memory allocation");
      exit(1);
    }
  int subArray1Size = 0;
  int subArray2Size = 0;
  // Splitting array
  for (int i = 0; i < size; i++)
  {
    if (i == pivotIndex) continue;
    if (isGreater(array + i * elem_size, array + pivotIndex * elem_size))
      memcpy(subArray2 + (subArray2Size++) * elem_size, array + i * elem_size,
             elem_size);
    else
      memcpy(subArray1 + (subArray1Size++) * elem_size, array + i * elem_size,
             elem_size);
  }
  // Recursive sort
  rquicksort(subArray1, isGreater, elem_size, subArray1Size);
  rquicksort(subArray2, isGreater, elem_size, subArray2Size);
  int j = 0;
  for (int i = 0; i < size; i++)
    if (i < subArray1Size)
    {
      memcpy(array + i * elem_size, subArray1 + j * elem_size, elem_size);
      j++;
    }
    else if (i == subArray1Size)
    {
      memcpy(array + i * elem_size, tempPivot, elem_size);
      j = 0;
    }
    else
    {
      memcpy(array + i * elem_size, subArray2 + j * elem_size, elem_size);
      j++;
    }
  free(tempPivot);
  free(subArray1);
  free(subArray2);
  return;
}
