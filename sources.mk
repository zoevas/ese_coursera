#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

# Add your Source files to this variable

ifeq ($(PLATFORM),HOST)
SOURCES = main.c \
	memory.c
else	
SOURCES = main.c \
	memory.c \
	interrupts_msp432p401r_gcc.c \
	startup_msp432p401r_gcc.c \
	system_msp432p401r.c
endif


ifeq ($(PLATFORM),HOST)
# Add your include paths to this variable
INCLUDES = -I/home/zoe/VasileiouZoe_Coursera/m2/include/common
else
INCLUDES = -I/home/zoe/VasileiouZoe_Coursera/m2/include/common	\
	-I/home/zoe/VasileiouZoe_Coursera/m2/include/msp432	\
	-I/home/zoe/VasileiouZoe_Coursera/m2/include/CMSIS
endif

