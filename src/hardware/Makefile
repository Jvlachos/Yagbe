

# Compiler and flags
CC = gcc
CFLAGS = -Wall -I. -Ihardware -Immu -Iutil -Icpu   # Include paths for headers

# Directories
SRCDIR = hardware mmu util cpu
OBJDIR = obj
BINDIR = bin

# Core source file (contains main function)
CORE_SRC = core.c

# Source and object files (including core.c)
SRCS = $(CORE_SRC) $(foreach dir,$(SRCDIR),$(wildcard $(dir)/*.c))
OBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))

# Target executable
TARGET = $(BINDIR)/core

# Rule to convert source file path to object file path
$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)/$(dir $<)
	$(CC) $(CFLAGS) -c $< -o $@

# Link the target executable
$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@

# Phony targets
.PHONY: all clean

# Default target: compile the project
all: $(TARGET)

# Clean up object and executable files
clean:
	rm -rf $(OBJDIR) $(TARGET)
