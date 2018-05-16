#include "JeuMontagnard.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

JeuMontagnard::JeuMontagnard(Board b1):Jeu(){
  b=b1;
p=Personnage();

}
JeuMontagnard::JeuMontagnard():Jeu(){
  temps=0;
  p=Personnage();
  srand(time(NULL));
}


float JeuMontagnard::getTemps(){
  return temps;
}

void JeuMontagnard::MaJ(){

  for (size_t i = 0; i < 4; i++) {
    if ((PieceEnCours->getPosy(i)==p.getPosy()) and (PieceEnCours->getPosx(i)==p.getPosx()) )
      p.setbloque();
  }


  //On check si le personnage n'est pas arrivé tout en haut
  if (p.getPosy()==19) {
    jeu=false;
    clock_t sec = clock();
    temps = ((float) sec/CLOCKS_PER_SEC);
  }


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
      //On vérifie si le personnage n'est pas libéré :
      if ((i==p.getPosy()) and (b.getGrille(p.getPosx(),p.getPosy())==0))
        p.setbloque();
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

    case 6:
      PieceEnCours= new Piece_S();
      break;

    case 7:
      PieceEnCours= new Piece_Z();
      break;

  }
  *PieceEnCours=*PieceSuivante;
  //On check que la nouvelle pièce peut bien s'intégrer dans le board :
  for (size_t i = 0; i < 4; i++) {
    if (b.getGrille(PieceEnCours->getPosx(i),PieceEnCours->getPosy(i))==1)
      jeu=false;
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
  //On vérifie que le personnage a toujours un bloc en dessous de lui sinon
  //on le fait tomber :
  if (b.getGrille(p.getPosx(),p.getPosy()-1)==0)
    while ((b.getGrille(p.getPosx(),p.getPosy()-1)==0) and (p.getPosy()>=1))
      p.setPosy(p.getPosy()-1);



}

Personnage JeuMontagnard::getPersonnage(){
  return p;
}

void JeuMontagnard::DeplacerPersonnage(){
  p.Deplacement(b);
}
