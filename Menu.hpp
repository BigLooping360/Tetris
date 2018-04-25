#ifndef __Menu_HPP__
#define __Menu_HPP__
#include "Jeu.hpp"
#include "JeuClassique.hpp"
#include "JeuMontagnard.hpp"
#include "Score.hpp"
#include "IHM.hpp"
#include <time.h>
#include <ncurses.h>
#include<stdlib.h>

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
  /*! /var jeuc est le JeuClassique du Tetris qui sera lancé à la demande de l'utilisateur*/
  JeuClassique jeuc;
  /*! /var jeum est le JeuMontagnard du Tetris qui sera lancé à la demande de l'utilisateur*/
  JeuMontagnard jeum;
  /*! /var scoreclassique est ce qui servira à gérer les Score de l'utilisateur pour le JeuClassique*/
  Score scoreclassique;
  /*! /var scoreM est ce qui servira à gérer les Score de l'utilisateur pour le JeuMontagnard*/
  Score scoreM;

public:
  /*! \fn void lancement()
  * \brief
  * \param
  */
  void lancement();
  void jouer();
  void ConsulterRegles();
  void ConsulterScore();
  void Quitter();

};

#endif
