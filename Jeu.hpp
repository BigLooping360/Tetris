#ifndef __Jeu_HPP__
#define __Jeu_HPP__

#include <iostream>
#include "Board.hpp"
#include "Piece_I.hpp"
#include "Piece_O.hpp"
#include "Piece_T.hpp"
#include "Piece_L.hpp"
#include "Piece_J.hpp"
#include "Piece_S.hpp"
#include "Piece_Z.hpp"
#include "Piece.hpp"


using namespace std;

/*! \class Jeu
 * \brief Gestion du déroulement d'une partie
 * \author Victor Le Maistre
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *Ce module permet l'initialisation du début d'une partie,
 *la mise à jour des différents paramètres suite aux actions d'un joueur,
 *et actionne le déplacement d'une Piece.
*/

class Jeu {
  /*! /var partie est le booléen qui vaut true tant que la partie peut continuer, false quand le joueur est bloqué*/
  bool jeu;
  int Score;
  /*! /var a est le nombre de pièce pour le random*/

  static const int a=1;
  /*! /var NombreDePieces est le nombre max de Tetriminos*/
  static const int NombreDePieces=6;
    /*! /var nombre_aleatoire permettra une arrivée aléatoire des Tetriminos */
  int nombre_aleatoire;
  /*! /var b correspondra à notre grille de jeu */
  Board b;
  /*! /var Ces pointeurs sur pièce permettront de modifier, au cours de la partie, la pièce en cours, la pièce suivante et la pièce stockée */
  Piece *PieceStocke, *PieceEnCours, *PieceSuivante;
  public :

  /*! \fn void MaJ()
  * \brief Met à jour la grille à chaque fois qu'une pièce est posée
  */
  void MaJ();

  bool getjeu()const;

  bool getstatut();

  //Envoie l'ordre de bouger la pièce
  void interaction(int c);
  //Permet de mettre le jeu en pause
  //void pause();

  Jeu();
  friend class IHM;




};

#endif
