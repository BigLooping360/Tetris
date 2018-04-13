#ifndef __Jeu_HPP__
#define __Jeu_HPP__

#include <iostream>
#include "Board.hpp"
#include "Piece_I.hpp"
#include "Piece_O.hpp"
#include "Piece_T.hpp"
#include "Piece.hpp"
#include "IHM.hpp"

using namespace std;
class Jeu{
  // Largeur et Hauteur sont static et const pour pouvoir initialiser Grille
  bool jeu;
  bool pause;
  int Score;
  //Nombre de pièce pour le random
  static const int a=1;
  static const int NombreDePieces=4;
  int nombre_aleatoire;
  Board b;
  Piece *PieceStocke, *PieceEnCours, *PieceSuivante;
  public :
  //initialise le jeu
  void init();
  //Contient la boucle principale qui fait tourner le Jeu
  void play();
  // Met à jour la grille à chaque fois qu'une pièce est  posée
  void MaJ();
  //Envoie l'ordre de bouger la pièce
  void interaction(int c);
  //Permet de mettre le jeu en pause
  void pause();


};

#endif
