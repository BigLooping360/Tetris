#include <iostream>
#include "Piece.hpp"
#include <string>
#include<vector>

using namespace std;
//Initialise la piece à une certaine position
Piece::Piece():tab(5,Bloc(0,0)) {

  for (int i = 0; i < 4; i++) {
    tab[i] = Bloc(4,19-i);
    cout<<tab[i].getPosx()<<endl;
    cout<<tab[i].getPosy()<<endl;
  }
  bloque=false;
}

//Note : les getters et setters utilisent aussi ceux de bloc

//Retourne la position x du bloc i
int Piece::getPosx(int i)const{
    return tab[i].getPosx();
  }

//Retourne la position y du bloc i
int Piece::getPosy(int i)const{
  return tab[i].getPosy();
}

// //Prend la ième pièce et modifie sa position x ou y en j
void Piece::setPosx(int i,int j){
  tab[i].setPosx(j);
}

void Piece::setPosy(int i, int j){
  tab[i].setPosy(j);FILE *fp;
}

bool Piece::getbloque(){
  return bloque;
}



//Regarde si il n'y a pas un bloc en-dessous duquel il y a un bloc;
bool Piece::Down(Board b){
  for (int i = 0; i < 4; i++) {
    if ((b.getGrille(getPosx(i), getPosy(i)-1)==1) or (getPosy(i)==0))
      return false;
    }
  return true;
}

bool Piece::Left(Board b){
  for (int i = 0; i < 4; i++) {
    if ((b.getGrille(getPosx(i)-1, getPosy(i))==1) or (getPosx(i)==0))
      return false;
    }
  return true;
}

bool Piece::Right(Board b){
  for (int i = 0; i < 4; i++) {
    if ((b.getGrille(getPosx(i)+1, getPosy(i))==1) or (getPosx(i)==9))
      return false;
    }
  return true;
}

//Affiche la grille avec la piève en question, à remplacer. Notamment à
//cause du 20 et 10 qui représentent respectivement la hauteur et la
//largeur qui sont privés.. Résoudre le problème des références
void Piece::afficher(Board b){
  Board b2;
  b2.init();
  for (int i = 0; i < b.getHauteur(); i++) {
    for (int j = 0; j < b.getLargeur(); j++) {
      if (b2.getGrille(j,i)!=b.getGrille(j,i)) {
        b2.setGrille(j,i);
        }
      }
    }
  for (int i = 0; i < 4; i++) {
    b2.setGrille(getPosx(i), getPosy(i));
  }
  cout<<b2<<endl;
  }


//Si la pièce peut descendre on la fait descendre, si elle se bloque
//on change la valeur du booléen bloque

void Piece::MoveDown(Board b){
  //On check si une fois que l'on baisse la pièce elle se retrouve coincée
  if (Down(b)==false)
    bloque=true;
  else
    for (int i = 0; i < 4; i++) {
      setPosy(i,tab[i].getPosy()-1);
    }

}
void Piece::MoveRight(Board b){
    if (Right(b))
      for (int i = 0; i < 4; i++) {
        setPosx(i,tab[i].getPosx()+1);
        }
    }
 void Piece::MoveLeft(Board b){
        if (Left(b))
          for (int i = 0; i < 4; i++) {
            setPosx(i,tab[i].getPosx()-1);
            }


        }
