#include "data.h"
#include "memory.h"
#include <stdio.h>



uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  int i = 0;
  
  bool isNegative = false;
  uint8_t length = 0;
  
   /* Handle 0 explicitely, otherwise empty string is printed for 0 */
   if (data == 0) {
      printf("%s\n","\nmyitoa before;\n");

      *(ptr + i++) = '0';
      printf("%s\n","\nmyitoa after;\n");
      *(ptr + i) = '\0';
      length = length +2;
      return length;
    }
    
    // In standard itoa(), negative numbers are handled only with 
    //base 10. Otherwise, numbers are considered unsigned.
    if (data < 0 && base == 10)
    {
      printf("%s\n","\nmyitoa negative;\n");
      isNegative = true;
      data = -data;
    }
    
    
     // Process individual digits
     // ascii table https://ascii.cl/
     while (data != 0) {
	  
	  int rem = data % base;
	  ptr[i++] = (rem > 9) ? (rem - 10) +'A' : rem + '0';
	  data = data/base;
      }
      
      if (isNegative) {
	ptr[i++] = '-';
	length++;
      }
      
      *(ptr + i) = '\0';
      
      printf("\n%s = %s\n","\nmyitoa()=", ptr);
      
      my_reverse(ptr, i);
      
      
      printf("%s = %s\n","\nmyitoa AFTER REVERSE()=", ptr);
      
      return length + i;
  
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  
  int res = 0;
  int sign = 1, i = 0;  // Initialize sign as positive
  
  // If number is negative, then update sign
    if (*(ptr + 0) == '-')
    {
        sign = -1;  
        i++;  // Also update index of first digit
    }
  
  
   while (*(ptr+i) != '\0') {
     res = res * base +*(ptr+i) - '0';
 
     i++;
   }
  
  
  
  return sign * res;
}