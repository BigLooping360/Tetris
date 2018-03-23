#include <string>
#include<vector>
#include <iostream>
#include "Piece_O.hpp"
Piece_O::Piece_O():tab(5,Bloc(0,0)) {

  tab[0] = Bloc(4,19);
  tab[1] = Bloc(4,18);
  tab[2] = Bloc(5,19);
  tab[3] = Bloc(5,18);


  bloque=false;
  //On pose 1 comme le premier état sur 4
  etat=1;
}

bool Piece_O::isRotateable(Board b){
  return true;
}

void Piece_O::Rotate(Board b){
}
