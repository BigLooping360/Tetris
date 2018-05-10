#include "Menu.hpp"

using namespace std;

void Menu::lancement() {
  //scorec = Score("classique");
  //scorem = Score("montagnard");
  IHM::init();
  IHM::menu();
  int inter=-1;
  while (inter!=(int)'5'){
    inter=IHM::getinput();
    if (inter==(int)'1')
      jouerClassique();
    if (inter==(int)'2')
      jouerMontagnard();
    if (inter==(int)'3')
      ConsulterScore();
    if (inter==(int)'4')
      ConsulterRegles();
  }
  IHM::fin();

}

void Menu::jouerClassique(){
  jeuc=JeuClassique();
  IHM::init();
  while(jeuc.getjeu()){
    clock_t temps=clock();
    while (jeuc.getstatut()==false) {
        int inter;
        if (clock()-temps>(CLOCKS_PER_SEC/2)){
            jeuc.interaction((int)'s');
            temps=clock();
          }
        inter=IHM::getinput();
        if (inter!=-1)
          jeuc.interaction(inter);
        IHM::afficher(jeuc);
        refresh();
        }
      jeuc.MaJ();
  }
IHM::menu();
}

void Menu::jouerMontagnard(){
  jeum=JeuMontagnard();
  IHM::init();


  while(jeum.getjeu()){
    clock_t temps=clock();
    while (jeum.getstatut()==false) {
        int inter;
        if (clock()-temps>(CLOCKS_PER_SEC/2)){
            jeum.interaction((int)'s');
            if (!jeum.getPersonnage().getbloque())
              jeum.DeplacerPersonnage();
            temps=clock();
          }
        inter=IHM::getinput();
        if (inter!=-1)
          jeum.interaction(inter);
        IHM::afficher(jeum);
        refresh();
        }
      jeum.MaJ();
  }
  IHM::menu();

}

void Menu::ConsulterScore() {
  //IHM::score();

}

void Menu::ConsulterRegles() {
  IHM::reglesduJeu();

}
