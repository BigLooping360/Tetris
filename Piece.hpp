#ifndef __Piece_HPP__
#define __Piece_HPP__
#include <iostream>
#include "Bloc.cpp"
#include<vector>
using namespace std;

class Piece{
  vector<Bloc> tab;


  public :
  //Renvoie la position x du ième bloc
  int getPosx(int i)const;
  int getPosy(int i)const;

  bool isMoveable();
  bool isRotateable();
  Piece();




};

#endif
