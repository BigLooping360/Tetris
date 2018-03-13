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
  //initialise le jeu
  void init();
  //Contient la boucle principale qui fait tourner le Jeu
  void play();
  // Met à jour la grille à chaque fois qu'une pièce est  posée
  void MaJ();
  //Envoie l'ordre de bouger la pièce
  void Move(char c);


};

#endif
