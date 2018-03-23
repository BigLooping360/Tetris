FC = g++

#OPT = -O
#OPT = -p
OPT = -lncurses

# executables
# main
main : Bloc.cpp Board.cpp Piece.cpp Jeu.cpp main.cpp
	$(FC) Bloc.cpp Board.cpp Piece.cpp Jeu.cpp main.cpp $(OPT) -o Tetris


#Classes
Bloc: Bloc.cpp
	$(FC) Bloc.cpp
Board: Board.cpp
	$(FC) Board.cpp
Jeu: Bloc.cpp
	$(FC) Bloc.cpp $(OPT)
Piece: Piece.cpp
	$(FC) Piece.cpp


	clean:
	rm *.hpp.gch Tetris
