CXX = g++
# CXXFLAGS are for compilation. Add -g for debugging symbols.
CXXFLAGS = -std=c++17 -Wall -Wextra -g
# CPPFLAGS are for the preprocessor, mainly for include directories (-I).
CPPFLAGS = -Isrc -Ithird_party/googletest/include
# LDFLAGS are for the linker, for library paths (-L).
LDFLAGS = -Lthird_party/googletest/build/lib
# LDLIBS are the libraries to link against (-l).
LDLIBS = -lgtest -lgtest_main -pthread

# --- Main Application ---
SRCS = main.cpp piece.cpp Queen.cpp Bishop.cpp Rook.cpp Knight.cpp Pawn.cpp King.cpp ExtractMove.cpp Board.cpp Game.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = chess

# --- Tests ---
TEST_SRCS = ../tests/Pawn_test.cpp 
TEST_OBJS = $(TEST_SRCS:.cpp=.o)
# This now includes all object files needed by Pawn_test.cpp
TEST_DEPS_OBJS = Board.o Piece.o Pawn.o Rook.o
TEST_TARGET = run_tests


.PHONY: all build run test clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJS) $(TEST_DEPS_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# This generic rule now also handles compiling files in other directories like 'tests/'
%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

build: $(TARGET)

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJS) $(TEST_OBJS)