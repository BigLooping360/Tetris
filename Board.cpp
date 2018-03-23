#include "Board.hpp"
#include <iostream>
#include <string>
using namespace std;

int Board::getHauteur()const{
  return Hauteur;
}

int Board::getLargeur()const{
  return Largeur;
}

int Board::getGrille(int x, int y)const{
  return Grille[x][y];
}
//Change la valeur de la Grille x,y
void Board::setGrille(int x, int y){
  if (Grille[x][y]==1)
  Grille[x][y]=0;
  else
  Grille[x][y]=1;
}

//Initialise la grille en mettant des 0 partout
void Board::init(){
  for (int i = 0; i < Hauteur; i++) {
    for (int j = 0; j < Largeur; j++) {
      Grille[j][i]=0;
      }
    }
  }

/* Permet d'afficher la grille sur un terminal, affiche un x
lorsque la grille comprend un 1, et affiche 0 sinon
*/
ostream &operator<<(ostream &out, Board &b) { //ici
  for (int i = b.getHauteur(); i>=-1; i--) {
    for (int j = -1; j <= b.getLargeur(); j++) {
      if ( (i==b.getHauteur()) or (i==-1) or (j==-1) or (j==b.getLargeur()))
        cout<<"x";
      else{
        if (b.getGrille(j,i)==1)
          cout<<"x";
        else
          cout<<" ";
        }
      }
    std::cout <<'\n';
    }
  }
