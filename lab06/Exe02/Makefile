# Compiler
CXX = g++

# Compiler flags
# -Wall: Enable all common warnings
# -g: Generate debugging information
# -std=c++11: (Optional) Specify C++ standard if needed
CXXFLAGS = -Wall -g -std=c++11

# Directories
INC_DIR = include
LIB_SRC_DIR = lib_src
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = bin

# Include flags for preprocessor
CPPFLAGS = -I$(INC_DIR)

# Library information
STATIC_LIB_NAME = libswap.a
STATIC_LIB = $(LIB_DIR)/$(STATIC_LIB_NAME)

# Executable name
EXEC_NAME = test_programer
EXEC = $(BIN_DIR)/$(EXEC_NAME)

# Source files
LIB_SOURCES = $(wildcard $(LIB_SRC_DIR)/*.cpp)
MAIN_SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
LIB_OBJECTS = $(patsubst $(LIB_SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(LIB_SOURCES))
MAIN_OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(MAIN_SOURCES))

# Linker flags
LDFLAGS = -L$(LIB_DIR)
# Libraries to link against (-lswap will link libswap.a)
LDLIBS = -lswap

# Default target: build all
all: $(EXEC)

# Rule to create the executable
$(EXEC): $(MAIN_OBJECTS) $(STATIC_LIB)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $@
	@echo "Executable '$(EXEC)' created successfully."

# Rule to create the static library
$(STATIC_LIB): $(LIB_OBJECTS)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^
	@echo "Static library '$(STATIC_LIB)' created successfully."

# Rule to compile library source files into object files
$(OBJ_DIR)/%.o: $(LIB_SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

# Rule to compile main program source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

# Clean up build files
clean:
	@echo "Cleaning up..."
	rm -f $(LIB_OBJECTS) $(MAIN_OBJECTS)
	rm -f $(STATIC_LIB)
	rm -f $(EXEC)
	@# Optionally remove directories if they are empty or if you want to be thorough
	@# Use with caution:
	rm -rf $(OBJ_DIR) $(LIB_DIR) $(BIN_DIR)
	@echo "Cleanup complete."

# Phony targets are targets that don't represent actual files
.PHONY: all clean