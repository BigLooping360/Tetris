#ifndef __Piece_S_HPP__
#define __Piece_S_HPP__
#include <iostream>
#include "Piece.hpp"

#include<vector>
using namespace std;

/*! \class Piece_S
 * \brief Représentation d'un Tétrimino en forme de S. Hérite de Pièce.
 * \author Léa Lefrançois
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet la représentation physique d'un Tétrimino en forme de S.
 *Cette classe hérite de Pièce, elle hérite donc de ses paramètres (couleur, etat, position, etc) et gardera ses méthodes de déplacement.
 */

class Piece_S : public Piece{
  public :
  /*! \fn bool isRotateable(Board b)=0
  * \brief Vérifie si on peut tourner le Tétrimino en forme de S d'un cran dans le sens horaire par rapport à la grille de jeu.
  * \param b est la grille de notre Tetris
  */
  bool isRotateable(Board b);
  /*! \fn void Rotate(Board b)=0
  * \brief Permet la rotation d'un Tétrimino en forme de S dans le sens horaire par rapport à la grille de jeu.
  * \param b est la grille de notre Tetris
  */
  void Rotate(Board b);
  /*! \fn Piece_S()
  * \brief constructeur qui permet la création d'un Tétrimino en forme de S, composé de 4 cases. A son initilisation, il est en position carrée mais avec la rangée supérieure décalée d'un cran vers la droite.
  */
  Piece_S();
};

#endif
