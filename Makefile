CXX      := g++
CXXFLAGS := -O3 -std=c++20 -Iinclude -fopenmp
LDFLAGS  := -fopenmp

SRC_DIR  := src
OBJ_DIR  := obj
INC_DIR  := include

SRCS := $(SRC_DIR)/main.cpp \
        $(wildcard $(SRC_DIR)/kernels/*.cpp) \
        $(wildcard $(SRC_DIR)/utils/*.cpp)

OBJS := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

TARGET := alab

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Linking $(TARGET)..."
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	rm -rf $(OBJ_DIR) $(TARGET)

# List of phony targets
.PHONY: all clean
