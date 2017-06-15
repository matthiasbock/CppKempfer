#
# The compiler: gcc for C program, g++ for C++
#
CC = gcc
CPP := g++
RM = rm

#
# Compiler flags
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
CPPFLAGS += -g -Wall

#
# Source files
#
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = $(wildcard *.h)
TARGET := ueb05

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
	CPP := colorgcc
    endif
    ifeq ($(UNAME_S),Darwin)
        CPPFLAGS += -D OSX
    endif
endif


#
# Build targets
#

all: $(TARGET)

$(TARGET): Makefile $(SOURCES) $(HEADERS) $(OBJECTS)
	rm -f $@
	$(CPP) $(CPPFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $^ -o $@

clean:
	$(RM) -f $(TARGET) *.o *.elf

