CXX      := g++
CXXFLAGS := -O3 -std=c++20 -Iinclude -fopenmp

LDFLAGS  := -fopenmp

SRC_DIR  := src
OBJ_DIR  := obj
BIN_DIR  := bin
TEST_DIR := tests

MAIN_SRC := $(SRC_DIR)/main.cpp
UTIL_SRC := $(wildcard $(SRC_DIR)/utils/*.cpp)
KERN_SRC := $(wildcard $(SRC_DIR)/kernels/*.cpp)
SRCS     := $(MAIN_SRC) $(UTIL_SRC) $(KERN_SRC)

OBJS      := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))
TEST_DEPS := $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(UTIL_SRC) $(KERN_SRC))

TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/$(TEST_DIR)/%.o, $(TEST_SRCS))

TARGET   := alab
TEST_EXE := bin/test_runner

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Linking $(TARGET)..."
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(TEST_EXE): $(TEST_OBJS) $(TEST_DEPS)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS) -lCatch2Main -lCatch2

test: $(TEST_EXE)
	./$(TEST_EXE)

$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling Test $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	rm -rf $(OBJ_DIR) $(TARGET) $(BIN_DIR)

.PHONY: all clean test
