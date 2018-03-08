#ifndef __Board_HPP__
#define __Board_HPP_
#include <iostream>
using namespace std;
class Board{
  // Largeur et Hauteur sont static et const pour pouvoir initialiser Grille
  static const int Largeur=12;
  static const int Hauteur=21;
  int Grille[Largeur][Hauteur];

  public :
  //Accesseurs :
  int getLargeur() const;
  int getHauteur() const;
  int getGrille(int x, int y) const;

  //Mutateurs :
  void setGrille(int x, int y);

  //Autres
  void init();

  //Amis :
  friend ostream  &operator <<(ostream &out,  Board &);

};

ostream & operator<<(ostream &out,  Board &b);
#endif
