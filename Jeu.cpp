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
  cout<<b<<endl;
}

void Jeu::play(){
  while (jeu) {
    clock_t temps=clock();
      while (PieceEnCours.getbloque()==false) {
        if (clock()-temps>CLOCKS_PER_SEC){
            cout<<"Hey"<<endl;
            PieceEnCours.fall(b);
            temps=clock();
            PieceEnCours.afficher(b);
          }
      }
      cout<<"Fini"<<endl;
      jeu=false;
  }
}
