# C++ compiler
CXX = g++

# Compiler flags: -g for debug, -pthread for GTest
CXXFLAGS = -std=c++17 -Wall -Wextra -g -pthread

# Preprocessor flags: -I for include directories
# ADDED -Ithird_party/googletest/googlemock to help gmock-all.cc find its own source files.
CPPFLAGS = -Isrc \
           -Ithird_party/googletest/googletest \
           -Ithird_party/googletest/googlemock \
           -Ithird_party/googletest/googletest/include \
           -Ithird_party/googletest/googlemock/include

# --- Main Application ---
# Filter out main.cpp for test builds
APP_SRCS = $(wildcard src/*.cpp)
APP_OBJS = $(APP_SRCS:.cpp=.o)
TARGET = chess

# --- Tests ---
# Object files for the code being tested (all app code except main.o)
TEST_DEPS_OBJS = $(filter-out src/main.o, $(APP_OBJS))

# The test source files themselves
TEST_SRCS = tests/Pawn_test.cpp tests/Piece_test.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# ADDED: GTest/GMock source files to be compiled directly.
# This avoids needing to pre-build the GTest libraries.
# gtest_main.cc provides a main() function for the test runner.
GTEST_SRCS = third_party/googletest/googletest/src/gtest-all.cc \
             third_party/googletest/googlemock/src/gmock-all.cc \
             third_party/googletest/googletest/src/gtest_main.cc
GTEST_OBJS = $(GTEST_SRCS:.cc=.o)

# The final test runner executable
TEST_TARGET = run_tests

# Define all targets that are not files
.PHONY: all test clean run

all: $(TARGET)

# Link the main application
$(TARGET): $(APP_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Link the test runner
$(TEST_TARGET): $(TEST_OBJS) $(TEST_DEPS_OBJS) $(GTEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Generic rule to compile any .cpp file into a .o file
%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# ADDED: Generic rule to compile GTest's .cc files
%.o: %.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Updated clean rule to remove all generated object files
clean:
	rm -f $(TARGET) $(TEST_TARGET) $(APP_OBJS) $(TEST_OBJS) $(GTEST_OBJS) 

