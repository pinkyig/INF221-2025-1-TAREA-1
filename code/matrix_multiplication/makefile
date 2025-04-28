# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++20 -Wall -O2

# Directories
SRC_DIR = .
ALGO_DIR = algorithms
SCRIPT_DIR = scripts
OBJ_DIR = obj
BIN_DIR = .

# Source files
SRCS = $(SRC_DIR)/matrix_multiplication.cpp \
	$(ALGO_DIR)/naive.cpp \
	$(ALGO_DIR)/strassen.cpp

# Object files
OBJS = $(OBJ_DIR)/matrix_multiplication.o \
	$(OBJ_DIR)/naive.o \
	$(OBJ_DIR)/strassen.o

# Output binary
TARGET = $(BIN_DIR)/matrix_multiplication
PLOT_SCRIPT = $(SCRIPT_DIR)/plot_generator.py

# Default target - now builds, runs, and plots
all: $(TARGET) run plot

# Rule to run the main program
run: $(TARGET)
	./$(TARGET)

# Rule to execute the plot generation script
plot: run
	cd $(SCRIPT_DIR) && python3 plot_generator.py

# Final linking
$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation of matrix_multiplication.cpp
$(OBJ_DIR)/matrix_multiplication.o: $(SRC_DIR)/matrix_multiplication.cpp \
					 $(ALGO_DIR)/naive.h \
					 $(ALGO_DIR)/strassen.h
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilation of naive.cpp
$(OBJ_DIR)/naive.o: $(ALGO_DIR)/naive.cpp $(ALGO_DIR)/naive.h
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilation of strassen.cpp
$(OBJ_DIR)/strassen.o: $(ALGO_DIR)/strassen.cpp $(ALGO_DIR)/strassen.h
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean generated files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Build without running
build: $(TARGET)

# Run without recompiling
run-only:
	./$(TARGET)
	cd $(SCRIPT_DIR) && python3 plot_generator.py

# Phony targets
.PHONY: all clean build run run-only plot