#ifndef __IHM_HPP__
#define __IHM_HPP__
#include <iostream>
<<<<<<< HEAD
#include "Jeu.hpp"


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

  static void afficher(Jeu j);

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
