#include "Bloc.hpp"
#include <iostream>
#include <string>
using namespace std;

Bloc::Bloc(int x, int y){
  Posx = x;
  Posy = y;
}

//Accesseurs :

int Bloc::getPosx()const{
  return Posx;
}
int Bloc::getPosy() const{
  return Posy;
}

//Mutateurs

void Bloc::setPosx(int x) {
  Posx=x;
}
void Bloc::setPosy(int y) {
  Posy=y;
}
