/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}


uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
    unsigned int i = 0;
   for (i=0; i<length; i++)
    if ((src+i)==dst || (dst+i)==src) return NULL;
  
  
    for (int i = 0; i < length; i++) {
      *(dst+i) = *(src+i);
    }
  
    return dst;
}

//https://stackoverflow.com/questions/3572309/memmove-implementation-in-c/3572519#3572519 very useful
//this is the only case starting at the end of src
//2) <-----s----->                start at end of s
//            <-----d----->
//4)          <-----s----->       start at beginning of s
//   <-----d----->
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){

  
  printf ("\nsrc address = %p, dst address  = %p\n", src, dst);
  
  if ((src + length) <= dst || src > dst || src > (dst + length)) {
      /* No overlap, use memcpy logic (copy forward) */
      while (length--)
      *dst++ = *src++;
      printf ("no overlap\n");
  } else {
    /* Overlap detected! Copy backward to fix */
    src = src + length - 1;
    
    dst = dst + length - 1;
    printf ("\nsrc address = %p, dst address  = %p, length = %d\n", src, dst,(int)length);
    while (length--)
      *dst-- = *src--;
    
     printf ("overlap\n");
  }
  return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
  
  for (int i = 0; i < length; i++) {
    *(src+i) = value;
  }
  return src;
}

uint8_t * my_memzero (uint8_t * src, size_t length) {
  
  for (int i = 0; i < length; i++) {
    *(src+i) = 0;
  }
  return src;
}


uint8_t * my_reverse(uint8_t * src, size_t length) {
  
  uint8_t  tmp;
  
  int j  = length - 1;
  int i  = 0;
  
  while (i < j) {
    tmp = src[i];
    src[i] = src[j];
    src[j] = tmp;
    i++;
    j--;
  }
  
  return src;
}


int32_t * reserve_words(size_t length) {
  
    int32_t * src = (int32_t *) malloc(length * sizeof(int32_t));
    
    printf("%s\n", "reserve_words");
    
    return src;
    
}

void free_words(uint32_t * src) {
  
  free(src);
}