FC = g++

#OPT = -O
#OPT = -p
OPT = -lncurses

# executables
# main
main : Bloc.cpp Board.cpp Piece_T.cpp Piece_I.cpp Piece_O.cpp Piece_L.cpp Piece_J.cpp Board.cpp Piece.cpp Jeu.cpp Menu.cpp main.cpp
	$(FC) Bloc.cpp Board.cpp Piece_T.cpp Piece_I.cpp Piece_O.cpp Piece_L.cpp Piece_J.cpp Piece.cpp Jeu.cpp IHM.cpp main.cpp Menu.cpp $(OPT) -o Tetris
	./Tetris


#Classes
IHM: IHM.cpp
	$(FC) IHM.cpp
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
Piece_L: Piece_L.cpp
	$(FC) Piece_L.cpp
Piece_J: Piece_J.cpp
	$(FC) Piece_J.cpp
Menu : Menu.cpp
	$(FC) Menu.cpp
clean:
	rm *.hpp.gch Tetris
