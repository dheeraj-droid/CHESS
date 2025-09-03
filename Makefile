
.PHONY: build run
SRCS = main.cpp piece.cpp Queen.cpp Bishop.cpp Rook.cpp Knight.cpp Pawn.cpp King.cpp Board.cpp Game.cpp
OUTPUT = chess

build:
	g++ $(SRCS) -o $(OUTPUT)

run: build
	./$(OUTPUT)

clean:
	rm -f $(OUTPUT)