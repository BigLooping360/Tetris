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
  /*! /var jeu est le booléen qui permet de déterminer si la partie est finie ou non */
  bool jeu;
  static const int a=1;
  /*! /var NombreDePieces est le nombre max de Tetriminos disponibles dans notre Jeu*/
  static const int NombreDePieces=8;
  /*! /var nombre_aleatoire permettra une arrivée aléatoire des Tetriminos */
  int nombre_aleatoire;
  /*! /var b correspondra à notre grille de jeu */
  Board b;
  /*! /var PieceStockee est le pointeur sur la Piece stockée par l'utilisateur*/
  Piece *PieceStocke;
  /*! /var PieceEnCours est le pointeur sur la Piece en cours, c'est-à-dire celle en train de descendre le long du Board */
  Piece *PieceEnCours;
  /*! /var PieceSuivante est le pointeur sur la Piece suivante, c'est-à-dire celle suivant la Piece en cours*/
  Piece *PieceSuivante;

  public:

  /*! \fn bool getjeu()const
  * \brief Accesseur du booleen jeu
  * \return le booléen jeu
  */
  bool getjeu()const;
  /*! \fn void MaJ()
  * \brief Met à jour la grille à chaque fois qu'une Piece est posée
  */
  void MaJ();
  /*! \fn bool getstatut()
  * \brief Détermine si le jeu peut continuer ou non
  * \return vrai si la Piece en cours est bloqué, faux sinon
  */
  bool getstatut();
  /*! \fn void interaction(int c)
  * \brief Réagit face aux actions du joueur : envoie l'ordre de bouger une Piece, de la tourner, etc.
  * \param c est l'entier qui correspond à la touche tapée par l'utilisateur
  */
  void interaction(int c);
  /*! \fn Jeu()
  * \brief Constructeur de Jeu, initialise un début de partie
  */
  Jeu();

  friend class IHM;




};

#endif
