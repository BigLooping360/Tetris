#ifndef __Piece_O_HPP__
#define __Piece_O_HPP__
#include <iostream>
#include "Piece.hpp"

#include<vector>
using namespace std;

/*! \class Piece_O
 * \brief Représentation d'un Tétrimino en forme de carré. Hérite de Piece.
 * \author Léa Lefrançois
 * \author Laura Couret
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet la représentation physique d'un Tétrimino en forme de carré.
 *Cette classe hérite de Piece, elle hérite donc de ses paramètres (couleur, etat, position, etc) et gardera ses méthodes de déplacement.
 */

class Piece_O : public Piece{
  public :
  /*! \fn bool isRotateable(Board b)=0
  * \brief Vérifie si on peut tourner le Tétrimino en forme de carré d'un cran dans le sens horaire par rapport au Board.
  * \param b est le Board de notre Tetris
  * \return renvoie vrai dans tous les cas car la rotation d'un carré ne change pas sa position dans la grille
  */
  bool isRotateable(Board b);
  /*! \fn void Rotate(Board b)=0
  * \brief Permet la rotation d'un Tétrimino en forme de carré dans le sens horaire par rapport au Board. Ne change rien en vu de la forme du Tétrimino.
  * \param b est le Board de notre Tetris
  */
  void Rotate(Board b);
  /*! \fn Piece_O()
  * \brief constructeur qui permet la création d'un Tétrimino en forme de carré, composé de 4 cases. A son initilisation, il est en position verticale.
  */
  Piece_O();
};

#endif
