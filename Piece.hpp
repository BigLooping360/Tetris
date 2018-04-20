#ifndef __Piece_HPP__
#define __Piece_HPP__
#include <iostream>
#include "Bloc.hpp"
#include "Board.hpp"
#include<vector>

using namespace std;

/*! \class Piece
 * \brief Représentation d'une pièce de jeu
 * \author Léa Lefrançois
 * \author Laura Couret
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet la représentation physique d'une pièce par sa position, son état et sa couleur.
 *Plus particulièrement, on pourra changer les paramètres caractéristiques de la pièce,
 * vérifier si on peut la déplacer ou la tourner,
 * la déplacer dans les 3 sens (gauche, droite, bas),
 * et la tourner dans le sens horaire ou dans le sens trigonométrique.
*/

class Piece {
  protected:
  /*! /var tab un vecteur de Bloc, c'est-à-dire un vecteur où chaque case a pour attribut la position en x et la position en y*/
  vector<Bloc> tab;
  /*! /var etat correspond à dans quel état de rotation se situe la pièce*/
  int etat;
  /*! /var bloque est un booleen qui permet de savoir si une pièce a atteint sa position finale dans la grille de jeu ou si elle peut encore descendre*/
  bool bloque;
  /*! /var color définit la couleur de la piece */
  int color;
  /*! /var stocke permet de savoir si une pièce peut être stocké. Attention, une pièce ne peut être stockée qu'une fois. */
  bool stocke;
  public:
  int getPosx(int i)const;
  int getPosy(int i)const;
  void setPosx(int i,int j);
  void setPosy(int i,int j);
  bool getbloque();
  int getcolor();

  /*! \fn bool Down(Board b)
  * \brief Vérifie si on peut descendre la pièce dans la grille de jeu
  * \param b est la grille de notre Tetris
  * \return true si on peut descendre la pièce d'un cran, false sinon
  */
  bool Down(Board b);
  /*! \fn bool Left(Board b)
  * \brief Vérifie si on peut déplacer la pièce vers la gauche dans la grille de jeu
  * \param b est la grille de notre Tetris
  * \return true si on peut déplacer la pièce d'un cran vers la gauche, false sinon
  */
  bool Left(Board b);
  /*! \fn bool Right(Board b)
  * \brief Vérifie si on peut déplacer la pièce vers la droite dans la grille de jeu
  * \param b est la grille de notre Tetris
  * \return true si on peut déplacer la pièce d'un cran vers la droite, false sinon
  */
  bool Right(Board b);
  /*! \fn void MoveDown(Board b)
  * \brief Descend la pièce d'un cran vers le bas dans la grille de jeu
  * \param b est la grille de notre Tetris
  */
  void MoveDown(Board b);
  /*! \fn void MoveRight(Board b)
  * \brief Décale la pièce d'un cran vers la droite dans la grille de jeu
  * \param b est la grille de notre Tetris
  */
  void MoveRight(Board b);
  /*! \fn void MoveLeft(Board b)
  * \brief Décale la pièce d'un cran vers le gauche dans la grille de jeu
  * \param b est la grille de notre Tetris
  */
  void MoveLeft(Board b);
  /*! \fn virtual bool isRotateable(Board b)=0
  * \brief Vérifie si on peut tourner une pièce d'un cran dans le sens horaire par rapport à la grille de jeu
  * \param b est la grille de notre Tetris
  */
  virtual bool isRotateable(Board b)=0;
  /*! \fn virtual void Rotate(Board b)=0
  * \brief Permet la rotation d'une pièce dans le sens horaire par rapport à la grille de jeu
  * \param b est la grille de notre Tetris
  */
  virtual void Rotate(Board b)=0;

  Piece();


};


#endif
