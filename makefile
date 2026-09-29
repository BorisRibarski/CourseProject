CXX := g++
CPPFLAGS := -I. -Isrc -Isrc/app  -Isrc/cli  -Isrc/lib
CXXFLAGS := -std=c++23 -Wall -Wextra -pedantic
TARGET := target/program
BUILD_DIR = build
# SRCS := $(shell find src -maxdepth 3 -name "*.cc" 2>/dev/null)
# SRCS := \
# 		$(wildcard src/*.cc) \
# 		$(wildcard src/app/*.cc) \
# 		$(wildcard src/cli/*.cc) \
# 		$(wildcard src/lib/*.cc)
# OBJS := $(SRCS:%.cc=${BUILD_DIR}/%.o)
SRCS := $(shell find src -name "*.cc")
OBJS := $(patsubst src/%.cc,$(BUILD_DIR)/%.o, $(SRCS))

.PHONY: all clean run info

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: src/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -fr $(BUILD_DIR) $(TARGET)
