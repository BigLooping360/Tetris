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
#include "TestJeu.hpp"
#include "Jeu.hpp"
#include "JeuClassique.hpp"
#include "Piece.hpp"
#include "Piece_I.hpp"
#include "Board.hpp"

using namespace CppUnit;
using namespace std;


void TestJeu::setUp(void) {

  JeuTest = new JeuClassique();
  //BoardTest = new Board();
  //PieceTest = new Piece_I();

}

void TestJeu::tearDown(void) {

  delete JeuTest;
  //delete BoardTest;
  //delete PieceTest;

}


void TestJeu::testMaJPiece(void) {

  //tout debut d'une partie, on fait descendre la premiere piece, le nombre de lignes complétées est forcément 0
  JeuTest->interaction(KEY_UP);
  CPPUNIT_ASSERT(JeuTest->MaJPiece() == 0);
  //le jeu ne peut pas déjà être bloqué
  CPPUNIT_ASSERT(JeuTest->getjeu());

  //on fait tomber 10 pièces pour être sûr que le jeu doit s'arrêter
  for (int i = 0; i < 10; i++ ) {
    JeuTest->interaction(KEY_UP);
  }
  CPPUNIT_ASSERT(!JeuTest->getjeu());







  //on complete pour que la prochaine piece complete 2 lignes

  //on complete pour que la prochaine piece complete 3 lignes

  //on complete pour que la prochaine piece complete 4 lignes


}



//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestJeu );

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
	ofstream xmlFileOut("cppTestJeu.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();
	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}
