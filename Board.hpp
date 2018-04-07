#ifndef __Board_HPP__
#define __Board_HPP__
#include <iostream>
using namespace std;
class Board{
  // Largeur et Hauteur sont static et const pour pouvoir initialiser Grille
  static const int Largeur=10;
  static const int Hauteur=20;
  //Grille contient 1 si elle est remplie 0 si la case est vide
  int Grille[Largeur][Hauteur];

  public :
  //Accesseurs :
  int getLargeur() const;
  int getHauteur() const;
  int getGrille(int x, int y) const;

  //Mutateurs :
  void setGrille(int x, int y);

  //Le changer en constructeur
  void init();


  //Amis :
  friend ostream  &operator <<(ostream &out,  Board &);

};

ostream & operator<<(ostream &out,  Board &b);
#endif
