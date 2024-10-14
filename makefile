# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Source files
ASSET_SRC = Asset.cpp
STOCK_SRC = Stock.cpp
BOND_SRC = Bond.cpp
CRYPTO_SRC = Cryptocurrency.cpp
GOVBOND_SRC = GovernmentBond.cpp
USER_SRC = User.cpp
MAIN_SRC = main.cpp  # Include the file where your main function is

# Object files
ASSET_OBJ = Asset.o
STOCK_OBJ = Stock.o
BOND_OBJ = Bond.o
CRYPTO_OBJ = Cryptocurrency.o
GOVBOND_OBJ = GovernmentBond.o
USER_OBJ = User.o
MAIN_OBJ = main.o  # Object for main

# Executable name
EXECUTABLE = portfolio_manager

# Default target: compile the program
all: $(EXECUTABLE)

# Link the object files to create the final executable
$(EXECUTABLE): $(MAIN_OBJ) $(ASSET_OBJ) $(STOCK_OBJ) $(BOND_OBJ) $(CRYPTO_OBJ) $(GOVBOND_OBJ) $(USER_OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $^

# Compile each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up the generated files
clean:
	rm -f $(EXECUTABLE) *.o
