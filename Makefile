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

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST
# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds

#The cpu is an architecture specific flag and you only need to add that for ARM. No CPU is needed for the host machine. As the host machine knows the architecture already.


CFLAGS =  -Wall -Werror -g -O0 -std=c99

BASENAME= c1m2
TARGET = $(BASENAME).out

LDFLAGS =  -Wl,-Map=$(BASENAME).map 

ifeq ($(PLATFORM),HOST)
	CC = gcc
	CPPFLAGS = -DHOST
	# etc
else
	CC = arm-none-eabi-gcc
	CPPFLAGS = -DMSP432
	LDFLAGS = -T $(LINKER_FILE)  	\
		-march=armv7e-m		\
		-mfloat-abi=hard	\
		-mfpu=fpv4-sp-d16 	\
		-DMSP432		\
		-mcpu=cortex-m4		\
		--specs=nosys.specs	\
		-mthumb
	# etc
endif





# #run make print-variable
print-%: ; @echo $*=$($*)


OBJS = $(SOURCES:.c=.o)


%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $@
	
%.i : %.c
	$(CC) -E $< $(CPPFLAGS) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $@

%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $@
%.dep : %.c
	$(CC) -M $< $(CPPFLAGS) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $@


.PHONY: build
build: all
.PHONY: all
all: $(TARGET)
#includes are not needed at this stage
$(TARGET) : $(OBJS)
	$(CC)  $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
	
	
.PHONY: compile-all
compile-all:
	$(CC)  $(CPPFLAGS) $(INCLUDES) $(CFLAGS)  -c  -o $(SOURCES)

.PHONY: clean
clean:
	rm -rf *.map	\
		*.out	\
		*.o	\
		*.asm	\
		*.i	\
		*.dep