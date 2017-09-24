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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

    print_statistics(test, SIZE);
    return;
}

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
  
  print_array(arr, size);
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
    int count = 0;
    
    
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
 * size of array is even, the median will be size of array divided by two
 * minus one.
 *
 * @param The Character Array whose median is to be found
 * @param The Size of the array
 *
 * @return The median of the array
 */
int find_median(unsigned char arr[], int size) {
  
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
  
}


