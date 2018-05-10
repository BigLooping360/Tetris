#include "Score.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <vector>

using namespace std;


Score::Score(string ch) {

    ch+=".txt";
    ifstream fichier(ch.c_str(),ios::app);  //on utilise append pour créer le fichier s'il n'existe pas
    fichier.close();
    nomfichier = ch; //on affecte le nom du mode de jeu + .txt pour le nom du fichier

}

string Score::getNomfichier() {
  return nomfichier;
}

void Score::addscore(float s,string nomjoueur) {

  //déclaration des variables
  int j = 0;
  int n = 0;
  int max = 10; //nb max de meilleurs scores que l'on décide de sauvegarder
  bool OK = true;
  vector<float> scores(10,-1); //tableau permettant de stocker les scores
  vector<string> pseudos(10); //tableau permettant de stocker les pseudos

  //on ouvre en mode lecture pour recupérer tous les scores contenues sur le fichier
  string nomf = getNomfichier();
  ifstream fichier(nomf.c_str(),ios::in); //c_str() permet de transformer nomf en pointeur vers une chaine de caractere
  if (fichier) {
    for (int i=0;i<max;i++) {
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
	for (int i=(max-1);i>=(j+1);i--) {
		scores[i]=scores[i-1];
		pseudos[i]=pseudos[i-1];
	}
	scores[j] = s;
	pseudos[j] = nomjoueur;

  //on réécrit tout dans notre fichier texte que l'on écrase
  ofstream fichier2(nomf.c_str(),ios::out | ios::trunc); //trunc permet de supprimer l'ancien contenu
  while (n<(max-1) && scores[n]>=0) {
    fichier2 << pseudos[n] << " " << scores[n] << endl;
    n++;
  }

  fichier.close();

}

bool Score::meilleurescore(int s) {


}
