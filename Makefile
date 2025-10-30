# WinRDP Makefile - Educational WinAPI Project
# Compiles with MinGW GCC (or MSVC with cl.exe)

# Compiler settings
CC = gcc
WINDRES = windres
CFLAGS = -Wall -Wextra -std=c11 -D_WIN32_WINNT=0x0601 -DUNICODE -D_UNICODE
LDFLAGS = -mwindows -municode
LIBS = -lcomctl32 -lole32 -lshell32 -ladvapi32 -lcredui -lwldap32 -lcomdlg32

# Directories
SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

# Target executable
TARGET = $(BUILD_DIR)/WinRDP.exe

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

# Resource file (for icon, version info, etc.)
RES_FILE = $(SRC_DIR)/resources.rc
RES_OBJ = $(OBJ_DIR)/resources.o

# Default target
all: directories $(TARGET)

# Create build directories
directories:
	@if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
	@if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"

# Link executable
$(TARGET): $(OBJECTS) $(RES_OBJ)
	@echo Linking $@...
	@$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)
	@echo Build complete: $@

# Compile C source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compiling $<...
	@$(CC) $(CFLAGS) -c $< -o $@

# Compile resource file
$(RES_OBJ): $(RES_FILE)
	@echo Compiling resources...
	@$(WINDRES) $< -o $@

# Clean build artifacts
clean:
	@if exist "$(BUILD_DIR)" rmdir /s /q "$(BUILD_DIR)"
	@echo Cleaned build directory

# Run the application
run: all
	@$(TARGET)

# Debug build
debug: CFLAGS += -g -O0 -DDEBUG
debug: clean all

# Release build (optimized)
release: CFLAGS += -O3 -s
release: clean all

.PHONY: all clean run debug release directories

