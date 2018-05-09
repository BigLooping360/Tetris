#include "Score.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stream.h>

using namespace std;


Score::Score(string ch) {

    strcat(ch,".txt");
    ifstream fichier(ch,ios::app);  //on utilise append pour créer le fichier s'il n'existe pas
    fichier.close();
    string nomfichier = ch; //on affecte le nom du mode de jeu + .txt pour le nom du fichier

}

string getNomfichier() {

  return nomfichier;

}

void Score::addscore(int s) {

  string nomf = getNomfichier();
  ifstream fichier(nomf,ios::app); //on ajoute le nouveau score à la fin du fichier
  if (fichier) {
    fichier << s << endl;
  }
  fichier.close();

}

bool Score::meilleurescore(int s) {


}
