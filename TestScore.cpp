#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include "TestScore.hpp"
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

void TestScore::testaddscore(int scla, float smon, string joueur) {

    //déclaration des variables
    int jc = 0; //jc est l'indice où on ajoutera le nouveau score classique
    int jm = 0; //jm est l'indice où on ajoutera le nouveau score classique
    int max = 10; //nb max de scores que l'on peut avoir sur un fichier
    bool OK = true;
    vector<int> scoresc(10,-1); //tableau permettant de stocker les scores classiques, tout initialité à -1
    vector<string> pseudosc(10); //tableau permettant de stocker les pseudos classiques
    vector<int> scoresm(10,-1); //tableau permettant de stocker les scores montagnard, tout initialité à -1
    vector<string> pseudosm(10); //tableau permettant de stocker les pseudos montagnard

    //on ouvre en mode lecture pour recupérer tous les scores contenues sur les 2 fichiers
    string nomfc = ScoreClassique->getNomfichier();
    string nomfm = ScoreMontagnard->getNomfichier();
    ifstream fc(nomfc.c_str(),ios::in); //c_str() permet de transformer nomf en pointeur vers une chaine de caractere
    ifstream fm(nomfm.c_str(),ios::in);
    if (fc && fm) {
      for (int i=0;i<max;i++) {
        fc >> pseudosc[i] >> scoresc[i];
        fm >> pseudosm[i] >> scoresm[i];
      }
    }
    fc.close();
    fm.close();

    //on récupère le rang jc (respectivement jm) où sera inséré notre nouveau score classique (respectivement notre nouveau score montagnard)
    while ((jc<max) && OK) {
       if (scoresc[jc] > scla) {
           jc++;
       } else {
           OK=false;
       }
     }
     OK = true;
     while ((jm<max) && OK) {
        if (scoresm[jm] > smon) {
            jm++;
        } else {
            OK=false;
        }
      }

    //on ajoute un nouveau score dans classique et montagnard
    ScoreClassique->addscore(scla,joueur);
    ScoreMontagnard->addscore(smon,joueur);

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
    CPPUNIT_ASSERT(scoresc[jc] == scla);
    CPPUNIT_ASSERT(abs(scoresm[jm] - smon) < 0.000001); //epsilon à revoir !
    CPPUNIT_ASSERT(joueur.compare(pseudosc[jc]) == 0);
    CPPUNIT_ASSERT(joueur.compare(pseudosm[jm]) == 0);

}

void TestScore::testmeilleurescore(int mscore) {



}

//on vérifie que les fichiers classique.txt et montagnard.txt se sont bien créés et qu'on peut écrire dessus
void TestScore::testScore() {

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
