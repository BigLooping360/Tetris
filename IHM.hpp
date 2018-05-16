#ifndef __IHM_HPP__
#define __IHM_HPP__
#include <iostream>
#include <ncurses.h>

#include "Jeu.hpp"
#include "JeuClassique.hpp"
#include "JeuMontagnard.hpp"


#include<vector>
using namespace std;

/*! \class IHM
 * \brief Gère les interactions entre les actions du joueur et le jeu à proprement parler
 * \author Laura Couret
 * \author Victor Le Maistre
 * \version 1.0
 * \date mai 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module va permettre de :
 *- récupérer les saisies clavier de l'utilisateur
 *- afficher le Menu
 *- afficher une interface graphique du Jeu
 *- afficher les Score et les règles du Jeu
 *- demande à un joueur de rentrer un pseudo lorsqu'il a gagné
*/

class IHM {

  public :
  /*! \fn void Pause()
  * \brief Affiche l'écran de Pause du Jeu
  */
  static void Pause();
  /*! \fn static int getinput()
  * \brief Récupère les données saisies par l'utilisateur sur le clavier
  * \return l'entier correspondant au caractère tapé
  */
  static int getinput();
  /*! \fn static void init()
  * \brief initialise l'écran
  */
  static void init();
  /*! \fn static void fin()
  * \brief désactive lncurses et l'écran pour rendre le terminal réutilisable
  */
  static void fin();
  /*! \fn static void afficher(JeuClassique j)
  * \brief Affiche l'état courant du Jeu Classique
  */
  static void afficher(JeuClassique j);
  /*! \fn static void afficher(JeuMontagnard j)
  * \brief Affiche l'état courant du Jeu Montagnard
  */
  static void afficher(JeuMontagnard j);
    /*! \fn static void menu();
  * \brief Affiche le Menu d'accueil de notre application
  */
  static void menu();
  /*! \fn static void reglesduJeu();
  * \brief Affiche les règles du Jeu
  */
  static void reglesduJeu();
  /*! \fn static void ScoreClassique();
  * \brief Affiche les meilleurs Score de JeuClassique
  */
  static void ScoreClassique();
  /*! \fn static void ScoreMontagnard();
  * \brief Affiche les meilleurs Score de JeuMontagnard
  */
  static void ScoreMontagnard();
  /*! \fn static int MeilleurScoreClassique(int s)
  * \brief Récupère le sième meilleure Score des JeuClassique
  * \param s le numéro du Score que l'on veut afficher, doit être compris entre 1 et 5
  * \return Retourne le sième meilleure Score des JeuClassique
  */
  static int MeilleurScoreClassique(int);
  /*! \fn static int MeilleurScoreMontagnard(int s)
  * \brief Récupère le sième meilleure Score des JeuMontagnard
  * \param s le numéro du Score que l'on veut afficher, doit être compris entre 1 et 5
  * \return Retourne le sième meilleure Score des JeuMontagnard
  */
  static float MeilleurScoreMontagnard(int s);
  /*! \fn static string getPseudoGagnant()
  * \brief Demande au joueur courant de rentrer un pseudo
  * \return Retourne le pseudo choisi par le joueur
  */
  static string getPseudoGagnant();



};

#endif
