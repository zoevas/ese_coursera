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
 * @file stats.c 
 * @brief Statistics on an array
 *
 * Functions provided for callculating mean, median, minimum and maximum of an array.
 *
 * @author Vasileiou Zoe
 * @date 24 September 2017
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/*int main() {

    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

    print_statistics(test, SIZE);
    return 0;
}*/

/**
 * @brief It prints statistics (minimum, maximum, mean , median) of an array in a nice format
 *
 * It invokes other functions(find_median, find_mean, find_maximum, find_minimum) for calculating the statistics and then prints them in a nice format
 * on the command line
 *
 * @param Character array on which analytics to be performed
 * @param Size of the array
 *
 * @return none
 */
void print_statistics(unsigned char arr[], int size) {
  
  sort_array(arr, size);
  
#ifdef VERBOSE
  print_array(arr, size);
#endif
  printf("\n\n------------------------------------------------------------");
  printf("\nStatistics");
  printf("\n------------------------------------------------------------");
  printf("\nThe median of the array is %d\n", find_median(arr,size));
  printf("The mean of the array is %d\n", find_mean(arr,size));
  printf("The maximum of the array is %d\n", find_maximum(arr,size));
  printf("The minimum of the array is %d\n", find_minimum(arr,size));
}

/**
 * @brief This function will find the median of the input array.
 *
 * Given an array of data and a length, returns the median value
 *
 * @param Character array on which analytics to be performed
 * @param Size of the array
 *
 * @return none
 */
void print_array(unsigned char arr[] , int size) {
   
    unsigned int i;
   // int count = 0;
    
    
    printf("%s", "Elements of array:");
    
    for (i=0; i < size; i++) {
      if (i % 8 == 0) {
         printf("\n%d ", arr[i]);
      } else {
         printf("%d ", arr[i]);
      }
    }
  
}



/**
 * @brief This function will find the median of the input array.
 *
 * It will find the median of the input array. If the size of 
 * array is odd, the median will the size of array divided by two. If the
 * size of array is even, the median will be the sum of the two middle elements
 * divided by 2
 *
 * @param The Character Array whose median is to be found
 * @param The Size of the array
 *
 * @return The median of the array
 */
int find_median(unsigned char arr[], int size) {
  
    if(size%2==0) {
        // if there is an even number of elements, return mean of the two elements in the middle
        return((arr[size/2] + arr[size/2 - 1]) / 2);
    } else {
        // else return the element in the middle
        return arr[size/2];
    }
 
}


/**
 * @brief Find the mean of the input array
 *
 * It will calculate the average of all the elements of
 * the array. The sum of all the elements is calculated and then mean by
 * dividing the sum by the size of the array.
 *
 * @param The Character Array who mean is to be determined
 * @param The Size of the array
 *
 * @return The mean of the array
 */
int find_mean(unsigned char arr[], int size) {
  
  int sum  = 0;
  unsigned int i = 0;
  
  for (i =0; i < size; i++) { 
    sum += arr[i];
  }
  
  return sum/size;
}


/**
 * @brief Finds the element with the maximum value
 *
 * It will search the given array and will find the element
 * with the maximum value
 *
 * @param The Character Array from which maximum value is to be found
 * @param The Size of the array
 *
 * @return Element with the maximum value
 */
int find_maximum(unsigned char arr[], int size) {
  unsigned int maximum = 0;
  unsigned int i = 0;
  
  for (i = 0; i < size; i++) {
      if (arr[i] > maximum) {
         maximum = arr[i];
      }
  }
  return maximum;
  
}



/**
 * @brief Finds the element with the minimum value
 *
 * It will search the given array and will find the element
 * with the minimum value
 *
 * @param The Character Array from which minimum value is to be found
 * @param The Size of the array
 *
 * @return Element with the minimum value
 */
int find_minimum(unsigned char arr[], int size) {
    unsigned int i = 0;
    unsigned int minimum = arr[i];

    for(i = 0; i < size; i++){
        if(arr[i] < minimum){
            minimum = arr[i];
        }
    }

    return minimum;
}


/**
 * @brief Sort the elements in Descending order
 *
 * It will sort the elements of the array with the first 
 * element having the largest value and the last element having the
 * least value
 *
 * @param The Character Array which is to be sorted
 * @param The Size of the array
 *
 * @return None
 */
void sort_array(unsigned char arr[], int size) {
  unsigned int i = 0;
  unsigned int j = 0;
  
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size -1; j++) {
      if (arr[j] < arr[j+1]) {
	unsigned int  temp = arr[j+1];
	arr[j+1] = arr[j];
	arr[j] = temp;
      }
    }
  }
  
  return;
}


