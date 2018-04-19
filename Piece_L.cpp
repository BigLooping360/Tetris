#include <string>
#include <vector>
#include <iostream>
#include "Piece_L.hpp"

Piece_L::Piece_L():Piece() {
  color=2;

  tab[0] = Bloc(4,18);
  tab[1] = Bloc(4,19);
  tab[2] = Bloc(5,19);
  tab[3] = Bloc(6,19);
}

bool Piece_L::isRotateable(Board b){
  return true;
}

void Piece_L::Rotate(Board b){

  switch (etat){
    case 1:
      if (isRotateable(b)){
        setPosx(0,getPosx(1)-1);
        setPosy(0,getPosy(1)+1);

        setPosx(2,getPosx(1)-1);
        setPosy(2,getPosy(1)-1);

        setPosx(3,getPosx(1)-2);
        setPosy(3,getPosy(1)-2);
        etat++;
      }
      break;

    case 2:
    if (isRotateable(b)){
      setPosx(0,getPosx(1)+1);
      setPosy(0,getPosy(1)+1);

      setPosx(2,getPosx(1)-1);
      setPosy(2,getPosy(1)+1);

      setPosx(3,getPosx(1)-2);
      setPosy(3,getPosy(1)+2);
      etat++;
      }
      break;

    case 3:
    if (isRotateable(b)){
      setPosx(0,getPosx(1)+1);
      setPosy(0,getPosy(1)-1);

      setPosx(2,getPosx(1)+1);
      setPosy(2,getPosy(1)+1);

      setPosx(3,getPosx(1)+2);
      setPosy(3,getPosy(1)+2);
      etat++;
      }
      break;

    case 4 :
    if (isRotateable(b)){
      setPosx(0,getPosx(1)-1);
      setPosy(0,getPosy(1)-1);

      setPosx(2,getPosx(1)+1);
      setPosy(2,getPosy(1)-1);

      setPosx(3,getPosx(1)+2);
      setPosy(3,getPosy(1)-2);
      etat=1;
      }
      break;


  }

}
