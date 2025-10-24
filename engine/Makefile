# COMPILER = g++
# FLAGS = -std=c++17 -lfmt
# LDFLAGS = -lfmt

# # Directories
# SRC_DIR = ./
# # Source files
# SOURCES = $(wildcard $(SRC_DIR)/*.cc)
# # Object files
# OBJECTS = $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SOURCES))
# # Header files
# HEADERS = $(wildcard ./*/*.hh)


# main: main.0
# 	$(COMPILER) $(FLAGS) main.cc -o main $(LDFLAGS)
# main.0: main.cc
# 	$(COMPILER) -c main.cc -o main.0
# clean:
# 	rm -f main main.0

# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Ilib -I.
# Linker flags
LDFLAGS = -lfmt

# Executable name
TARGET = engine

# Find all .cpp files in root and lib/
SOURCES = $(wildcard *.cc) $(wildcard fs/*.cc) $(wildcard timing/*.cc)
# Convert .cpp to .o
OBJECTS = $(SOURCES:.cc=.o)
# Dependency files
DEPS = $(OBJECTS:.o=.d)

# Default target
all: $(TARGET)

# Link objects to create executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compile .cpp to .o and generate .d files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -M -MF $(@:.o=.d) $<
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependency files
-include $(DEPS)

# Clean up
clean:
	rm -f *.o *.d fs/*.o fs/*.d $(TARGET)

# Phony targets
.PHONY: all clean