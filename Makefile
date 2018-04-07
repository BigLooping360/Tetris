FC = g++

#OPT = -O
#OPT = -p
OPT = -lncurses

# executables
# main
main : Bloc.cpp Board.cpp Piece_I.cpp Piece.cpp Jeu.cpp main.cpp
	$(FC) Bloc.cpp Board.cpp Piece_I.cpp Piece.cpp Jeu.cpp main.cpp $(OPT) -o Tetris


#Classes
Bloc: Bloc.cpp
	$(FC) Bloc.cpp
Board: Board.cpp
	$(FC) Board.cpp
Jeu: Jeu.cpp
	$(FC) Jeu.cpp $(OPT)
Piece: Piece.cpp
	$(FC) Piece.cpp
Piece_I: Piece_I.cpp
	$(FC) Piece_I.cpp
Piece_O: Piece_O.cpp
	$(FC) Piece_O.cpp
Piece_T: Piece_T.cpp
	$(FC) Piece_T.cpp
clean:
	rm *.hpp.gch Tetris
