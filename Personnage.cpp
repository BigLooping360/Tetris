#include "Personnage.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <ncurses.h>
#include<stdlib.h>


Personnage::Personnage(){
  Posx = 4;
  Posy = 0;
  Direction = true;
  bloque = false;
}

  int Personnage::getPosx(){
    return Posx;
  }

  int Personnage::getPosy(){
    return Posy;
  }

  void Personnage::setPosy(int i){
    Posy=i;
  }

  bool Personnage::getbloque(){
    return bloque;
  }

  void Personnage::setbloque(){
    bloque=!bloque;
  }

  bool Personnage::getDirection(){
    return Direction;
  }

  void Personnage::Deplacement(Board b){
    if (Direction){
      if (Posx==9)
        Direction=!Direction;
      else{
        if ( (b.getGrille(Posx+1,Posy)==0) and ((Posy==0) or (b.getGrille(Posx+1,Posy-1)==1)) )
          Posx++;
        else{
          if ((b.getGrille(Posx+1,Posy+1)==0) and (b.getGrille(Posx+1,Posy)==1)){
            Posx++;
            Posy++;
          }
          else
            Direction=!Direction;
          }
      }
    }
    if (!Direction){
      if (Posx==0)
        Direction=!Direction;
      else{
        if ( (b.getGrille(Posx-1,Posy)==0) and ((Posy==0) or (b.getGrille(Posx-1,Posy-1)==1)) )
          Posx--;
        else{
          if ( (b.getGrille(Posx-1,Posy+1)==0) and (b.getGrille(Posx-1,Posy)==1)){
            Posx--;
            Posy++;
          }
          else
            Direction=!Direction;
          }
      }
    }

  }
