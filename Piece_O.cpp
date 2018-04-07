#include <string>
#include<vector>
#include <iostream>
#include "Piece_O.hpp"
Piece_O::Piece_O():Piece() {

  tab[0] = Bloc(4,19);
  tab[1] = Bloc(4,18);
  tab[2] = Bloc(5,19);
  tab[3] = Bloc(5,18);
}

bool Piece_O::isRotateable(Board b){
  return true;
}

void Piece_O::Rotate(Board b){
}
