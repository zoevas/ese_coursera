#include "data.h"
#include "memory.h"
#include <stdio.h>


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  int i = 0;
  
  bool isNegative = false;
  uint8_t length = 0;
  
   /* Handle 0 explicitely, otherwise empty string is printed for 0 */
   if (data == 0) {
      printf("%s\n","\nmyitoa before);\n");

      *(ptr + i++) = '0';
      printf("%s\n","\nmyitoa after);\n");
      *(ptr + i) = '\0';
      length = length +2;
      return length;
    }
    
    // In standard itoa(), negative numbers are handled only with 
    //base 10. Otherwise, numbers are considered unsigned.
    if (data < 0 && base == 10)
    {
      printf("%s\n","\nmyitoa negative);\n");
      isNegative = true;
      data = -data;
    }
    
    
     // Process individual digits
     while (data != 0) {
	  printf("%s\n","\nmyitoa individual);\n");
	  int rem = data % base;
	  *(ptr + i++) = (rem > 9) ? (rem - 10) +'A' : rem + '0';
	  data = data/base;
      }
      
      if (isNegative) {
	*(ptr + i++) = '-';
	length++;
      }
      
      *(ptr + i) = '\0';
      
      my_reverse(ptr, sizeof(i-1));
      
      
      printf("%s\n","\nmyitoa();\n");
      
      return length + i;
  
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  return 0;
}