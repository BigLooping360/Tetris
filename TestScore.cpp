#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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

void TestScore::testaddscore(int score) {

    //on ajoute des scores dans les classiques et les montagnards
    ScoreClassique->addscore(100);
    ScoreMontagnard->addscore(150);
    char temp[100];

    //et ensuite on parcourt les fichiers pour voir si les scores ont bien été rentrés()
    FILE* f1 = NULL;
    FILE* f2 = NULL;
    f1 = fopen("classique.txt",'r'); //r : mode lecture seule
    f2 = fopen("montagnard.txt",'r');
    if (f1 != NULL) {
		    char ligne1[100];
        //on recupere la dernière ligne de f1
		    while (fgets(ligne1,sizeof(ligne1),f1) != NULL) {
            memset(temp,0,sizeof(temp));
            strcpy(temp,ligne1);
			  }
        CPPUNIT_ASSERT(strcmp("100",temp)==0);
	  };
    if (f2 != NULL) {
		    char ligne2[100];
        //on recupere la dernière ligne de f2
		    while (fgets(ligne2,sizeof(ligne2),f2) != NULL) {
          memset(temp,0,sizeof(temp));
          strcpy(temp,ligne2);
			  }
        CPPUNIT_ASSERT(strcmp("150",temp)==0);
	  };
    fclose(f1);
    fclose(f2);

}

void TestScore::testmeilleurescore(int mscore) {



}

//on vérifie que les fichiers classique.txt et montagnard.txt se sont bien créés et qu'on peut écrire dessus
void TestScore::testScore() {

  char cl[50] = "classique.txt";
  char m[50] = "montagnard.txt";
  FILE* f1 = NULL;
  FILE* f2 = NULL;
  f1 = fopen(cl,'r+'); //r+ : mode écriture et le fichier doit exister
  f2 = fopen(m,'r+');
  CPPUNIT_ASSERT(f1!=NULL);
  CPPUNIT_ASSERT(f2!=NULL);
  fclose(f1);
  fclose(f2);

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
