#ifndef __Piece_HPP__
#define __Piece_HPP__
#include <iostream>
#include "Bloc.hpp"
#include "Board.hpp"
#include<vector>

using namespace std;

/*! \class Piece
 * \brief Représentation d'une Piece de jeu
 * \author Léa Lefrançois
 * \author Laura Couret
  * \author Victor Le Maistre
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet la représentation physique d'une Piece par sa position, son état et sa couleur.
 *Plus particulièrement, on pourra changer les paramètres caractéristiques de la Piece,
 * vérifier si on peut la déplacer ou la tourner,
 * la déplacer dans les 3 sens (gauche, droite, bas),
 * et la tourner dans le sens horaire ou dans le sens trigonométrique.
*/

class Piece {
  protected:
  /*! /var tab un vecteur de Bloc, c'est-à-dire un vecteur où chaque case a pour attribut la position en x et la position en y*/
  vector<Bloc> tab;
  /*! /var etat correspond à dans quel état de rotation se situe la Piece*/
  int etat;
  /*! /var bloque est un booleen qui permet de savoir si une Piece a atteint sa position finale dans le Board ou si elle peut encore descendre*/
  bool bloque;
  /*! /var color définit la couleur de la Piece */
  int color;
  /*! /var stocke permet de savoir si une Piece peut être stockée. Attention, une Piece ne peut être stockée qu'une fois.
  Vaut vrai si la pièce a déjà était stocké. */
  bool stocke;
  public:
  /*! \fn int getPosx(int i)const
  * \brief Accesseur de la position en x d'un Bloc
  * \param i est le numéro du Bloc dont on veut obtenir les informations
  * \return Retourne la position en x du Bloc numero i de la Piece en question
  */
  int getPosx(int i)const;
  /*! \fn int getPosy(int i)const
  * \brief Accesseur de la position en y d'un Bloc
  * \param i est le numéro du Bloc dont on veut obtenir les informations
  * \return Retourne la position en y du Bloc numero i de la Piece en question
  */
  int getPosy(int i)const;
  /*! \fn int setPosx(int i,int j)
  * \brief Mutateur de la position en x d'un Bloc
  * \param i est le numéro du Bloc dont on veut modifier la position en x par j
  */
  void setPosx(int i,int j);
  /*! \fn int setPosy(int i,int j)
  * \brief Mutateur de la position en y d'un Bloc
  * \param i est le numéro du Bloc dont on veut modifier la position en y par j
  */
  void setPosy(int i,int j);
  /*! \fn bool getbloque()
  * \brief Accesseur du booléen bloqué d'une Piece
  * \return Retourne le booléen bloque
  */
  bool getbloque();

  /*! \fn int getcolor()
  * \brief Accesseur de la couleur d'une Piece
  * \return Retourne l'entier correspondant à la couleur de la Piece
  */
  int getcolor();

  /*! \fn void setetat(int i)
  * \brief Mutateur d'état d'une pièce ATTENTION UTILE SEULEMENT POUR LES TESTS UNITAIRES A NE PAS UTILISER
  * \param i est l'entier qui correspond à l'état que l'on veut donner à la pièce
  */
  void setetat(int i);

  /*! \fn int getetat()
  * \brief Accesseur d'état d'une pièce
  * \return i est l'entier qui correspond à l'état de la pièce
  */
  int getetat();

  /*! \fn bool Down(Board b)
  * \brief Vérifie si on peut descendre la Piece dans le Board
  * \param b est le Board de notre Tetris
  * \return true si on peut descendre la Piece d'un cran, false sinon
  */
  bool Down(Board b);
  /*! \fn bool Left(Board b)
  * \brief Vérifie si on peut déplacer la Piece vers la gauche dans le Board
  * \param b est le Board de notre Tetris
  * \return true si on peut déplacer la Piece d'un cran vers la gauche, false sinon
  */
  bool Left(Board b);
  /*! \fn bool Right(Board b)
  * \brief Vérifie si on peut déplacer la Piece vers la droite dans le Board
  * \param b est le Board de notre Tetris
  * \return true si on peut déplacer la Piece d'un cran vers la droite, false sinon
  */
  bool Right(Board b);
  /*! \fn void MoveDown(Board b)
  * \brief Descend la Piece d'un cran vers le bas dans le Board
  * \param b est le Board de notre Tetris
  */
  void MoveDown(Board b);
  /*! \fn void MoveRight(Board b)
  * \brief Décale la Piece d'un cran vers la droite dans le Board
  * \param b est le Board de notre Tetris
  */
  void MoveRight(Board b);
  /*! \fn void MoveLeft(Board b)
  * \brief Décale la Piece d'un cran vers le gauche dans le Board
  * \param b est le Board de notre Tetris
  */
  void MoveLeft(Board b);
  /*! \fn bool setstocke()
  * \brief Mutateur de stocke
  */
  void setstocke();
  /*! \fn bool getstocke()
  * \brief Accesseur de stocke
  * \return le booléen stocke
  */
  bool getstocke();
  /*! \fn virtual bool isRotateable(Board b)=0
  * \brief Vérifie si on peut tourner une Piece d'un cran dans le sens horaire par rapport au Board
  * \param b est le Board de notre Tetris
  */
  virtual bool isRotateable(Board b)=0;
  /*! \fn virtual void Rotate(Board b)=0
  * \brief Permet la rotation d'une Piece dans le sens horaire par rapport au Board
  * \param b est le Board de notre Tetris
  */
  virtual void Rotate(Board b)=0;
  /*! \fn Piece()
  * \brief Constructeur d'une Piece de Jeu général
  */


  Piece();


};


#endif
