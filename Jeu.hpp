#ifndef __Jeu_HPP__
#define __Jeu_HPP_
#include <iostream>
// #include "Board.cpp"
#include "Piece.cpp"
using namespace std;
class Jeu{
  // Largeur et Hauteur sont static et const pour pouvoir initialiser Grille
  bool jeu;
  Board b;
  Piece PieceStocke, PieceEnCours, PieceSuivante;
  public :
  void init();
  void play();



};

#endif
