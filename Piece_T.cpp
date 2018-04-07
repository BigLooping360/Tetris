#include <string>
#include<vector>
#include <iostream>
#include "Piece_T.hpp"
Piece_T::Piece_T():Piece() {

  tab[0] = Bloc(4,19);
  tab[1] = Bloc(5,19);
  tab[2] = Bloc(6,19);
  tab[3] = Bloc(5,18);
}

bool Piece_T::isRotateable(Board b){
  switch (etat){
    case 1:
      if ( (getPosy(1)!=b.getHauteur()-1) and (b.getGrille(getPosx(1),getPosy(1)+1)==0))
           return true;
      else
        return false;
      break;

    case 2:
      if ( (getPosx(1)!=b.getLargeur()-1) and (b.getGrille(getPosx(1)+1,getPosy(1))==0))
           return true;
      else
        return false;
      break;
    case 3:
      if ( (getPosy(1)!=0) and (b.getGrille(getPosx(1),getPosy(1)-1)==0))
           return true;
      else
        return false;
      break;
    case 4 :
      if ( (getPosx(1)!=0) and (b.getGrille(getPosx(1)-1,getPosy(1))==0))
           return true;
      else
        return false;
      break;


  }
}

void Piece_T::Rotate(Board b){

switch (etat){
  case 1:
    if (isRotateable(b)){
      setPosx(0,getPosx(1));
      setPosy(0,getPosy(1)+1);

      setPosx(2,getPosx(1));
      setPosy(2,getPosy(1)-1);

      setPosx(3,getPosx(1)-1);
      setPosy(3,getPosy(1));
      etat++;
    }
    break;

  case 2:
  if (isRotateable(b)){
    setPosx(0,getPosx(1)+1);
    setPosy(0,getPosy(1));

    setPosx(2,getPosx(1)-1);
    setPosy(2,getPosy(1));

    setPosx(3,getPosx(1));
    setPosy(3,getPosy(1)+1);
    etat++;
    }
    break;

  case 3:
  if (isRotateable(b)){
    setPosx(0,getPosx(1));
    setPosy(0,getPosy(1)-1);

    setPosx(2,getPosx(1));
    setPosy(2,getPosy(1)+1);

    setPosx(3,getPosx(1)+1);
    setPosy(3,getPosy(1));
    etat++;
    }
    break;

  case 4 :
  if (isRotateable(b)){
    setPosx(0,getPosx(1)-1);
    setPosy(0,getPosy(1));

    setPosx(2,getPosx(1)+1);
    setPosy(2,getPosy(1));

    setPosx(3,getPosx(1));
    setPosy(3,getPosy(1)-1);
    etat=1;
    }
    break;

  }
}
