# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Source files
SRCS = main.cpp card.cpp pokemon_card.cpp energy_card.cpp trainer_card.cpp player.cpp

# Header files
HDRS = headers/card.h headers/pokemon_card.h headers/energy_card.h headers/trainer_card.h headers/player.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = main

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Compile source files into object files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC)

# Run the executable
run: $(EXEC)
	./$(EXEC)

.PHONY: all clean run