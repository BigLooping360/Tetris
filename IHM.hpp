#ifndef __IHM_HPP__
#define __IHM_HPP__
#include <iostream>
#include "Jeu.hpp"


#include<vector>
using namespace std;

class IHM {
  public :
  static int getinput();
  static void afficher(Jeu j);
  //static void afficher(Board b, Piece *PieceEnCours, Piece *PieceStocke, Piece *PieceSuivante, int Score, bool pause, Personnage p);
  static void menu();
  static void score();
  static void reglesduJeu();
  static void ScoreClassique();
  static void ScoreMontagnard();
  static void MeilleurScoreClassique(int);
  static void MeilleurScoreMontagnard(int);



};

#endif
