#include "Test_JeuMontagnard.hpp"
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

void Test_JeuMontagnard::test_DeplacerPersonnage(){
  Board BoardTest;
  //Rappelons que le personnage apparait en posx = 4 et posy = 0 et il
  //commence en avancant vers la droite
  CPPUNIT_ASSERT(jeum->getPersonnage().getPosx()==4);
  CPPUNIT_ASSERT(jeum->getPersonnage().getPosy()==0);
  CPPUNIT_ASSERT(jeum->getPersonnage().getDirection());
  //On le déplace et on regarde si il s'est bien déplacer
  for (size_t i = 0; i < 5; i++) {
    jeum->DeplacerPersonnage();
    CPPUNIT_ASSERT(jeum->getPersonnage().getPosy()==0);
    CPPUNIT_ASSERT(jeum->getPersonnage().getPosx()==5+i);
    CPPUNIT_ASSERT(jeum->getPersonnage().getDirection());
  }
  //On regarde si le personnage se retourne bien
  jeum->DeplacerPersonnage();
  CPPUNIT_ASSERT(jeum->getPersonnage().getPosx()==9);
  CPPUNIT_ASSERT(jeum->getPersonnage().getPosy()==0);
  CPPUNIT_ASSERT(!jeum->getPersonnage().getDirection());
  for (size_t i = 0; i < 9; i++) {
    jeum->DeplacerPersonnage();
    CPPUNIT_ASSERT(jeum->getPersonnage().getPosy()==0);
    CPPUNIT_ASSERT(jeum->getPersonnage().getPosx()==8-i);
    CPPUNIT_ASSERT(!jeum->getPersonnage().getDirection());
  }


  //On positionne un bloc devant lui pour voir si il monte le bloc
  BoardTest.setGrille(5,0);
  JeuMontagnard jeum2(BoardTest);
  CPPUNIT_ASSERT(jeum2. getPersonnage().getPosx()==4);
  CPPUNIT_ASSERT(jeum2.getPersonnage().getPosy()==0);
  jeum2.DeplacerPersonnage();
  //Le joueur a bougé et est monté sur le bloc
  CPPUNIT_ASSERT(jeum2.getPersonnage().getPosx()==5);
  CPPUNIT_ASSERT(jeum2.getPersonnage().getPosy()==1);
  //Le joueur a gardé sa direction
  CPPUNIT_ASSERT(jeum2.getPersonnage().getDirection());

  //On positionne deux blocs pour voir si il va bien faire demi-tour
  BoardTest.setGrille(5,1);
  JeuMontagnard jeum3(BoardTest);
  CPPUNIT_ASSERT(jeum3.getPersonnage().getPosx()==4);
  CPPUNIT_ASSERT(jeum3.getPersonnage().getPosy()==0);
  CPPUNIT_ASSERT(jeum3.getPersonnage().getDirection());
  jeum3.DeplacerPersonnage();
  //Le joueur a bougé et est monté sur le bloc
  CPPUNIT_ASSERT(jeum3.getPersonnage().getPosx()==4);
  CPPUNIT_ASSERT(jeum3.getPersonnage().getPosy()==0);
  //Le joueur a gardé sa direction
  CPPUNIT_ASSERT(!jeum3.getPersonnage().getDirection());
}


void Test_JeuMontagnard::test_MaJPersonnage(void){
// Le personnage apparait en posx = 4 et posy = 0

// Bloquons le en ajoutant un bloc sur cette case
jeum4->setPieceEnCoursO();
jeum4->interaction(KEY_UP);
jeum4->MaJ();
CPPUNIT_ASSERT(jeum4->getPersonnage().getbloque());
CPPUNIT_ASSERT(jeum->getPersonnage().getPosx()==4);
CPPUNIT_ASSERT(jeum->getPersonnage().getPosy()==0);


//vérifions qu'il se débloque bien
//une Piece_I colonne 0, 1, 2 et 3
jeum4->setPieceEnCoursI();
jeum4->interaction(KEY_BACKSPACE);
for (int i = 0; i < 3 ; i++) {
  jeum4->interaction(KEY_RIGHT);
}
jeum4->interaction(KEY_UP);
jeum4->MaJ();

//une Piece_O colonne 6,7,8 et 9 (attention : colonne démarre à 0)
jeum4->setPieceEnCoursI();
jeum4->interaction(KEY_BACKSPACE);
for (int i = 0; i < 3 ; i++) {
  jeum4->interaction(KEY_LEFT);
}
jeum4->interaction(KEY_UP);
jeum4->MaJ();

//une Piece_I colonne 0, 1, 2 et 3
jeum4->setPieceEnCoursI();
jeum4->interaction(KEY_BACKSPACE);
for (int i = 0; i < 3 ; i++) {
  jeum4->interaction(KEY_RIGHT);
}
jeum4->interaction(KEY_UP);
jeum4->MaJ();

//une Piece_O colonne 6,7,8 et 9 (attention : colonne démarre à 0)
jeum4->setPieceEnCoursI();
jeum4->interaction(KEY_BACKSPACE);
for (int i = 0; i < 3 ; i++) {
  jeum4->interaction(KEY_LEFT);
}
jeum4->interaction(KEY_UP);
jeum4->MaJ();


CPPUNIT_ASSERT(!jeum4->getPersonnage().getbloque());
}

void Test_JeuMontagnard::setUp(void)
{
	jeum = new JeuMontagnard();
  jeum4= new JeuMontagnard();


}
void Test_JeuMontagnard::tearDown(void)
{
  delete jeum;
  delete jeum4;

}
//-----------------------------------------------------------------------------
CPPUNIT_TEST_SUITE_REGISTRATION( Test_JeuMontagnard );
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
	ofstream xmlFileOut("cppTestPiece_I.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();
	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}
