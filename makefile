.PHONY: clean

game: game.exe

game.exe: exec_game.cc		\
		game_session.cc \
		player.cc
	@if [ ! -d "./bin" ]; then mkdir ./bin; fi
	g++ -g -std=c++11 $^ -o game.exe

clean:
	@if [ -d "./bin" ]; then rm -rf .bin; fi
	@echo "Removed bin directory."
