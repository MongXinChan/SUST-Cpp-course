# Compiler and Archiver
CC = gcc
AR = ar

# Archiver flags:
# r - replace existing files or add new ones
# c - create the archive if it doesn't exist
# s - create an object-file index (symbol table)
ARFLAGS = rcs

# Target library name
TARGET = libmyfun.a

# Source files: find all .c files in the current directory (e.g., lib_a/)
SRCS = $(wildcard ./*.c)

# Object files: derive .o filenames from .c filenames
# e.g., if SRCS is "max.c min.c", OBJS will be "max.o min.o"
OBJS = $(patsubst %.c,%.o,$(SRCS))

# Directory containing the header file (fun.h) - parent directory
HEADER_DIR = ../

# Full path to the header file, used for dependency tracking
# This assumes fun.h is directly in the parent directory.
HEADER_FILE = $(HEADER_DIR)fun.h

# Compiler flags:
# -Wall: Enable all common compiler warnings (good practice)
# -I$(HEADER_DIR): Add the parent directory to the list of directories
#                  searched for header files (so #include "fun.h" works)
CFLAGS = -Wall -I$(HEADER_DIR)

# Phony targets are targets that don't represent actual files.
# 'all' is a common default target.
# 'clean' is for removing built files.
.PHONY: all clean

# Default target: executed when 'make' is run without arguments.
# This rule says 'all' depends on the TARGET library.
all: $(TARGET)

# Rule to create the static library from object files
# $@ : The target file name (e.g., libmyfun.a)
# $^ : The names of all prerequisites (e.g., max.o min.o)
$(TARGET): $(OBJS)
	@echo "Archiving objects into $@"
	$(AR) $(ARFLAGS) $@ $^

# Pattern rule to compile .c files into .o files
# This rule applies to any target ending in .o for which a .c file exists.
# $< : The name of the first prerequisite (the .c file, e.g., max.c)
# $@ : The name of the target file (the .o file, e.g., max.o)
# $(HEADER_FILE) is listed as a prerequisite. If fun.h changes,
# the .c files that depend on it will be recompiled.
%.o: %.c $(HEADER_FILE)
	@echo "Compiling $< to $@"
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean up build artifacts (object files and the library)
clean:
	@echo "Cleaning up build files..."
	rm -f $(OBJS) $(TARGET)


.PHONY : clean static_lib