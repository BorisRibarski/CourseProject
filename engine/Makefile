CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -Werror -pedantic -H
LDFLAGS = -lfmt

SRC := $(wildcard ./*.cc ./*/*.cc)
OBJ := $(SRC:.cc=.o)
HDR := precompiled.hh
PDR := precompiled.hh.gch
# HDR := $(wildcard ./*.hh ./*/*.hh)

all: $(OBJ)
	$(CXX) $^ $(LDFLAGS) -o engine
$.o : $.cc
	$(CXX) -c $< $(CXXFLAGS)
precompiled.hh.gch : precompiled.hh
	$(CXX) -c precompiled.hh $(CXXFLAGS)

clean:
	find . -name "*.o" -delete
	find . -name "*.gch" -delete