#include "Piece.hpp"
#include <iostream>
#include <string>
#include<vector>

using namespace std;

void Piece::setetat(int i){
  etat =i;
}

int Piece::getetat(){
  return etat;
}

int Piece::getcolor(){
  return color;
}

int Piece::getPosx(int i)const{
    return tab[i].getPosx();
  }

int Piece::getPosy(int i)const{
  return tab[i].getPosy();
}

void Piece::setPosx(int i,int j){
  tab[i].setPosx(j);
}

void Piece::setPosy(int i, int j){
  tab[i].setPosy(j);
}

bool Piece::getbloque(){
  return bloque;
}

//Regarde si il n'y a pas un bloc en-dessous duquel il y a un bloc;
bool Piece::Down(Board b){
  for (int i = 0; i < 4; i++) {
    if ((b.getGrille(getPosx(i), getPosy(i)-1)==1) or (getPosy(i)==0))
      return false;
    }
  return true;
}

bool Piece::Left(Board b){
  for (int i = 0; i < 4; i++) {
    if ((b.getGrille(getPosx(i)-1, getPosy(i))==1) or (getPosx(i)==0))
      return false;
    }
  return true;
}

bool Piece::Right(Board b){
  for (int i = 0; i < 4; i++) {
    if ((b.getGrille(getPosx(i)+1, getPosy(i))==1) or (getPosx(i)==9))
      return false;
    }
  return true;
}



void Piece::MoveDown(Board b){
  //On check si une fois que l'on baisse la pièce elle se retrouve coincée
  if (Down(b)==false)
    bloque=true;
  else
    for (int i = 0; i < 4; i++) {
      setPosy(i,tab[i].getPosy()-1);
    }

}
void Piece::MoveRight(Board b){
    if (Right(b))
      for (int i = 0; i < 4; i++) {
        setPosx(i,tab[i].getPosx()+1);
        }
    }
 void Piece::MoveLeft(Board b){
        if (Left(b))
          for (int i = 0; i < 4; i++) {
            setPosx(i,tab[i].getPosx()-1);
            }
}

Piece::Piece():tab(5,Bloc(0,0)) {
  tab[0] = Bloc(4,19);
  tab[1] = Bloc(5,19);
  tab[2] = Bloc(6,19);
  tab[3] = Bloc(5,18);
  bloque=false;
//On pose 1 comme le premier état sur 4
  etat=1;
}
