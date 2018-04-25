#include <string>
#include <vector>
#include <iostream>
#include "Piece_S.hpp"

Piece_S::Piece_S():Piece() {

  color=6;

  tab[0] = Bloc(4,18);
  tab[1] = Bloc(5,18);
  tab[2] = Bloc(5,19);
  tab[3] = Bloc(6,19);
}

bool Piece_S::isRotateable(Board b){

  switch (etat){

    case 1:
      return ((getPosy(1) >= 1 ) and (b.getGrille(getPosx(1)+1,getPosy(1)-1)==0) and (b.getGrille(getPosx(1)+1,getPosy(1))==0));
      break;

    case 2:
      return ((getPosx(1) >= 1 ) and (b.getGrille(getPosx(1),getPosy(1)-1)==0) and (b.getGrille(getPosx(1)-1,getPosy(1)-1)==0));
      break;

    case 3:
      return ((getPosy(1) < b.getHauteur()-1 ) and (b.getGrille(getPosx(1)-1,getPosy(1))==0) and (b.getGrille(getPosx(1)-1,getPosy(1)+1)==0));
      break;

    case 4 :
      return ((getPosx(1) < b.getLargeur()-1 ) and (b.getGrille(getPosx(1)+1,getPosy(1)+1)==0) and (b.getGrille(getPosx(1)-1,getPosy(1)-1)==0)) ;
      break;

  }
}

void Piece_S::Rotate(Board b){

  switch (etat){
    case 1:
      if (isRotateable(b)){
        setPosx(0,getPosx(0)+1);
        setPosy(0,getPosy(0)+1);

        setPosx(2,getPosx(2)+1);
        setPosy(2,getPosy(2)-1);

        setPosy(3,getPosy(3)-2);
        etat++;
      }
      break;

    case 2:
    if (isRotateable(b)){
      setPosx(0,getPosx(0)+1);
      setPosy(0,getPosy(0)-1);

      setPosx(2,getPosx(2)-1);
      setPosy(2,getPosy(2)-1);

      setPosx(3,getPosx(3)-2);

      etat++;
      }
      break;

    case 3:
    if (isRotateable(b)){
      setPosx(0,getPosx(0)-1);
      setPosy(0,getPosy(0)-1);

      setPosx(2,getPosx(2)-1);
      setPosy(2,getPosy(2)+1);


      setPosy(3,getPosy(3)+2);
      etat++;
      }
      break;

    case 4 :
    if (isRotateable(b)){
      setPosx(0,getPosx(0)-1);
      setPosy(0,getPosy(0)+1);

      setPosx(2,getPosx(2)+1);
      setPosy(2,getPosy(2)+1);

      setPosx(3,getPosx(3)+2);

      etat=1;
      }
      break;


  }
}
