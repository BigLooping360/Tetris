#include "IHM.hpp"
#include <iostream>
#include <ncurses.h>


using namespace std;

int IHM::getinput(){
  return getch();
}


void IHM::afficher(Board b, Piece *PieceEnCours, Piece *PieceStocke, Piece *PieceSuivante, int Score, bool Pause){
  clear();
  //On affiche le board
  for (int i = 0; i<b.getHauteur(); i++)
    for (int j = 0; j <= b.getLargeur(); j++)
      if (b.getGrille(j,i)==1)
        mvaddch(b.getHauteur()-i-1,j+1,'x');
  //On affiche la bordure
  for (int i=0; i<b.getHauteur();i++){
    mvaddch(i,0,'x');
    mvaddch(i,b.getLargeur()+1,'x');
  }
  for (int i=0; i<b.getLargeur()+2;i++){
    mvaddch(b.getHauteur(),i,'x');
  }
  //On affiche la pièce
  for (int i = 0; i < 4; i++) {
    mvaddch(b.getHauteur()-PieceEnCours->getPosy(i)-1,PieceEnCours->getPosx(i)+1,'x');
  }

}
