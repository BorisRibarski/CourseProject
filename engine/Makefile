CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -Werror -pedantic
LDFLAGS = -lfmt

SRC := $(wildcard ./*.cc ./*/*.cc)
OBJ := $(SRC:.cc=.o)

all: $(OBJ)
	$(CXX) $^ $(LDFLAGS) -o engine
$.o : $.cc
	$(CXX) -c $< $(CXXFLAGS)

clean:
	find . -name "*.o" -delete