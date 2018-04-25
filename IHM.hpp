#ifndef __IHM_HPP__
#define __IHM_HPP__
#include <iostream>

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
 *- afficher le Menu
 *- afficher une interface graphique du jeu
 *- afficher les Score et les règles du jeu
 *- consulter et ajouter des meilleurs Score autant pour le JeuClassique que le JeuMontagnard
*/

class IHM {

  public :
  /*! \fn static int getinput()
  * \brief Récupère les données saisies par l'utilisateur sur le clavier
  * \return l'entier correspondant au caractère tapé
  */
  static int getinput();
  /*! \fn static void afficher(Jeu j)
  * \brief Affiche l'état courant du Jeu
  */
  static void afficher(Jeu j);
    /*! \fn static void menu();
  * \brief Affiche le Menu d'accueil de notre application
  */
  static void menu();
  /*! \fn static void score();
  * \brief Affiche tous les meilleurs Score (JeuClassique et JeuMontagnard)
  */
  static void score();
  /*! \fn static void reglesduJeu();
  * \brief Affiche les règles du jeu
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



};

#endif
