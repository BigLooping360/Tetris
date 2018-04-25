#ifndef __Piece_I_HPP__
#define __Piece_I_HPP__
#include <iostream>
#include "Piece.hpp"

#include<vector>
using namespace std;

/*! \class Piece_I
 * \brief Représentation d'un Tétrimino en forme de I. Hérite de Piece.
 * \author Léa Lefrançois
 * \author Laura Couret
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet la représentation physique d'un Tétrimino en forme de I.
 *Cette classe hérite de Piece, elle hérite donc de ses paramètres (couleur, etat, position, etc) et gardera ses méthodes de déplacement.
 */

class Piece_I : public Piece{
  public :
  /*! \fn virtual bool isRotateable(Board b)=0
  * \brief Vérifie si on peut tourner le Tétrimino en forme de I d'un cran dans le sens horaire par rapport au Board
  * \param b est le Board de notre Tetris
  */
  virtual bool isRotateable(Board b);
  /*! \fn virtual void Rotate(Board b)=0
  * \brief Permet la rotation d'un Tétrimino en forme de I dans le sens horaire par rapport au Board
  * \param b est le Board de notre Tetris
  */
  virtual void Rotate(Board b);
  /*! \fn Piece_I()
  * \brief constructeur qui permet la création d'un Tétrimino en forme de I, composé de 4 cases. A son initilisation, il est en position verticale.
  */
  Piece_I();
};

#endif
