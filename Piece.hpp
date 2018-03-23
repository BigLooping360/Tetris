#ifndef __Piece_HPP__
#define __Piece_HPP__

#include <iostream>
#include "Bloc.hpp"
#include "Board.hpp"
#include<vector>
using namespace std;

class Piece{
  protected :
  vector<Bloc> tab;
  bool bloque;
  int etat;
  int color;
  //Une pièce ne peut être stocké qu'une fois. Ce booléen permet de
  //savoir si une pièce peut être stocké.
  bool stocke;

  public :
  //getter et setters sur les pièces de tab
  int getPosx(int i)const;
  int getPosy(int i)const;
  void setPosx(int i,int j);
  void setPosy(int i,int j);
  bool getbloque();
  //Verificateurs (peut-on bouger dans la direction ..)
  bool Down(Board b);
  bool Left(Board b);
  bool Right(Board b);
  bool isRotateable(Board b);

  //Mouvement Pièce
  void MoveDown(Board b);
  void MoveRight(Board b);
  void MoveLeft(Board b);
  // Le etat permet de déterminer la manièredont on va tourner la pièce
  void Rotate(Board b);
  //autres
  //void afficher(Board b);


  Piece();


};

#endif
