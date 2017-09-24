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
 * @brief Functions used by stats.c are declared here
 *
 * Contains declarations of functions that can analyze an array of unsigned char data items and report
 * analytics on the maximum, minimum, mean, and median of the data set. 
 * In addition functions for reordering the data set from large to small and printing 
 * in a nice format will be provided. 
 *
 * @author Zoe Vasileiou
 * @date 24 September 2017
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


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
void print_statistics(unsigned char *, int);



/**
 * @brief It prints the content of the array
 *
 * Given an array of data and a length, prints the array to the screen
 *
 * @param Character array on which analytics to be performed
 * @param Size of the array
 *
 * @return none
 */
void print_array(unsigned char *, int);



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
int find_median(unsigned char *, int);


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
int find_mean(unsigned char *, int);





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
int find_maximum(unsigned char *, int);



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
int find_minimum(unsigned char *, int);


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
void sort_array(unsigned char *, int);



#endif /* __STATS_H__ */
