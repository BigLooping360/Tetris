FC = g++

#OPT = -O
#OPT = -p
OPT1 = -lncurses
OPT2 = -lcppunit
# executables
# main
main : IHM.o 	Bloc.o Board.o Piece_T.o Piece_I.o Piece_O.o Piece_L.o Piece_J.o Piece_S.o Piece_Z.o Board.o Piece.o Jeu.o Menu.o main.o
	$(FC) Bloc.o Board.o Piece_T.o Piece_I.o Piece_O.o Piece_L.o Piece_J.o Piece_S.o Piece_Z.o Piece.o Jeu.o IHM.o main.o Menu.o $(OPT1) -o Tetris
	./Tetris

Test_Piece_T : Board.o Piece.o Bloc.o Piece_T.o  TestPiece_T.o
			$(FC) Board.o  Piece.o Bloc.o Piece_T.o TestPiece_T.o $(OPT2) -o TestPiece_T
			./TestPiece_T

Test_Piece_I : Board.o Piece.o Bloc.o Piece_I.o  TestPiece_I.o
		$(FC) Board.o  Piece.o Bloc.o Piece_I.o TestPiece_I.o $(OPT2) -o TestPiece_I
		./TestPiece_I

Test_Piece : Board.o Piece.o Bloc.o Piece_I.o  TestPiece.o
		$(FC) Board.o  Piece.o Bloc.o Piece_I.o TestPiece.o $(OPT2) -o TestPiece
		./TestPiece


Test_Piece_J : Board.o TestPiece_J.o Piece.o Bloc.o Piece_J.o
		$(FC) Board.o TestPiece_J.o Piece.o Bloc.o Piece_J.o $(OPT2) -o TestPiece_J
		./TestPiece_J

Test_Piece_L : Board.o TestPiece_L.o Piece.o Bloc.o Piece_L.o
		$(FC) Board.o TestPiece_L.o Piece.o Bloc.o Piece_L.o $(OPT2) -o TestPiece_L
		./TestPiece_L

Test_Piece_S : Board.o TestPiece_S.o Piece.o Bloc.o Piece_S.o
		$(FC) Board.o TestPiece_S.o Piece.o Bloc.o Piece_S.o $(OPT2) -o TestPiece_S
		./TestPiece_S

Test_Piece_Z : Board.o TestPiece_Z.o Piece.o Bloc.o Piece_Z.o
		$(FC) Board.o TestPiece_Z.o Piece.o Bloc.o Piece_Z.o $(OPT2) -o TestPiece_Z
		./TestPiece_Z





#Classes
TestPiece_I.o: TestPiece_I.cpp
	$(FC) -c 	TestPiece_I.cpp

TestPiece.o: TestPiece.cpp
	$(FC) -c 	TestPiece.cpp

TestPiece_L.o: TestPiece_L.cpp
	$(FC) -c 	TestPiece_L.cpp

main.o: main.cpp
	$(FC) -c main.cpp
IHM.o: IHM.cpp
	$(FC) -c IHM.cpp
Bloc.o: Bloc.cpp
	$(FC) -c Bloc.cpp
Board.o: Board.cpp
	$(FC) -c Board.cpp
Jeu.o: Jeu.cpp
	$(FC) -c Jeu.cpp $(OPT)
Piece.o: Piece.cpp
	$(FC) -c Piece.cpp
Piece_I.o: Piece_I.cpp
	$(FC) -c Piece_I.cpp
Piece_O.o: Piece_O.cpp
	$(FC) -c Piece_O.cpp
Piece_T.o: Piece_T.cpp
	$(FC) -c Piece_T.cpp
Piece_L.o: Piece_L.cpp
	$(FC) -c Piece_L.cpp
Piece_J.o: Piece_J.cpp
	$(FC) -c Piece_J.cpp
Piece_S.o: Piece_S.cpp
	$(FC) -c Piece_S.cpp
Piece_Z.o: Piece_Z.cpp
	$(FC) -c Piece_Z.cpp
Menu.o : Menu.cpp
	$(FC) -c Menu.cpp
clean:
	rm *.hpp.gch Tetris *.o *.xml TestPiece_I TestPiece_T TestPiece_L TestPiece TestPiece_J TestPiece_S TestPiece_Z
