#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
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
#include "TestJeuClassique.hpp"
#include "Jeu.hpp"
#include "JeuClassique.hpp"
#include "Piece.hpp"
#include "Piece_I.hpp"
#include "Piece_O.hpp"
#include "Board.hpp"

using namespace CppUnit;
using namespace std;


void TestJeuClassique::setUp(void) {

  JeuTest1 = new JeuClassique();
  JeuTest2 = new JeuClassique();
  JeuTest3 = new JeuClassique();
  JeuTest4 = new JeuClassique();


}

void TestJeuClassique::tearDown(void) {

  delete JeuTest1;
  delete JeuTest2;
  delete JeuTest3;
  delete JeuTest4;

}


void TestJeuClassique::testMaJ1(void) {

  //on teste que le score augmente bien après la suppression de 1 lignes complete se fait bien
  int j;
  //on remplit une ligne complète sans une case
  //une Piece_I à fond à gauche
  JeuTest1->setPieceEnCoursI();
  for (int i = 0; i < 5 ; i++) {
    JeuTest1->interaction(KEY_LEFT);
  }
  JeuTest1->interaction(KEY_UP);
  j = JeuTest1->MaJPiece();

  //une Piece_O colonne 1 et 2 (attention : colonne démarre à 0)
  JeuTest1->setPieceEnCoursO();
  for (int i = 0; i < 3 ; i++) {
    JeuTest1->interaction(KEY_LEFT);
  }
  JeuTest1->interaction(KEY_UP);
  j = JeuTest1->MaJPiece();

  //une Piece_O colonne 3 et 4 (attention : colonne démarre à 0)
  JeuTest1->setPieceEnCoursO();
  JeuTest1->interaction(KEY_LEFT);
  JeuTest1->interaction(KEY_UP);
  j = JeuTest1->MaJPiece();

  //on rajoute un I couché décalée au max à droite
  JeuTest1->setPieceEnCoursI();
  JeuTest1->interaction(KEY_BACKSPACE);
  for (int i = 0 ; i < 3 ; i++ ) {
    JeuTest1->interaction(KEY_RIGHT);
  }
  JeuTest1->interaction(KEY_UP);
  j = JeuTest1->MaJPiece();

  //on ajoute la Piece manquante
  JeuTest1->setPieceEnCoursI();
  JeuTest1->interaction(KEY_UP);
  j = JeuTest1->MaJPiece();

//on vérifie que le score a bien augmenté
  CPPUNIT_ASSERT(JeuTest1->getpoints() == 10);


}

void TestJeuClassique::testMaJ2(void) {

  //on teste que le score augmente bien après la suppression de 2 lignes completes se fait bien

  int j;

  //on remplit une ligne complète sans une case
  //une Piece_I à fond à gauche
  JeuTest2->setPieceEnCoursI();
  for (int i = 0; i < 5 ; i++) {
    JeuTest2->interaction(KEY_LEFT);
  }
  JeuTest2->interaction(KEY_UP);
  j = JeuTest2->MaJPiece();

  //une Piece_O colonne 1 et 2 (attention : colonne démarre à 0)
  JeuTest2->setPieceEnCoursO();
  for (int i = 0; i < 3 ; i++) {
    JeuTest2->interaction(KEY_LEFT);
  }
  JeuTest2->interaction(KEY_UP);
  j = JeuTest2->MaJPiece();

  //une Piece_O colonne 3 et 4 (attention : colonne démarre à 0)
  JeuTest2->setPieceEnCoursO();
  JeuTest2->interaction(KEY_LEFT);
  JeuTest2->interaction(KEY_UP);
  j = JeuTest2->MaJPiece();

  //une Piece_O colonne 8 et 9 (attention : colonne démarre à 0)
  JeuTest2->setPieceEnCoursO();
  for (int i = 0; i < 4 ; i++) {
    JeuTest2->interaction(KEY_RIGHT);
  }
  JeuTest2->interaction(KEY_UP);
  j = JeuTest2->MaJPiece();

  //une Piece_O colonne 6 et 7 (attention : colonne démarre à 0)
  JeuTest2->setPieceEnCoursO();
  for (int i = 0; i < 2 ; i++) {
    JeuTest2->interaction(KEY_RIGHT);
  }
  JeuTest2->interaction(KEY_UP);
  j = JeuTest2->MaJPiece();

  //on ajoute la Piece manquante
  JeuTest2->setPieceEnCoursI();
  JeuTest2->interaction(KEY_UP);
    j = JeuTest2->MaJPiece();

  //on vérifie que le score a bien augmenté
  CPPUNIT_ASSERT(JeuTest2->getpoints() == 30);

}

void TestJeuClassique::testMaJ3(void) {

  //on teste que le score augmente bien après la suppression de 3 lignes completes se fait bien

  int j;

  //une Piece_I à fond à gauche
  JeuTest3->setPieceEnCoursI();
  for (int i = 0; i < 5 ; i++) {
    JeuTest3->interaction(KEY_LEFT);
  }
  JeuTest3->interaction(KEY_UP);
  j = JeuTest3->MaJPiece();

  //une Piece_O colonne 1 et 2 (attention : colonne démarre à 0) ligne 0 et 1
  JeuTest3->setPieceEnCoursO();
  for (int i = 0; i < 3 ; i++) {
    JeuTest3->interaction(KEY_LEFT);
  }
  JeuTest3->interaction(KEY_UP);
  j = JeuTest3->MaJPiece();

  //une Piece_O colonne 1 et 2 (attention : colonne démarre à 0) ligne 2 et 3
  JeuTest3->setPieceEnCoursO();
  for (int i = 0; i < 3 ; i++) {
    JeuTest3->interaction(KEY_LEFT);
  }
  JeuTest3->interaction(KEY_UP);
  j = JeuTest3->MaJPiece();

  //une Piece_O colonne 3 et 4 (attention : colonne démarre à 0) ligne 0 et 1
  JeuTest3->setPieceEnCoursO();
  JeuTest3->interaction(KEY_LEFT);
  JeuTest3->interaction(KEY_UP);
  j = JeuTest3->MaJPiece();

  //une Piece_O colonne 3 et 4 (attention : colonne démarre à 0) ligne 2 et 3
  JeuTest3->setPieceEnCoursO();
  JeuTest3->interaction(KEY_LEFT);
  JeuTest3->interaction(KEY_UP);
  j = JeuTest3->MaJPiece();

  //une Piece_O colonne 8 et 9 (attention : colonne démarre à 0)
  JeuTest3->setPieceEnCoursO();
  for (int i = 0; i < 4 ; i++) {
    JeuTest3->interaction(KEY_RIGHT);
  }
  JeuTest3->interaction(KEY_UP);
  j = JeuTest3->MaJPiece();

  //une Piece_O colonne 6 et 7 (attention : colonne démarre à 0)
  JeuTest3->setPieceEnCoursO();
  for (int i = 0; i < 2 ; i++) {
    JeuTest3->interaction(KEY_RIGHT);
  }
  JeuTest3->interaction(KEY_UP);
  j = JeuTest3->MaJPiece();

  //on rajoute un I couché décalée au max à droite
  JeuTest3->setPieceEnCoursI();
  JeuTest3->interaction(KEY_BACKSPACE);
  for (int i = 0 ; i < 3 ; i++ ) {
    JeuTest3->interaction(KEY_RIGHT);
  }
  JeuTest3->interaction(KEY_UP);
  j = JeuTest3->MaJPiece();


  //on ajoute la Piece manquante
  JeuTest3->setPieceEnCoursI();
  JeuTest3->interaction(KEY_UP);
  j = JeuTest3->MaJPiece();

//on vérifie que le score a bien augmenté
  CPPUNIT_ASSERT(JeuTest3->getpoints() == 60 );

}

void TestJeuClassique::testMaJ4(void) {

  //on teste que le score augmente bien après la suppression de 4 lignes completes se fait bien

  int j;

  //on remplit une ligne complète sans une case
  //une Piece_I à fond à gauche
  JeuTest4->setPieceEnCoursI();
  for (int i = 0; i < 5 ; i++) {
    JeuTest4->interaction(KEY_LEFT);
  }
  JeuTest4->interaction(KEY_UP);
  j = JeuTest4->MaJPiece();

  //une Piece_O colonne 1 et 2 (attention : colonne démarre à 0) ligne 0 et 1
  JeuTest4->setPieceEnCoursO();
  for (int i = 0; i < 3 ; i++) {
    JeuTest4->interaction(KEY_LEFT);
  }
  JeuTest4->interaction(KEY_UP);
  j = JeuTest4->MaJPiece();

  //une Piece_O colonne 1 et 2 (attention : colonne démarre à 0) ligne 2 et 3
  JeuTest4->setPieceEnCoursO();
  for (int i = 0; i < 3 ; i++) {
    JeuTest4->interaction(KEY_LEFT);
  }
  JeuTest4->interaction(KEY_UP);
  j = JeuTest4->MaJPiece();

  //une Piece_O colonne 3 et 4 (attention : colonne démarre à 0) ligne 0 et 1
  JeuTest4->setPieceEnCoursO();
  JeuTest4->interaction(KEY_LEFT);
  JeuTest4->interaction(KEY_UP);
  j = JeuTest4->MaJPiece();

  //une Piece_O colonne 3 et 4 (attention : colonne démarre à 0) ligne 2 et 3
  JeuTest4->setPieceEnCoursO();
  JeuTest4->interaction(KEY_LEFT);
  JeuTest4->interaction(KEY_UP);
  j = JeuTest4->MaJPiece();

  //une Piece_O colonne 8 et 9 (attention : colonne démarre à 0) ligne 0 et 1
  JeuTest4->setPieceEnCoursO();
  for (int i = 0; i < 4 ; i++) {
    JeuTest4->interaction(KEY_RIGHT);
  }
  JeuTest4->interaction(KEY_UP);
  j = JeuTest4->MaJPiece();

  //une Piece_O colonne 8 et 9 (attention : colonne démarre à 0) ligne 2 et 3
  JeuTest4->setPieceEnCoursO();
  for (int i = 0; i < 4 ; i++) {
    JeuTest4->interaction(KEY_RIGHT);
  }
  JeuTest4->interaction(KEY_UP);
  j = JeuTest4->MaJPiece();

  //une Piece_O colonne 6 et 7 (attention : colonne démarre à 0) ligne 0 et 1
  JeuTest4->setPieceEnCoursO();
  for (int i = 0; i < 2 ; i++) {
    JeuTest4->interaction(KEY_RIGHT);
  }
  JeuTest4->interaction(KEY_UP);
  j = JeuTest4->MaJPiece();

  //une Piece_O colonne 6 et 7 (attention : colonne démarre à 0) ligne 2 et 3
  JeuTest4->setPieceEnCoursO();
  for (int i = 0; i < 2 ; i++) {
    JeuTest4->interaction(KEY_RIGHT);
  }
  JeuTest4->interaction(KEY_UP);
  j = JeuTest4->MaJPiece();

  //on ajoute la Piece manquante
  JeuTest4->setPieceEnCoursI();
  JeuTest4->interaction(KEY_UP);
  j = JeuTest3->MaJPiece();

  //on vérifie que le score a bien augmenté
  CPPUNIT_ASSERT(JeuTest4->getpoints() == 100);


}



//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestJeuClassique );

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
	ofstream xmlFileOut("cppTestJeuClassique.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();
	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}
