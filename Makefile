CXX      := g++
CXXFLAGS := -O3 -std=c++20 -Isrc/include -fopenmp
LDFLAGS  := -fopenmp

SRC_DIR := src
OBJ_DIR := obj

SRCS    := $(SRC_DIR)/main.cpp \
           $(SRC_DIR)/kernels/ddot_serial.cpp 

OBJS    := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))
TARGET  := alab

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean
