#ifndef __Piece_HPP__
#define __Piece_HPP__
#include <iostream>
#include "Bloc.cpp"
#include "Board.cpp"
#include<vector>
using namespace std;

class Piece{
  vector<Bloc> tab;
  bool bloque;

  public :
  //getter et setters sur les pièces de tab
  int getPosx(int i)const;
  int getPosy(int i)const;
  void setPosx(int i,int j);
  void setPosy(int i,int j);
  bool getbloque();
  //Verificateurs
  bool isMoveable(Board b);
  bool isRotateable();

  //autres
  void fall(Board b);
  void afficher(Board b);


  Piece();


};

#endif
