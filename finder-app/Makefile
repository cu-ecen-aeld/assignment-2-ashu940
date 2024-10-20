# Variables
CROSS_COMPILE ?= 
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror
TARGET = writer
SRC = writer.c
OBJ = $(SRC:.c=.o)

# Default target - build the application
all: $(TARGET)

# Build the writer executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target - remove the binary and object files
clean:
	rm -f $(TARGET) $(OBJ)

# Phony targets to prevent conflicts with files
.PHONY: all clean

