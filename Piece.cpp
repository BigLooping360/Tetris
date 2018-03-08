#include <iostream>
#include "Piece.hpp"
#include <string>
#include<vector>

using namespace std;
//Initialise la piece à une certaine position
Piece::Piece():tab(5,Bloc(0,0)) {

  for (int i = 0; i < 4; i++) {
    tab[i] = Bloc(4,4-i);
    cout<<tab[i].getPosx()<<endl;
    cout<<tab[i].getPosy()<<endl;
  }
}
//Retourne la position x du bloc i
int Piece::getPosx(int i)const{
    return tab[i].getPosx();
  }

//Retourne la position y du bloc i
int Piece::getPosy(int i)const{
  return tab[i].getPosy();
}
//Regarde si il n'y a pas un bloc en-dessous duquel il y a un bloc;
bool Piece::isMoveable(B){
  for (int i = 0; i < 4; i++) {
    if (getPosy(i)==1)
      return false;
    }
  return true;
}
