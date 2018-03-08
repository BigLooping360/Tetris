#include <iostream>
#include "Board.hpp"
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

//Initialise la grille en mettant des 1 sur les bordures
// et des 0 sinon
void Board::init(){
  for (int i = 0; i < Hauteur; i++) {
    for (int j = 0; j < Largeur; j++) {
      if ((i==0) or (j==0) or (j==Largeur-1))
        Grille[j][i]=1;
      else
        Grille[j][i]=0;
      }
    }
  }

/* Permet d'afficher la grille sur un terminal, affiche un x
lorsque la grille comprend un 1, et affiche 0 sinon
*/
ostream &operator<<(ostream &out, Board &b) { //ici
  for (int i = b.getHauteur()-1; i>=0; i--) {
    for (int j = 0; j < b.getLargeur(); j++) {
      if (b.getGrille(j,i)==1)
        cout<<"x";
      else
        cout<<" ";
      }
    std::cout <<'\n';
    }
  }
