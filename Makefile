CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -Werror -O2 -Wno-unused-parameter
LDFLAGS := -s -lpthread
TARGET := build/main

SRCS := $(wildcard src/*.cc)
OBJS := $(patsubst src/%.cc, build/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

build/%.o: src/%.cc
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build

.PHONY: all clean
