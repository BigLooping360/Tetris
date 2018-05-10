#include "IHM.hpp"
#include <iostream>
#include <vector>
#include <ncurses.h>
#include <string.h>
#include <fstream>
#include <string>


using namespace std;

int IHM::getinput(){
  return getch();
}

string IHM::getPseudoGagnant() {

  clear();
  char *msg1 = "Gagné ! Vous pouvez entrer votre pseudo pour rentrer dans le palmares de nos meilleurs joueurs : ";
  string nom;
  int taille1 = strlen(msg1);
  attron(A_DIM | A_BOLD);
  mvprintw(25, (COLS / 2) - (taille1 / 2), msg1);
  cin >> nom;
  return nom;


}

void IHM::reglesduJeu() {

  clear();

  int inter=-1;
  int i=2;
  char *msg1 = "Les règles du Tetris";
  int taille1 = strlen(msg1);
  attron(A_DIM | A_BOLD);
  mvprintw(0, (COLS / 2) - (taille1 / 2), msg1);

  ifstream f("regles.txt",ios::in);
  if (f) {
    string ligne;
      while(getline(f, ligne)) {
        mvprintw(i,5,ligne.c_str());
        i=i+2;
      }
  }
  f.close();
  mvprintw(i+2,2,"Appuyer sur Entrée pour revenir au menu principal");

  while (inter!=(char)'\n') {
    inter=IHM::getinput();
  }

  IHM::menu();

}


void IHM::init(){
  initscr();
  noecho();
  keypad(stdscr,TRUE);
  //cbreak();
  nodelay(stdscr, TRUE);
  start_color();			/* Start color 			*/
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_CYAN, COLOR_BLACK);

}

void IHM::fin(){
  endwin();
}

void IHM::menu(){
  clear();
  char *msg1 = "TETRIS";
  char *msg2 = "par Victor LE MAISTRE, Laura COURET et Léa LEFRANCOIS";
  char *msg3 = "Appuyer sur la touche :";
  char *choix1 = "1 pour Jouer au Tetris Classique";
  char *choix2 = "2 pour Jouer au Tetris Montagnard";
  char *choix3 = "3 pour consulter les meilleurs scores du Tetris Classique";
  char *choix4 = "4 pour consulter les meilleurs scores du Tetris Montagnard";
  char *choix5 = "5 pour consulter les règles";
  char *choix6 = "6 pour quitter l'application";
  int taille1= strlen(msg1);
  int taille2= strlen(msg2);
  int taille3= strlen(msg3);
  int taille4= strlen(choix1);
  int taille5= strlen(choix2);
  int taille6= strlen(choix3);
  int taille7= strlen(choix4);
  int taille8 = strlen(choix5);
  int taille9 = strlen(choix6);
  attron(A_DIM | A_BOLD);
  mvprintw(0, (COLS / 2) - (taille1 / 2), msg1);
  attroff(A_DIM | A_BOLD);
  mvprintw(1, (COLS / 2) - (taille2 / 2), msg2);
  mvprintw(4, (COLS / 2) - (taille3 / 2), msg3);
  attron(COLOR_PAIR(4));
  mvprintw(8, (COLS / 2) - (taille4 / 2), choix1);
  attroff(COLOR_PAIR(4));
  attron(COLOR_PAIR(2));
  mvprintw(10, (COLS / 2) - (taille5 / 2), choix2);
  attroff(COLOR_PAIR(2));
  attron(COLOR_PAIR(3));
  mvprintw(12, (COLS / 2) - (taille6 / 2), choix3);
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(5));
  mvprintw(14, (COLS / 2) - (taille7 / 2), choix4);
  attroff(COLOR_PAIR(5));
  attron(COLOR_PAIR(6));
  mvprintw(16, (COLS / 2) - (taille8 / 2), choix5);
  attroff(COLOR_PAIR(2));
  attron(COLOR_PAIR(4));
  mvprintw(18, (COLS / 2) - (taille9 / 2), choix6);
  attroff(COLOR_PAIR(8));

  refresh();


}

void IHM::afficher(JeuClassique Jeu1){
  clear();
  //On affiche le board
  attron(COLOR_PAIR(3));
  for (int i = 0; i<Jeu1.b.getHauteur(); i++)
    for (int j = 0; j <= Jeu1.b.getLargeur(); j++)
      if (Jeu1.b.getGrille(j,i)==1)
        mvaddch(Jeu1.b.getHauteur()-i-1,j+1,'x');
  attroff(COLOR_PAIR(3));
  //On affiche la bordure
  for (int i=0; i<Jeu1.b.getHauteur();i++){
    mvaddch(i,0,'x');
    mvaddch(i,Jeu1.b.getLargeur()+1,'x');
  }
  for (int i=0; i<Jeu1.b.getLargeur()+2;i++){
    mvaddch(Jeu1.b.getHauteur(),i,'x');
  }
  //On affiche la pièce
  switch (Jeu1.PieceEnCours->getcolor()){
    case 1:
      attron(COLOR_PAIR(1));
      for (int i = 0; i < 4; i++) {
        mvaddch(Jeu1.b.getHauteur()-Jeu1.PieceEnCours->getPosy(i)-1,Jeu1.PieceEnCours->getPosx(i)+1,'x');
      }
      attroff(COLOR_PAIR(1));
      break;
    case 2:
      attron(COLOR_PAIR(2));
      for (int i = 0; i < 4; i++) {
        mvaddch(Jeu1.b.getHauteur()-Jeu1.PieceEnCours->getPosy(i)-1,Jeu1.PieceEnCours->getPosx(i)+1,'x');
      }
      attroff(COLOR_PAIR(2));
      break;

    case 3:
      attron(COLOR_PAIR(4));
      for (int i = 0; i < 4; i++) {
        mvaddch(Jeu1.b.getHauteur()-Jeu1.PieceEnCours->getPosy(i)-1,Jeu1.PieceEnCours->getPosx(i)+1,'x');
      }
      attroff(COLOR_PAIR(4));
      break;

    case 4:
      attron(COLOR_PAIR(4));
      for (int i = 0; i < 4; i++) {
        mvaddch(Jeu1.b.getHauteur()-Jeu1.PieceEnCours->getPosy(i)-1,Jeu1.PieceEnCours->getPosx(i)+1,'x');
      }
      attroff(COLOR_PAIR(4));
      break;

    case 5:
      attron(COLOR_PAIR(5));
      for (int i = 0; i < 4; i++) {
        mvaddch(Jeu1.b.getHauteur()-Jeu1.PieceEnCours->getPosy(i)-1,Jeu1.PieceEnCours->getPosx(i)+1,'x');
      }
      attroff(COLOR_PAIR(5));
      break;

    case 6:
      attron(COLOR_PAIR(6));
      for (int i = 0; i < 4; i++) {
        mvaddch(Jeu1.b.getHauteur()-Jeu1.PieceEnCours->getPosy(i)-1,Jeu1.PieceEnCours->getPosx(i)+1,'x');
      }
      attroff(COLOR_PAIR(6));
      break;

    case 7:
      attron(COLOR_PAIR(6));
      for (int i = 0; i < 4; i++) {
        mvaddch(Jeu1.b.getHauteur()-Jeu1.PieceEnCours->getPosy(i)-1,Jeu1.PieceEnCours->getPosx(i)+1,'x');
      }
      attroff(COLOR_PAIR(6));
      break;
  }


}

void IHM::afficher(JeuMontagnard Jeu1){
  clear();
  //On affiche le board
  attron(COLOR_PAIR(3));
  for (int i = 0; i<Jeu1.b.getHauteur(); i++)
    for (int j = 0; j <= Jeu1.b.getLargeur(); j++)
      if (Jeu1.b.getGrille(j,i)==1)
        mvaddch(Jeu1.b.getHauteur()-i-1,j+1,'x');
  attroff(COLOR_PAIR(3));
  //On affiche la bordure
  for (int i=0; i<Jeu1.b.getHauteur();i++){
    mvaddch(i,0,'x');
    mvaddch(i,Jeu1.b.getLargeur()+1,'x');
  }
  for (int i=0; i<Jeu1.b.getLargeur()+2;i++){
    mvaddch(Jeu1.b.getHauteur(),i,'x');
  }
  //On affiche la pièce
  switch (Jeu1.PieceEnCours->getcolor()){
    case 1:
      attron(COLOR_PAIR(1));
      for (int i = 0; i < 4; i++) {
        mvaddch(Jeu1.b.getHauteur()-Jeu1.PieceEnCours->getPosy(i)-1,Jeu1.PieceEnCours->getPosx(i)+1,'x');
      }
      attroff(COLOR_PAIR(1));
      break;
    case 2:
      attron(COLOR_PAIR(2));
      for (int i = 0; i < 4; i++) {
        mvaddch(Jeu1.b.getHauteur()-Jeu1.PieceEnCours->getPosy(i)-1,Jeu1.PieceEnCours->getPosx(i)+1,'x');
      }
      attroff(COLOR_PAIR(2));
      break;

    case 3:
      attron(COLOR_PAIR(3));
      for (int i = 0; i < 4; i++) {
        mvaddch(Jeu1.b.getHauteur()-Jeu1.PieceEnCours->getPosy(i)-1,Jeu1.PieceEnCours->getPosx(i)+1,'x');
      }
      attroff(COLOR_PAIR(3));
      break;

    case 4:
      attron(COLOR_PAIR(4));
      for (int i = 0; i < 4; i++) {
        mvaddch(Jeu1.b.getHauteur()-Jeu1.PieceEnCours->getPosy(i)-1,Jeu1.PieceEnCours->getPosx(i)+1,'x');
      }
      attroff(COLOR_PAIR(4));
      break;

    case 5:
      attron(COLOR_PAIR(5));
      for (int i = 0; i < 4; i++) {
        mvaddch(Jeu1.b.getHauteur()-Jeu1.PieceEnCours->getPosy(i)-1,Jeu1.PieceEnCours->getPosx(i)+1,'x');
      }
      attroff(COLOR_PAIR(5));
      break;

    case 6:
      attron(COLOR_PAIR(6));
      for (int i = 0; i < 4; i++) {
        mvaddch(Jeu1.b.getHauteur()-Jeu1.PieceEnCours->getPosy(i)-1,Jeu1.PieceEnCours->getPosx(i)+1,'x');
      }
      attroff(COLOR_PAIR(6));
      break;

    case 7:
      attron(COLOR_PAIR(6));
      for (int i = 0; i < 4; i++) {
        mvaddch(Jeu1.b.getHauteur()-Jeu1.PieceEnCours->getPosy(i)-1,Jeu1.PieceEnCours->getPosx(i)+1,'x');
      }
      attroff(COLOR_PAIR(6));
      break;
  }

  //On affiche le Personnage
  attron(COLOR_PAIR(4));
  if (Jeu1.getPersonnage().getDirection()==1)
    mvaddch(Jeu1.b.getHauteur()-Jeu1.getPersonnage().getPosy()-1,Jeu1.getPersonnage().getPosx()+1,'p');
  else
    mvaddch(Jeu1.b.getHauteur()-Jeu1.getPersonnage().getPosy()-1,Jeu1.getPersonnage().getPosx()+1,'q');
  attroff(COLOR_PAIR(4));

}


void IHM::ScoreMontagnard() {

  clear();
  int inter=-1;
  int i=3;
  char *msg1 = "Les meilleurs scores pour le Tetris Montagnard sont : ";
  int taille1 = strlen(msg1);
  attron(A_DIM | A_BOLD);
  mvprintw(1, (COLS / 2) - (taille1 / 2), msg1);

  ifstream f("montagnard.txt",ios::in);
  if (f) {
    string ligne;
      while(getline(f, ligne)) {
        ligne+=" secondes";
        mvprintw(i,5,ligne.c_str());
        i=i+2;
      }
  }
  f.close();

  mvprintw(i+2,2,"Appuyer sur Entrée pour revenir au menu principal");
  while (inter!=(char)'\n') {
    inter=IHM::getinput();
  }
  IHM::menu();

}

void IHM::ScoreClassique() {

  clear();
  int inter=-1;
  int i=3;
  char *msg1 = "Les meilleurs scores pour le Tetris Classique sont : ";
  int taille1 = strlen(msg1);
  attron(A_DIM | A_BOLD);
  mvprintw(1, (COLS / 2) - (taille1 / 2), msg1);

  ifstream f("classique.txt",ios::in);
  if (f) {
    string ligne;
      while(getline(f, ligne)) {
        ligne+=" points";
        mvprintw(i,5,ligne.c_str());
        i=i+2;
      }
  }
  f.close();

  mvprintw(i+2,2,"Appuyer sur Entrée pour revenir au menu principal");
  while (inter!=(char)'\n') {
    inter=IHM::getinput();
  }
  IHM::menu();


}
