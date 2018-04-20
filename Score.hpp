#ifndef __Score_HPP__
#define __Score_HPP__

using namespace std;

/*! \class Score
 * \brief Gestion des meilleurs scores des joueurs
 * \author Laura Couret
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet la gestion des meilleurs scores. Plus particulièrmeent, on pourra
 *consulter les meilleurs scores déjà réalisés, et en ajouter un nouveau si nécessaire.
*/

class Score {

  private:
  /*! /var nomfichier est le nom du fichier où seront stockés les meilleurs scores réalisés*/
  string nomfichier;

  public:
  /*! \fn Score(string ch)
  * \brief Constructeur d'un Score
  * \param ch est le nom du fichier de score à créer (un pour la version classiquen, un pour la version montagnarde)
  */
  Score(string ch);
  /*! \fn addscore(int s)
  * \brief Ajoute un nouveau score au fichier des meilleurs scores
  * \param s est le score réalisé à ajouter
  */
  void addscore(int s);
  /*! \fn bool meilleurescore(int s)
  * \brief Vérifie si un joueur peut rentrer dans le palmares des 5 meilleurs scores
  * \param s est le score réalisé à comparer avec ceux déjà réalisé
  * \return true s'il s'agit d'un nouveau meilleur score, false sinon
  */
  bool meilleurescore(int s);

};

#endif
