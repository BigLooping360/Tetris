#include <string>
#include <vector>
#include <iostream>
#include "Piece_J.hpp"
Piece_J::Piece_J():Piece() {
  color=2;

  tab[0] = Bloc(4,19);
  tab[1] = Bloc(4,18);
  tab[2] = Bloc(5,19);
  tab[3] = Bloc(5,18);
}

bool Piece_J::isRotateable(Board b){
  return true;
}

void Piece_J::Rotate(Board b){
}
