#ifndef __Piece_L_HPP__
#define __Piece_L_HPP__
#include <iostream>
#include "Piece.hpp"

#include<vector>
using namespace std;

/*! \class Piece_O
 * \brief Représentation d'un Tétrimino en forme de L. Hérite de Pièce.
 * \author Laura Couret
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet la représentation physique d'un Tétrimino en forme de L.
 *Cette classe hérite de Pièce, elle hérite donc de ses paramètres (couleur, etat, position, etc) et gardera ses méthodes de déplacement.
 */

class Piece_L : public Piece{
  public :
  /*! \fn bool isRotateable(Board b)=0
  * \brief Vérifie si on peut tourner le Tétrimino en forme de L d'un cran dans le sens horaire par rapport à la grille de jeu.
  * \param b est la grille de notre Tetris
  */
  bool isRotateable(Board b);
  /*! \fn void Rotate(Board b)=0
  * \brief Permet la rotation d'un Tétrimino en forme de L dans le sens horaire par rapport à la grille de jeu.
  * \param b est la grille de notre Tetris
  */
  void Rotate(Board b);
  /*! \fn Piece_L()
  * \brief constructeur qui permet la création d'un Tétrimino en forme de L, composé de 4 cases. A son initilisation, il est en position : 3 cases en ligne et une case sous le côté gauche.
  */
  Piece_L();
};

#endif
