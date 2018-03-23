#ifndef __Jeu_HPP__
#define __Jeu_HPP__

#include <iostream>
#include "Board.hpp"
#include "Piece.hpp"
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
  void move(int c);
  //Affiche la grille et la board envoyé :
  void afficher();


};

#endif
