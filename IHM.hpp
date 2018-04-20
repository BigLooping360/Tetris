#ifndef __IHM_HPP__
#define __IHM_HPP__
#include <iostream>
#include "Board.hpp"
#include "Piece.hpp"
#include "Personnage.hpp"

#include<vector>
using namespace std;

/*! \class IHM
 * \brief Gère les interactions entre les actions du joueur et le jeu à proprement parler
 * \author Léa Lefrançois
 * \author Laura Couret
  * \author Victor Le Maistre
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module va permettre de :
 *- récupérer les saisies clavier de l'utilisateur
 *- afficher le menu
 *- afficher une interface graphique du jeu
 *- afficher les scores et les règles du jeu
 *- consulter et ajouter des meilleurs scores autant pour le jeu Classique que le Montagnard
*/

class IHM {

  public :
  /*! \fn static int getinput()
  * \brief Récupère les données saisies par l'utilisateur sur le clavier
  * \return l'entier correspondant au caractère tapé
  */
  static int getinput();
  /*! \fn static void afficher(Board b, Piece *PieceEnCours, Piece *PieceStockee, Piece *PieceSuivante, int Score, bool Pause)
  * \brief Affiche l'interface graphique du Tetris Classique en fonction de l'état courant du jeu
  * \param b est la grille de jeu
  * \param *PieceEnCours est le pointeur sur la Pièce actuellement en train de descendre le long de la grille de jeu
  * \param *PieceStockee est le pointeur sur la Pièce actuellement stockée par le joueur
  * \param *PieceSuivante est le pointeur sur la prochaine Pièce à descendre le long de la grille de jeu
  * \param Score est le score actuel du joueur en points
  * \param bool est le booleen qui permet de savoir si on affiche le jeu, ou si on affiche un message de pause
  */
  static void afficher(Board b, Piece *PieceEnCours, Piece *PieceStockee, Piece *PieceSuivante, int Score, bool pause);
  /*! \fn static void afficher(Board b, Piece *PieceEnCours, Piece *PieceStockee, Piece *PieceSuivante, int Score, bool pause,Personnage p)
  * \brief Affiche l'interface graphique du Tetris Montagnard en fonction de l'état courant du jeu
  * \param b est la grille de jeu
  * \param *PieceEnCours est le pointeur sur la Pièce actuellement en train de descendre le long de la grille de jeu
  * \param *PieceStockee est le pointeur sur la Pièce actuellement stockée par le joueur
  * \param *PieceSuivante est le pointeur sur la prochaine Pièce à descendre le long de la grille de jeu
  * \param Score est le score actuel du joueur en millisecondes
  * \param bool est le booleen qui permet de savoir si on affiche le jeu, ou si on affiche un message de pause
  * \param p est le Personnage du Tetris Montagnard
  */
  static void afficher(Board b, Piece *PieceEnCours, Piece *PieceStockee, Piece *PieceSuivante, int Score, bool pause, Personnage p);
  /*! \fn static void menu();
  * \brief Affiche le menu d'accueil de notre application
  */
  static void menu();
  /*! \fn static void score();
  * \brief Affiche tous les meilleurs scores (Jeu Classique et Jeu Montagnard)
  */
  static void score();
  /*! \fn static void reglesduJeu();
  * \brief Affiche les règles du jeu
  */
  static void reglesduJeu();
  /*! \fn static void ScoreClassique();
  * \brief Affiche les meilleurs scores des parties classiques
  */
  static void ScoreClassique();
  /*! \fn static void ScoreMontagnard();
  * \brief Affiche les meilleurs scores des parties montagnardes
  */
  static void ScoreMontagnard();
  /*! \fn static int MeilleurScoreClassique(int s)
  * \brief Récupère le sième meilleure score des parties classiques
  * \param s le numéro du score que l'on veut afficher, doit être compris entre 1 et 5
  * \return Retourne le sième meilleure score des parties classiques
  */
  static int MeilleurScoreClassique(int);
  /*! \fn static int MeilleurScoreMontagnard(int s)
  * \brief Récupère le sième meilleure score des parties montagnardes
  * \param s le numéro du score que l'on veut afficher, doit être compris entre 1 et 5
  * \return Retourne le sième meilleure score des parties montagnardes
  */
  static int MeilleurScoreMontagnard(int s);



};

#endif
