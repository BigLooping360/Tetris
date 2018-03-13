#include <iostream>
#include "Jeu.hpp"
#include <string>
#include <time.h>
using namespace std;

void Jeu::init(){
  b.init();
  jeu=true;
  b.init();
  PieceEnCours;
  PieceStocke;
  cout<<b<<endl;
}

void Jeu::MaJ(){
  //On intègre la pièce en cours bloqué dans le Board b
  for (int i = 0; i < 4; i++) {
    b.setGrille(PieceEnCours.getPosx(i), PieceEnCours.getPosy(i));
  }
  //On vérifie pour toutes les lignes qu'il n'y a pas de ligne formé
  for (int i = 0; i < b.getHauteur(); i++) {
    bool LigneCompletee=true;
    for (int j = 0; j < b.getLargeur(); j++) {
      if (b.getGrille(j,i)==0){
        LigneCompletee=false;
      }
    }
    //Si la ligne en question est complétée :
    if (LigneCompletee){
      //On vide la Ligne en question
      for (int j = 0; j < b.getLargeur(); j++)
        b.setGrille(j,i);
      //Puis on fait tomber tous les autres blocs d'une case :
      for (int k = i+1; k < b.getHauteur(); k++) {
        for (int j = 0; j < b.getLargeur(); j++)
          if (b.getGrille(j,k)==1){
            //On vide la case
            b.setGrille(j,k);
            //On remplit la case du dessous qui est forcément vide
            b.setGrille(j,k-1);
          }

      }
    }

  }
}
// Envoie l'ordre de bouger une pièce, renvoie true si une pièce est bougé
void Jeu::Move(char c){
  if (c=='q')
    PieceEnCours.MoveLeft(b);
  if (c=='d')
    PieceEnCours.MoveRight(b);
  if (c=='s')
    PieceEnCours.MoveDown(b);
}


void Jeu::play(){
  /*Test LigneCompletee
  for (int i = 0; i < b.getLargeur(); i++) {
    if (i!=4)
      b.setGrille(i,0);
  }
  for (int i = 0; i < b.getLargeur(); i++) {
    if (i!=4)
      b.setGrille(i,3);
  }*/

  while (jeu) {
    clock_t temps=clock();
    while (PieceEnCours.getbloque()==false) {
        if (clock()-temps>(CLOCKS_PER_SEC/6)){
            PieceEnCours.afficher(b);
            PieceEnCours.MoveDown(b);
            temps=clock();
          }
        //If Keypressed d,q,s blabla
        char c='u';
        Move(c);
        }
      MaJ();
      PieceEnCours=PieceStocke;
    }
}
