#ifndef __Jeu_HPP__
#define __Jeu_HPP_
#include <iostream>
#include "Board.cpp"
using namespace std;
class Jeu{
  // Largeur et Hauteur sont static et const pour pouvoir initialiser Grille
  Board b;

  public :
  void init();
  void play();



};

#endif
