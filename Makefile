
.PHONY: build run
SRCS = main.cpp piece.cpp Queen.cpp Bishop.cpp Rook.cpp Knight.cpp Board.cpp Game.cpp
OUTPUT = chess

build:
	g++ $(SRCS) -o $(OUTPUT)

run: build
	./$(OUTPUT)

cleam:
	rm -f $(OUTPUT)