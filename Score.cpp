#include "Score.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stream>
#include <fstream>

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

  //ATTENTION, gérer a
  string a = "mon pseudo";

  int j=0;
  int max = 10; //nb max de meilleurs scores que l'on décide de sauvegarder
  bool OK=true;
  vector<int> scores(10); //tableau permettant de stocker les scores
  vector<string> pseudos(10); //tableau permettant de stocker les pseudos
  string nomf = getNomfichier();
  ifstream fichier(nomf,ios::in); //on ouvre en mode lecture pour recupérer tous les scores contenues sur le fichier
  if (fichier) {
    for (int i=0;i<10;i++) {
      fichier >> pseudos[i] >> scores[i];
    }
  }
  fichier.close();

  //on insère le nouveau à la bonne place dans nos deux tableaux
  while ((j<max) && OK) {   //on récupère le rang où on doit insérer notre nouveau score
	   if (scores[j] > s) {
		     j++;
	   } else {
		     OK=false;
	   }
   }
	for (int k=(max-1);k>=(j+1);k--) {
		scores[k]=scores[k-1];
		pseudos[k]=pseudos[k-1];
	}
	scores[j]=sc;
	pseudos[j]=a;

  //on réécrit tout dans notre fichier texte que l'on écrase
  ofstream fichier(nomf,ios::out | ios::trunc); //trunc permet de supprimer l'ancien contenu
  int n = 0;
  while (n<(max-1) && scores[n]!=0) {
    fichier << pseudos[n] << " " << scores[n] << endl;
    n++;
  }

  fichier.close();

}

bool Score::meilleurescore(int s) {


}
