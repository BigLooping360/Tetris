#include "JeuClassique.hpp"


JeuClassique::JeuClassique():Jeu(){
  points=0;
}


int JeuClassique::getpoints(){
  return points;
}

void JeuClassique::setpoints(int p){
  points+=p;
}

void JeuClassique::MaJ(){
  int nb_ligne=0;
  nb_ligne=MaJPiece();
  switch (nb_ligne){

    case 1:
      setpoints(10);
      break;

    case 2:
      setpoints(30);
      break;

    case 3:
      setpoints(60);
      break;

    case 4 :
      setpoints(100);
      break;

  }
}
