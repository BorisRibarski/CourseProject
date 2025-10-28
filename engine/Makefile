CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -Werror -pedantic -I.
LDFLAGS = -lfmt

SRC := $(wildcard ./*.cc ./*/*.cc)
OBJ := $(SRC:.cc=.o)
DEP := $(OBJ:.o=.d)
-include $(DEP)
HDR := $(wildcard ./*.hh ./*/*.hh)
# HDR := $(wildcard ./*.hh ./*/*.hh)

.PHONY: all clean

all: engine
	@echo "Build complete"

engine: $(OBJ)
	@echo "Building executable: $@"
	$(CXX) $^ $(LDFLAGS) -o engine 
# $(OBJ):
# 	@echo "Compiling object: $@"
%.o : %.cc
	@echo "object: $@ else: $<"
	$(CXX) -MMD -MP -c $< $(CXXFLAGS) -o $@
precompiled.hh.gch : precompiled.hh
	$(CXX) -c precompiled.hh $(CXXFLAGS)

clean:
	@echo "Cleaning up..."
	find . -name "*.o" -delete
	find . -name "*.d" -delete
	find . -name "*.gch" -delete
	@echo "Cleaned up"