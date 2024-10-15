# Compiler
CXX = clang++
CXXFLAGS = -std=c++11 -Wall

# Executable name
EXEC = main

# Source file
SRC = main.cpp

# Rule to build the executable
all: $(EXEC)

# Compile the main file into an executable
$(EXEC): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SRC)

# Clean up the executable
clean:
	rm -f $(EXEC)
