#ifndef __Piece_T_HPP__
#define __Piece_T_HPP__
#include <iostream>
#include "Piece.hpp"

#include<vector>
using namespace std;

class Piece_T : public Piece{
  public :
  bool isRotateable(Board b);
  void Rotate(Board b);
  Piece_T();
};

#endif
