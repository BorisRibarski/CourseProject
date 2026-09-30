CXX := g++
CPPFLAGS := -I. -Isrc -Isrc/app -Isrc/cli -Isrc/fio -Isrc/lib
CXXFLAGS := -std=c++23 -Wall -Wextra -pedantic
DATA_DIR := data
TARGET_DIR := target
TARGET := $(TARGET_DIR)/program
BUILD_DIR = build
SRCS := $(shell find src -name "*.cc")
OBJS := $(patsubst src/%.cc,$(BUILD_DIR)/%.o, $(SRCS))

.PHONY: all clean run info

all: $(TARGET)
$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: src/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -fr $(BUILD_DIR) $(TARGET_DIR) $(DATA_DIR)
