CXX := g++
CPPFLAGS := -I.
CXXFLAGS := -std=c++23 -Wall -Wextra -pedantic
TARGET := program
SRCS := $(wildcard *.cc)
OBJS := $(SRCS:.cc=.o)

.PHONY: all clean run

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
