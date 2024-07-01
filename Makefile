# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++17 -g -fsanitize=address,undefined -Wall -Wextra -pedantic

# Target executable
TARGET = demo

# Source files
SRCS = Demo.cpp

# Header files (not technically needed for compilation, but useful for dependency tracking)
HEADERS = node.hpp tree.hpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile the source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
