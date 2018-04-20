#include "Menu.hpp"

void Menu::jouerClassique(){
  Jeu1=Jeu();
  initscr();
  noecho();
  keypad(stdscr,TRUE);
  //cbreak();
  nodelay(stdscr, TRUE);


  while(Jeu1.getjeu()){
    clock_t temps=clock();
    while (Jeu1.getstatut()==false) {
        int inter;
        if (clock()-temps>(CLOCKS_PER_SEC/2)){
            Jeu1.interaction((int)'s');
            temps=clock();
          }
        inter=IHM::getinput();
        if (inter!=-1)
          Jeu1.interaction(inter);
        IHM::afficher(Jeu1);
        refresh();
        }
      Jeu1.MaJ();
  }
endwin();
}
