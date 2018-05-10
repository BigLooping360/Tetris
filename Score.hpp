#ifndef __Score_HPP__
#define __Score_HPP__
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;


/*! \class Score
 * \brief Gestion des meilleurs Score des joueurs
 * \author Laura Couret
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet la gestion des meilleurs Score. Plus particulièrement, on pourra
 *consulter les meilleurs Score déjà réalisés, et en ajouter un nouveau si nécessaire.
*/

class Score {

  protected:
  /*! /var nomfichier est le nom du fichier où seront stockés les meilleurs Score réalisés*/
  string nomfichier;

  public:
  /*! \fn Score(string ch)
  * \brief Constructeur d'un Score
  * \param ch est le nom du fichier de Score à créer (un pour JeuClassique, un pour JeuMontagnard)
  */
  Score(string ch);
  /*! \fn string getNomfichier()
  * \brief Accesseur du nom du fichier correspondant au type de jeu
  * \return "classique.txt" si JeuClassique, "montagnard.txt" si JeuMontagnard
  */
  string getNomfichier();
  /*! \fn addscore(int s)
  * \brief Ajoute un nouveau Score au fichier des meilleurs Score
  * \param s est le Score réalisé à ajouter
  */
  void addscore(int s,string pseudo);
  /*! \fn bool meilleurescore(int s)
  * \brief Vérifie si un joueur peut rentrer dans le palmares des 5 meilleurs Score
  * \param s est le Score réalisé à comparer avec ceux déjà réalisé
  * \return true s'il s'agit d'un nouveau meilleur Score, false sinon
  */
  bool meilleurescore(int s);

};

#endif
