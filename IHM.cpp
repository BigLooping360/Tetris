#include "IHM.hpp"
#include <iostream>
#include <ncurses.h>


using namespace std;

int IHM::getinput(){
  return getch();
}


void IHM::afficher(Jeu Jeu1){
  clear();
  //On affiche le board
  for (int i = 0; i<Jeu1.b.getHauteur(); i++)
    for (int j = 0; j <= Jeu1.b.getLargeur(); j++)
      if (Jeu1.b.getGrille(j,i)==1)
        mvaddch(Jeu1.b.getHauteur()-i-1,j+1,'x');
  //On affiche la bordure
  for (int i=0; i<Jeu1.b.getHauteur();i++){
    mvaddch(i,0,'x');
    mvaddch(i,Jeu1.b.getLargeur()+1,'x');
  }
  for (int i=0; i<Jeu1.b.getLargeur()+2;i++){
    mvaddch(Jeu1.b.getHauteur(),i,'x');
  }
  //On affiche la pièce
  for (int i = 0; i < 4; i++) {
    mvaddch(Jeu1.b.getHauteur()-Jeu1.PieceEnCours->getPosy(i)-1,Jeu1.PieceEnCours->getPosx(i)+1,'x');
  }

}
