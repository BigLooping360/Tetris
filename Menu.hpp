#ifndef __Menu_HPP__
#define __Menu_HPP__
#include "Jeu.hpp"
#include "Score.hpp"
#include "JeuClassique.hpp"
#include "JeuMontagnard.hpp"
#include "IHM.hpp"
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string>

using namespace std;

/*! \class Menu
 * \brief Menu de notre application permettant la redirection vers toutes nos fonctionnalités
 * \author Léa Lefrançois
 * \author Laura Couret
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
*/

class Menu {

private:
  /*! jeuc est le JeuClassique du Tetris qui sera lancé à la demande de l'utilisateur*/
  JeuClassique jeuc;
  /*! jeum est le JeuMontagnard du Tetris qui sera lancé à la demande de l'utilisateur*/
  JeuMontagnard jeum;

  /*! scoreC est ce qui servira à gérer les Score pour le JeuClassique*/
  Score scoreC;
  /*! scoreM est ce qui servira à gérer les Score pour le JeuMontagnard*/
  Score scoreM;

public:

  /*! \fn void lancement()
  * \brief Correspond au main de l'application (lance notre application)
  */
  void lancement();
  /*! \fn void jouerClassique()
  * \brief Lance une partie de Tetris Classique
  */
  void jouerClassique();
  /*! \fn void jouerMontagnard()
  * \brief Lance une partie de Tetris Montagnard
  */
  void jouerMontagnard();
  /*! \fn void ConsulterRegles()
  * \brief Lance la consultation des règles du JeuClassique et du JeuMontagnard
  */
  void ConsulterRegles();
  /*! \fn void ConsulterScoreClassique()
  * \brief Lance la consultation des scores du Tetris JeuClassique
  */
  void ConsulterScoreClassique();
  /*! \fn void ConsulterScoreMontagnard()
  * \brief Lance la consultation des scores du Tetris JeuMontagnard
  */
  void ConsulterScoreMontagnard();
  /*! \fn void Quitter()
  * \brief Lance la fermeture du terminal, quitte notre application
  */
  void Quitter();

};

#endif
