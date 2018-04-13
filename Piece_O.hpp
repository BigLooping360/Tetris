#ifndef __Piece_O_HPP__
#define __Piece_O_HPP__
#include <iostream>
#include "Piece.hpp"

#include<vector>
using namespace std;

/*! \class Piece_O
 * \brief Représentation d'un Tétrimino en forme de carré. Hérite de Pièce.
 * \author Léa Lefrançois
 * \author Laura Couret
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet la représentation physique d'un Tétrimino en forme de I.
 *Cette classe hérite de Pièce, elle hérite donc de ses paramètres (couleur, etat, position, etc) et gardera ses méthodes de déplacement.
 */

class Piece_O : public Piece{
  public :
  bool isRotateable(Board b);
  void Rotate(Board b);
  Piece_O();
};

#endif
