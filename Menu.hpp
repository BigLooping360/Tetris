#ifndef __Menu_HPP__
#define __Menu_HPP__
#include "Jeu.hpp"
#include "IHM.hpp"
#include <time.h>
#include <ncurses.h>
#include<stdlib.h>


using namespace std;


class Menu {
private:
  Jeu Jeu1;


public:
  void lancement();
  void jouerClassique();

};

#endif
