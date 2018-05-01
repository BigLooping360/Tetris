#include "JeuClassique.hpp"


JeuClassique::JeuClassique():Jeu(){
  points=0;
}


int JeuClassique::getpoints(){
  return points;
}

void JeuClassique::MaJ(){
  MaJPiece();
  points++;
}
