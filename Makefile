CXX := g++
CXXFLAGS := -std=c++23 -Wall -Wextra -Werror -O2 -Wno-unused-parameter
LDFLAGS := -s -lpthread
TARGET := main

SRCS := $(wildcard *.cc)
OBJS := $(SRCS:.cc=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(TARGET)

.PHONY: all clean
