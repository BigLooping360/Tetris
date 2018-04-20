#ifndef __Piece_T_HPP__
#define __Piece_T_HPP__
#include <iostream>
#include "Piece.hpp"

#include<vector>
using namespace std;

/*! \class Piece_T
 * \brief Représentation d'un Tétrimino en forme de T. Hérite de Pièce.
 * \author Léa Lefrançois
 * \author Laura Couret
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet la représentation physique d'un Tétrimino en forme de T.
 *Cette classe hérite de Pièce, elle hérite donc de ses paramètres (couleur, etat, position, etc) et gardera ses méthodes de déplacement.
 */

class Piece_T : public Piece{
  public :
  /*! \fn bool isRotateable(Board b)=0
  * \brief Vérifie si on peut tourner le Tétrimino en forme de T d'un cran dans le sens horaire par rapport à la grille de jeu.
  * \param b est la grille de notre Tetris
  * \return renvoie vrai si c'est possible, non sinon
  */
  bool isRotateable(Board b);
  /*! \fn void Rotate(Board b)=0
  * \brief Permet la rotation d'un Tétrimino en forme de T dans le sens horaire par rapport à la grille de jeu.
  * \param b est la grille de notre Tetris
  */
  void Rotate(Board b);
  /*! \fn Piece_T()
  * \brief constructeur qui permet la création d'un Tétrimino en forme de T, composé de 4 cases : une ligne de 3 cases, et une case en dessous de la case du milieu de cette ligne.
  */
  Piece_T();
};

#endif
