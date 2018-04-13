#include "Jeu.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <ncurses.h>
#include<stdlib.h>

using namespace std;


void Jeu::init(){

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
  }

  cout<<b<<endl;
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
  }
}
// Envoie l'ordre de bouger une pièce, renvoie true si une pièce est bougé
void Jeu::move(int c){
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


void Jeu::afficher(){
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
    initscr();
    noecho();
    keypad(stdscr,TRUE);
    //cbreak();
    nodelay(stdscr, TRUE);

    clock_t temps=clock();
    while (PieceEnCours->getbloque()==false) {
        if (clock()-temps>(CLOCKS_PER_SEC/2)){
            PieceEnCours->MoveDown(b);
            temps=clock();
          }
        int n=getch();
        if (n!=-1)
          move(n);
        afficher();
        refresh();
        }
      MaJ();
    }
    endwin();
}
