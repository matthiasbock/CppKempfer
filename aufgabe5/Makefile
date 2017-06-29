#
# The compiler: gcc for C program, g++ for C++
#
CC := gcc
CPP := g++
LD := g++
GDB = gdb
RM = rm

#
# Paths, where compiler and linker can find all the stuff
#
LDFLAGS += -L/lib/x86_64-linux-gnu
#LDFLAGS += -L/usr/lib/x86_64-linux-gnu
#LDFLAGS += -L/usr/lib/gcc/x86_64-linux-gnu/6

INCLUDE += -I/usr/include
INCLUDE += -I/usr/local/include
INCLUDE += -I/usr/include/libxml2

#
# Compiler flags
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
CFLAGS += -g -Wall
CPPFLAGS += -g -Wall -std=c++11
LDFLAGS += -lstdc++ -lxml2

#
# Source files
#
C_SRC = $(wildcard *.c)
CPP_SRC = $(wildcard *.cpp)
OBJS = $(CPP_SRC:.cpp=.o)
HEADERS = $(wildcard *.h)
TARGET := ueb05

#
# libxml2
#
LIBXML2_SYSLIB = /usr/lib/x86_64-linux-gnu/libxml2.so
LIBXML2_PATH = ../libxml2
LIBXML2_AC_CONFIG = $(LIBXML2_PATH)/libxml2-config.cmake
LIBXML2_LIB = $(LIBXML2_PATH)/.libs/libxml2.a
LIBXML2_SRC = $(filter $(wildcard $(LIBXML2_PATH)/*.c), xmllint.c)
LIBXML2_OBJS = $(LIBXML2_SRC:.c=.o)

INCLUDE += -I$(LIBXML2_PATH)/include

#
# Detect operating system
#
ifeq ($(OS),Windows_NT)
    CPPFLAGS += -D WIN32
    TARGET := $(TARGET).exe
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        CPPFLAGS += -D LINUX

        # Matthias prefers colorgcc
#        CC := colorgcc
#        CPP := colorgcc
    endif
    ifeq ($(UNAME_S),Darwin)
        CPPFLAGS += -D OSX
    endif
endif


#
# Build targets
#

all: $(TARGET)

run: $(TARGET)
	@./$(TARGET)

debug: $(TARGET)
	$(GDB) $^ -ex="r"

$(LIBXML2_PATH)/autogen.sh:
	$(shell if [ ! -e "$@" ]; then git submodule init; git submodule update; fi)

$(LIBXML2_AC_CONFIG): $(LIBXML2_PATH)/autogen.sh
	cd $(LIBXML2_PATH) && ./autogen.sh

$(LIBXML2_LIB): $(LIBXML2_AC_CONFIG)
	cd $(LIBXML2_PATH) && make

$(TARGET): Makefile $(CPP_SRC) $(HEADERS) $(OBJS) $(LIBXML2_LIB)
	@$(RM) -f $@
	$(LD) $(LDFLAGS) $(OBJS) $(LIBXML2_OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

%.o: %.cpp
	$(CPP) $(CPPFLAGS) $(INCLUDE) -c $^ -o $@

clean:
	$(RM) -f $(TARGET) *.o *.elf

