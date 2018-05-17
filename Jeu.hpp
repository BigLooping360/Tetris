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
 *
 *Ce module permet l'initialisation du début d'une partie,
 *la mise à jour des différents paramètres suite aux actions d'un joueur,
 *et actionne le déplacement d'une Piece.
*/

class Jeu {

protected:
  /*! jeu est le booléen qui permet de déterminer si la partie est finie ou non */
  bool jeu;
  static const int a=1;
  /*! NombreDePieces est le nombre max de Tetriminos disponibles dans notre Jeu*/
  static const int NombreDePieces=8;
  /*! nombre_aleatoire permettra une arrivée aléatoire des Tetriminos */
  int nombre_aleatoire;
  /*! b correspondra à notre grille de jeu */
  Board b;
  /*! PieceStockee est le pointeur sur la Piece stockée par l'utilisateur*/
  Piece *PieceStocke;
  /*! PieceEnCours est le pointeur sur la Piece en cours, c'est-à-dire celle en train de descendre le long du Board */
  Piece *PieceEnCours;
  /*! PieceSuivante est le pointeur sur la Piece suivante, c'est-à-dire celle suivant la Piece en cours*/
  Piece *PieceSuivante;

  public:
  /*! \fn void setPieceEnCoursI()
  * \brief change la PieceEnCours par une Piece_I, attention seulement utile pour les tests unitaires
  */
  void setPieceEnCoursI();
  /*! \fn void setPieceEnCoursO()
  * \brief change la PieceEnCours par une Piece_O, attention seulement utile pour les tests unitaires
  */
  void setPieceEnCoursO();
  /*! \fn void stocker()
  * \brief permet le stockage de la PieceEnCours
  */
  void stocker();
  /*! \fn bool getjeu()const
  * \brief Accesseur du booléen jeu
  * \return le booléen jeu
  */
  bool getjeu()const;
  /*! \fn int MaJPiece()
  * \brief Met à jour la grille à chaque fois qu'une Piece est posée
  * \return le nombre de lignes complétées par l'utilisateur grâce à la dernière Piece ajoutée
  */
  int MaJPiece();
  /*! \fn void MaJ()
  * \brief Met à jour l'ensemble des paramètres (scores, Pieces) à chaque fois qu'une pièce est posée
  */
  virtual void MaJ()=0;
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
