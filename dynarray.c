/*
 * Name: Artem Kolpakov
 * Email: kolpakoa@oregonstate.edu
 */

#include <stdlib.h>

#include "dynarray.h"

struct dynarray {
  void** data;
  int size;
  int capacity;
};


struct dynarray* dynarray_create() {
  struct dynarray* arr = malloc(sizeof(struct dynarray));
  arr->data = malloc(2 * sizeof(void *));

  arr->size = 0; 
  arr->capacity = 2;

  return arr;
}

void dynarray_free(struct dynarray* da) {
  free(da->data);
  free(da);
  return;
}

int dynarray_size(struct dynarray* da) {

  return da->size;

}

void dynarray_insert(struct dynarray* da, void* val) {

  if (da->size == da->capacity){ /* meaning that it's full */
    void** temp = malloc(2* da->capacity * sizeof(void *));

      for (int i=0; i < da->size; i++){
        temp[i] = da->data[i];
      }

      free(da->data);

      da->data = temp;

      da->capacity = da->capacity*2;
  }

    da->data[da->size] = val;
  
    da->size++;

  return;
}

void dynarray_remove(struct dynarray* da, int idx) {
  if (idx<0 || idx > da->size){
    return;
  }
  da->data[idx] = NULL;

  for (int i=idx; i<da->size-1; i++){
    da->data[i] = da->data[i+1];
  }
  da->size--;
  return;
}

void* dynarray_get(struct dynarray* da, int idx) {
  if (idx<0 || idx > da->size){ 
    return NULL;
  }
  else{
  return da->data[idx];
  }
}

void dynarray_set(struct dynarray* da, int idx, void* val) {
  if (idx<0 || idx > da->size){
    return;
  }
  else{
    da->data[idx] = val;
  }
  return;
}
