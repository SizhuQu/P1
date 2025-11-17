# Makefile / Assignment / Practicum I
# Sizhu Qu / CS5600 / Northeastern University
# Fall 2025 / Nov 15, 2025

# Description:
# This Makefile is used to compile the Practicum I project, which includes
# multiple source files such as main.c, cache.c, store.c, and message.c.

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -g

# Source & object files
SRCS = main.c test.c cache.c store.c message.c config.c
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = practicum1

# Tarball name
TARFILE = Qu-SizhuQu-CS5600-Practicum1.tar

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET) *.txt

# Run program
run: $(TARGET)
	./$(TARGET)

# Run tests only
test: $(TARGET)
	./$(TARGET) --test

# Create tarball (your name included)
tar: clean
	tar -cvf $(TARFILE) *.c *.h Makefile README.md

.PHONY: all clean run test tar