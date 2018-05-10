#include "Jeu.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>

using namespace std;


Jeu::Jeu(){

  srand(time(NULL));
  nombre_aleatoire=rand()%(NombreDePieces-a) +a;
  b=Board();
  jeu=true;
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

    case 6:
      PieceEnCours= new Piece_S();
      break;

    case 7:
      PieceEnCours= new Piece_Z();
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

    case 6:
      PieceSuivante= new Piece_S();
      break;

    case 7:
      PieceSuivante= new Piece_Z();
      break;
  }
  PieceStocke=NULL;
}


int Jeu::MaJPiece(){
  //On check que la pièce ne bloquera pas l'entrée de la nouvelle pièce
  for (size_t i = 0; i < 4; i++) {
    if ( ((PieceEnCours->getPosx(i)==4) or (PieceEnCours->getPosx(i)==5) or (PieceEnCours->getPosx(i)==6)) and (PieceEnCours->getPosy(i)==19))
      jeu=false;
  }

  //On intègre la pièce en cours bloqué dans le Board b
  for (int i = 0; i < 4; i++) {
    b.setGrille(PieceEnCours->getPosx(i), PieceEnCours->getPosy(i));
  }

  int nb_ligneCompletee=0;
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
      nb_ligneCompletee++;
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
  // PieceCours prend la valeur de PieceStocke
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

    case 6:
      PieceEnCours= new Piece_S();
      break;

    case 7:
      PieceEnCours= new Piece_Z();
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

    case 6:
      PieceSuivante= new Piece_S();
      break;

    case 7:
      PieceSuivante= new Piece_Z();
      break;
  }

  return nb_ligneCompletee;

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
  if ((char)c=='o')
    stocker();

}
void Jeu::stocker(){
  if (!PieceEnCours->getstocke()){
    if (PieceStocke!=NULL){
        // On a besoin d'intervertir les deux pièces, PieceX sera l'intermédiare
        Piece *PieceX;
        // On détermine tout d'abord le type de PieceX qui prendra la valeur de PieceEnCours
        switch (PieceEnCours->getcolor()) {
          case 1:
            PieceX = new Piece_I();
            break;

          case 2:
            PieceX= new Piece_O();
            break;

          case 3:
            PieceX= new Piece_T();
            break;

          case 4:
            PieceX= new Piece_L();
            break;

          case 5:
            PieceX= new Piece_J();
            break;

          case 6:
            PieceX= new Piece_S();
            break;

          case 7:
            PieceX= new Piece_Z();
            break;
        }
        *PieceX=*PieceEnCours;
        // On transmet maintenant PieceStocke à PieceEnCours
        switch (PieceStocke->getcolor()) {
          case 1:
            PieceEnCours = new Piece_I();
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

          case 6:
            PieceEnCours= new Piece_S();
            break;

          case 7:
            PieceEnCours= new Piece_Z();
            break;
        }
        *PieceEnCours=*PieceStocke;
        //Et on met maintenant à jour PieceStocke
        switch (PieceX->getcolor()) {
          case 1:
            PieceStocke = new Piece_I();
            break;

          case 2:
            PieceStocke = new Piece_O();
            break;

          case 3:
            PieceStocke = new Piece_T();
            break;

          case 4:
            PieceStocke = new Piece_L();
            break;

          case 5:
            PieceStocke = new Piece_J();
            break;

          case 6:
            PieceStocke = new Piece_S();
            break;

          case 7:
            PieceStocke = new Piece_Z();
            break;
        }



    }
    else{
      //On stocke la pièce
      switch (PieceEnCours->getcolor()) {
        case 1:
          PieceStocke = new Piece_I();
          break;

        case 2:
          PieceStocke= new Piece_O();
          break;

        case 3:
          PieceStocke= new Piece_T();
          break;

        case 4:
          PieceStocke= new Piece_L();
          break;

        case 5:
          PieceStocke= new Piece_J();
          break;

        case 6:
          PieceStocke= new Piece_S();
          break;

        case 7:
          PieceStocke= new Piece_Z();
          break;
      }

      //On passe la piece suivante en tant que piece en cours
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

        case 6:
          PieceEnCours= new Piece_S();
          break;

        case 7:
          PieceEnCours= new Piece_Z();
          break;

      }
      //On détermine la prochaine pièce
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

        case 6:
          PieceSuivante= new Piece_S();
          break;

        case 7:
          PieceSuivante= new Piece_Z();
          break;
      }

    }
    PieceStocke->setstocke();
  }



}
bool Jeu::getjeu()const{
  return jeu;
}

bool Jeu::getstatut(){
  return PieceEnCours->getbloque();
}
