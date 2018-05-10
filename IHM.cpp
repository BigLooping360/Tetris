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
  char *choix3 = "3 pour consulter les meilleurs scores";
  char *choix4 = "4 pour quitter l'application";
  int taille1= strlen(msg1);
  int taille2= strlen(msg2);
  int taille3= strlen(msg3);
  int taille4= strlen(choix1);
  int taille5= strlen(choix2);
  int taille6= strlen(choix3);
  int taille7= strlen(choix4);
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

void IHM::score() {

  ScoreClassique();
  //ScoreMontagnard();

}

void IHM::ScoreMontagnard() {

  int max = 10;
  int j = 0;
  vector<float> scores(10,-1); //tableau permettant de stocker les scores
  vector<string> pseudos(10); //tableau permettant de stocker les pseudos

  //on ouvre en mode lecture pour recupérer tous les scores contenues sur le fichier classique.txt
  ifstream fichier("montagnard.txt",ios::in);
  if (fichier) {
    for (int i=0;i<max;i++) {
      fichier >> pseudos[i] >> scores[i];
    }
  }
  fichier.close();

  mvprintw(0,0,"Les meilleurs scores pour le Tetris Montagnard sont : ");

  while (j<(max-1) && scores[j]>=0) {
    cout << pseudos[j] << " : " << scores[j] << " points" << endl; //a revoir
    j++;
  }

}

void IHM::ScoreClassique() {

  int max = 10;
  int j = 0;
  vector<int> scores(10,-1); //tableau permettant de stocker les scores
  vector<string> pseudos(10); //tableau permettant de stocker les pseudos

  //on ouvre en mode lecture pour recupérer tous les scores contenues sur le fichier classique.txt
  ifstream fichier("classique.txt",ios::in);
  if (fichier) {
    for (int i=0;i<max;i++) {
      fichier >> pseudos[i] >> scores[i];
    }
  }
  fichier.close();

  mvprintw(0,0,"Les meilleurs scores pour le Tetris Classique sont : ");
  //char *temp;
  while (j<(max-1) && scores[j]>=0) {
    //strcpy(temp,pseudos[j].c_str());
    //strcat(temp," : ");
    //strcat(temp,scores[j].c_str());
    //strcat(temp," points\n");
    //mvprintw(1,1,temp);
    j++;
  }


}
