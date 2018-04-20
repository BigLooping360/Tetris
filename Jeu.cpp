#include "Jeu.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <ncurses.h>
#include<stdlib.h>

using namespace std;


Jeu::Jeu(){

  srand(time(NULL));
  nombre_aleatoire=rand()%(NombreDePieces-a) +a;
  b.init() ;
  jeu=true;
  b.init();
  switch (nombre_aleatoire) {
    case 1:
      PieceEnCours= new Piece_I();
      break;

    case 2:
      PieceEnCours= new Piece_T();
      break;

    case 3:
      PieceEnCours= new Piece_O();
      break;

    case 4:
      PieceEnCours= new Piece_L();
      break;

    case 5:
      PieceEnCours= new Piece_J();
      break;
  }
  nombre_aleatoire=rand()%(NombreDePieces-a) +a;

  switch (nombre_aleatoire) {
    case 1:
      PieceSuivante= new Piece_I();
      break;

    case 2:
      PieceSuivante= new Piece_T();
      break;

    case 3:
      PieceSuivante= new Piece_O();
      break;

    case 4:
      PieceSuivante= new Piece_L();
      break;

    case 5:
      PieceSuivante= new Piece_J();
      break;


  }

}


void Jeu::MaJ(){

  //On intègre la pièce en cours bloqué dans le Board b
  for (int i = 0; i < 4; i++) {
    b.setGrille(PieceEnCours->getPosx(i), PieceEnCours->getPosy(i));
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
      //On décrémente ensuite i pour que la même ligne soit recheck
      i--;
    }


  }
  // PieceCours prend la valeur de PieceStockee
  switch (PieceSuivante->getcolor()) {
    case 1:
      PieceEnCours= new Piece_I();
      break;

    case 2:
      PieceEnCours= new Piece_O();
      break;

    case 3:
      PieceEnCours= new Piece_T();
      break;

    case 4:
      PieceEnCours= new Piece_L();
      break;

    case 5:
      PieceEnCours= new Piece_J();
      break;

  }
  *PieceEnCours=*PieceSuivante;

  nombre_aleatoire=rand()%(NombreDePieces-a) +a;
  switch (nombre_aleatoire) {
    case 1:
      PieceSuivante= new Piece_I();
      break;

    case 2:
      PieceSuivante= new Piece_T();
      break;

    case 3:
      PieceSuivante= new Piece_O();
      break;

    case 4:
      PieceSuivante= new Piece_L();
      break;

    case 5:
      PieceSuivante= new Piece_J();
      break;
  }
}
// Envoie l'ordre de bouger une pièce, renvoie true si une pièce est bougé
void Jeu::interaction(int c){
  if (((char)c=='q') or (c==KEY_LEFT))
    PieceEnCours->MoveLeft(b);
  if (((char)c=='d') or (c==KEY_RIGHT))
    PieceEnCours->MoveRight(b);
  if (((char)c=='s') or (c==KEY_DOWN))
    PieceEnCours->MoveDown(b);
  if (((char)c==' ') or (c==KEY_UP))
    while(!PieceEnCours->getbloque())
      PieceEnCours->MoveDown(b);
  if ((char)c=='r')
    PieceEnCours->Rotate(b);
}

bool Jeu::getjeu()const{
  return jeu;
}

bool Jeu::getstatut(){
  return PieceEnCours->getbloque();
}
