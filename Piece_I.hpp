#ifndef __Piece_I_HPP__
#define __Piece_I_HPP__
#include <iostream>
#include "Piece.hpp"

#include<vector>
using namespace std;

class Piece_I : public Piece{
  public :
  bool isRotateable(Board b);
  void Rotate(Board b);
  Piece_I();
};

#endif
