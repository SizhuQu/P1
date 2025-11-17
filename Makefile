/*
 * Makefile / Assignment / Practicum I
 *
 * Sizhu Qu / CS5600 / Northeastern University
 * Fall 2025 / Nov 15, 2025
 *
 * Description:
 *  This Makefile is used to compile the Practicum I project, which includes
 *  multiple source files such as main.c, cache.c, store.c, and message.c.
 */

CC = gcc
CFLAGS = -Wall -Wextra -g

SRCS = main.c test.c cache.c store.c message.c config.c
OBJS = $(SRCS:.c=.o)
TARGET = practicum1

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean compiled files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean run test tar

# Run program normally
run: $(TARGET)
	./$(TARGET)

# Run tests
test: $(TARGET)
	./$(TARGET) --test

# Create TAR package with your name
TARFILE = Sizhu_Qu_Practicum1.tar

tar: clean
	tar -cvf $(TARFILE) *.c *.h Makefile README.md