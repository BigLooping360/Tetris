#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include "TestScore.hpp"
#include "Score.hpp"

using namespace CppUnit;
using namespace std;


void TestScore::setUp(void) {

  ScoreClassique = new Score("classique");
  ScoreMontagnard = new Score("montagnard");

}

void TestScore::tearDown(void) {

  delete ScoreClassique;
  delete ScoreMontagnard;

}

void TestScore::testaddscore(void) {

    //déclaration des variables
    int jc = 0; //jc est l'indice où on ajoutera le nouveau score classique
    int jm = 0; //jm est l'indice où on ajoutera le nouveau score classique
    int max = 10; //nb max de scores que l'on peut avoir sur un fichier
    bool OK = true;
    vector<float> scoresc(max,-1); //tableau permettant de stocker les scores classiques, tout initialité à -1
    vector<string> pseudosc(max); //tableau permettant de stocker les pseudos classiques
    vector<float> scoresm(max,-1); //tableau permettant de stocker les scores montagnard, tout initialité à -1
    vector<string> pseudosm(max); //tableau permettant de stocker les pseudos montagnard

    string nomfc = ScoreClassique->getNomfichier();
    string nomfm = ScoreMontagnard->getNomfichier();
    string ligne;
    string joueur = "abc";
    ofstream fc1(nomfc.c_str(),ios::out | ios::trunc); //on écrase le contenu avec trunc
    ofstream fm1(nomfm.c_str(),ios::out | ios::trunc);


    //on remplit notre fichier de quelques scores
    string pseudo = "def";
    if (fc1) {
      for (int i=0;i<max;i++){
        pseudosc[i] = pseudo;
        float score = 100-10*i;
        scoresc[i] = score;
        fc1 << pseudo << " " << score << endl;
      }
    }
    if (fm1) {
      for (int i=0;i<max;i++) {
        pseudosm[i] = pseudo;
        float score = 6.7*(i+1);
        scoresm[i] = score;
        fm1 << pseudo << " " << score << endl;
      }
    }
    fc1.close();
    fm1.close();

    //on ajoute un nouveau score dans classique et montagnard qui se range au milieu
    ScoreClassique->addscore(55,joueur);
    ScoreMontagnard->addscore(10.6,joueur);

    //on récupère le rang jc (respectivement jm) où sera inséré notre nouveau score classique (respectivement notre nouveau score montagnard)
    while ((jc<(max-1)) && OK) {
       if (scoresc[jc] > 55) {
           jc++;
       } else {
           OK=false;
       }
     }
     OK = true;
     while ((jm<(max-1)) && OK) {
        if ((scoresm[jm] < 10.6) && scoresm[jm]>=0) {
            jm++;
        } else {
            OK=false;
        }
      }

    //on vérifie que les scores et les nom du joueur ont bien été rangé aux rangs jc et jm
    ifstream fc2(nomfc.c_str(),ios::in); //c_str() permet de transformer nomf en pointeur vers une chaine de caractere
    ifstream fm2(nomfm.c_str(),ios::in);
    if (fc2 && fm2) {
      for (int i=0;i<max;i++) {
        fc2 >> pseudosc[i] >> scoresc[i];
        fm2 >> pseudosm[i] >> scoresm[i];
      }
    }
    fc2.close();
    fm2.close();
    CPPUNIT_ASSERT(abs(scoresc[jc] - 55) <= 0.000001);
    CPPUNIT_ASSERT(abs(scoresm[jm]-10.6) <= 0.000001);
    CPPUNIT_ASSERT(joueur.compare(pseudosc[jc]) == 0);
    CPPUNIT_ASSERT(joueur.compare(pseudosm[jm]) == 0);


    //on ajoute un nouveau score dans classique et montagnard qui se range au tout début des 10 meilleurs scores
    ScoreClassique->addscore(2000,joueur);
    ScoreMontagnard->addscore(1.3,joueur);

    //on récupère le rang jc (respectivement jm) où sera inséré notre nouveau score classique (respectivement notre nouveau score montagnard)
    jc = 0;
    jm = 0;
    OK = true;
    while ((jc<(max-1)) && OK) {
       if (scoresc[jc] > 2000) {
           jc++;
       } else {
           OK=false;
       }
     }
     OK = true;
     while ((jm<(max-1)) && OK) {
        if ((scoresm[jm] < 1.3) && scoresm[jm]>=0) {
            jm++;
        } else {
            OK=false;
        }
      }

    //on vérifie que les scores et les nom du joueur ont bien été rangé aux rangs jc et jm
    ifstream fc3(nomfc.c_str(),ios::in); //c_str() permet de transformer nomf en pointeur vers une chaine de caractere
    ifstream fm3(nomfm.c_str(),ios::in);
    if (fc3 && fm3) {
      for (int i=0;i<max;i++) {
        fc3 >> pseudosc[i] >> scoresc[i];
        fm3 >> pseudosm[i] >> scoresm[i];
      }
    }
    fc3.close();
    fm3.close();
    CPPUNIT_ASSERT(abs(scoresc[jc] - 2000) <= 0.000001);
    CPPUNIT_ASSERT(abs(scoresm[jm]-1.3) <= 0.000001);
    CPPUNIT_ASSERT(joueur.compare(pseudosc[jc]) == 0);
    CPPUNIT_ASSERT(joueur.compare(pseudosm[jm]) == 0);

    //on ajoute un nouveau score dans classique et montagnard qui se range tout à la fin des 10 meilleurs
    ScoreClassique->addscore(45,joueur);
    ScoreMontagnard->addscore(41.2,joueur);

    //on récupère le rang jc (respectivement jm) où sera inséré notre nouveau score classique (respectivement notre nouveau score montagnard)
    jc = 0;
    jm = 0;
    OK = true;
    while ((jc<(max-1)) && OK) {
       if (scoresc[jc] > 45) {
           jc++;
       } else {
           OK=false;
       }
     }
     OK = true;
     while ((jm<(max-1)) && OK) {
        if ((scoresm[jm] < 41.2 ) && scoresm[jm]>=0) {
            jm++;
        } else {
            OK=false;
        }
      }

    //on vérifie que les scores et les nom du joueur ont bien été rangé aux rangs jc et jm
    ifstream fc4(nomfc.c_str(),ios::in); //c_str() permet de transformer nomf en pointeur vers une chaine de caractere
    ifstream fm4(nomfm.c_str(),ios::in);
    if (fc4 && fm4) {
      for (int i=0;i<max;i++) {
        fc4 >> pseudosc[i] >> scoresc[i];
        fm4 >> pseudosm[i] >> scoresm[i];
      }
    }
    fc4.close();
    fm4.close();
    CPPUNIT_ASSERT(abs(scoresc[jc] - 45) <= 0.000001);
    CPPUNIT_ASSERT(abs(scoresm[jm]-41.2) <= 0.000001);
    CPPUNIT_ASSERT(joueur.compare(pseudosc[jc]) == 0);
    CPPUNIT_ASSERT(joueur.compare(pseudosm[jm]) == 0);

}

void TestScore::testmeilleurescore(void) {
  float score1 = 14;
  float score2 = 1.2;

    string nomfc = ScoreClassique->getNomfichier();
    string nomfm = ScoreMontagnard->getNomfichier();
    ofstream fc(nomfc.c_str(),ios::out | ios::trunc);
    ofstream fm(nomfm.c_str(),ios::out | ios::trunc);

    // si le fichier est vide on peut forcément ajouter notre score
    CPPUNIT_ASSERT(ScoreClassique->meilleurescore(score1));
    CPPUNIT_ASSERT(ScoreMontagnard->meilleurescore(score1));

  //je remplis mon fichier de score de 10 scores
    if (fc) {
      for (int i=0;i<10;i++){
        string pseudo = "abcde";
        float score = 14.3-i;
        fc << pseudo << " " << score << endl;
      }
    }
    if (fm) {
      for (int i=0;i<10;i++){
        string pseudo = "abcde";
        float score = i+2.5;
        fm << pseudo << " " << score << endl;
      }
    }

  fc.close();
  fm.close();

  // on test si c'est des meilleurs scores
  CPPUNIT_ASSERT(ScoreClassique->meilleurescore(score1)==true);
  CPPUNIT_ASSERT(ScoreClassique->meilleurescore(score2)==false);
  CPPUNIT_ASSERT(ScoreMontagnard->meilleurescore(score2)==true);
  CPPUNIT_ASSERT(ScoreMontagnard->meilleurescore(score1)==false);




}

//on vérifie que les fichiers classique.txt et montagnard.txt se sont bien créés et qu'on peut écrire dessus
void TestScore::testScore(void) {

  string cl;
  string m;
  cl = ScoreClassique->getNomfichier();
  m = ScoreMontagnard->getNomfichier();

  //On vérifie que les nomfichier sont biens mis à jour
  CPPUNIT_ASSERT(cl.compare("classique.txt") == 0);
  CPPUNIT_ASSERT(m.compare("montagnard.txt") == 0);

  //on utilise le mode lecture+écriture pour déterminer si les fichiers ont bien été créés
  //ate permet de ne pas effacer le contenu s'ils existent
  fstream f1(cl.c_str(), ios::in | ios::out | ios::ate);
  fstream f2(m.c_str(), ios::in | ios::out | ios::ate);

  //On vérifie que les fichiers ont bien été créés
  CPPUNIT_ASSERT(f1);
  CPPUNIT_ASSERT(f2);

  f1.close();
  f2.close();

}


//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestScore );

int main(int argc, char* argv[])
{
	// informs test-listener about testresults
	CPPUNIT_NS::TestResult testresult;
	// register listener for collecting the test-results
	CPPUNIT_NS::TestResultCollector collectedresults;
	testresult.addListener (&collectedresults);
	// register listener for per-test progress output
	CPPUNIT_NS::BriefTestProgressListener progress;
	testresult.addListener (&progress);
	// insert test-suite at test-runner by registry
	CPPUNIT_NS::TestRunner testrunner;
	testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
	testrunner.run(testresult);
	// output results in compiler-format
	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
	compileroutputter.write ();
	// Output XML for Jenkins CPPunit plugin
	ofstream xmlFileOut("cppTestScore.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();
	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}
