#include <iostream>
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

#include "TestPiece_L.hpp"

#include "Piece.hpp"
#include "Board.hpp"
#include "Piece_L.hpp"

using namespace CppUnit;
using namespace std;

void TestPiece_L::setUp() {
  	PieceTest1 = new Piece_L();
    PieceTest2 = new Piece_L(); //mTestPiece2 est la pièce test utilisee pour la comparaison
    BoardTest = new Board();
}

void TestPiece_L::tearDown() {
    delete PieceTest1;
    delete PieceTest2;
    delete BoardTest;
}

void TestPiece_L::testisRotateable() {

  //cas normal : la pice est au milieu d'une grille vide, rien ne l'empêche de tourner d'un cran vers la gauche
  int i;
  PieceTest1->setPosx(0,4);
  PieceTest1->setPosy(0,8);
  for (i=1;i<4;i++) {
    PieceTest1->setPosx(i,3+i);
    PieceTest1->setPosy(i,9);
  }
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest) == true);

  BoardTest->setGrille(4,10);
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest) == true);

  //cas où une case pleine de la grille empêche la pièce de tourner
  BoardTest->setGrille(3,9);
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest) == false);

  BoardTest->setGrille(3,9);
  BoardTest->setGrille(4,7);
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest) == false);

  //cas où le bord de la grille empêche la rotation
  PieceTest1->setPosx(0,0);
  PieceTest1->setPosy(0,8);
  for (i=1;i<4;i++) {
    PieceTest1->setPosx(i,i-1);
    PieceTest1->setPosy(i,9);
  }
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest) == false);

}

void TestPiece_L::testRotate() {

  int i;

  //cas normal : la pièce est au milieu d'une grille vide, rien ne l'empêche de tourner d'un cran vers la gauche
  PieceTest1->setPosx(0,4);
  PieceTest1->setPosy(0,8);
  PieceTest2->setPosx(0,3);
  PieceTest2->setPosy(0,9);
  for (i=1;i<4;i++) {
    PieceTest1->setPosx(i,3+i);
    PieceTest1->setPosy(i,9);
    PieceTest2->setPosx(i,4);
    PieceTest2->setPosy(i,10-i);
  }
  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat() == 2);
  for (i=0;i<4;i++) {
    CPPUNIT_ASSERT(PieceTest2->getPosx(i) == PieceTest1->getPosx(i));
    CPPUNIT_ASSERT(PieceTest2->getPosy(i) == PieceTest1->getPosy(i));
  }

  //On effectue un 2e rotation et on vérifie que les positions sont bonnes et que l'état a augmenté
  PieceTest2->setPosx(0,3);
  PieceTest2->setPosy(0,9);
  for (i=1;i<4;i++) {
    PieceTest2->setPosx(i,4);
    PieceTest2->setPosy(i,10-i);
  }
  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat() == 3);

  //On effectue une 3e rotation et on vérifie que les positions sont bonnes et que l'état a augmenté
  PieceTest2->setPosx(0,4);
  PieceTest2->setPosy(0,10);
  for (i=1;i<4;i++) {
    PieceTest2->setPosx(i,5-i);
    PieceTest2->setPosy(i,9);
  }
  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat() == 4);

  //On effectue une 4e rotation et on vérifie que les positions sont bonnes et que l'état est revenu à 1
  PieceTest2->setPosx(0,5);
  PieceTest2->setPosy(0,9);
  for (i=1;i<4;i++) {
    PieceTest2->setPosx(i,4);
    PieceTest2->setPosy(i,8+i);
  }
  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat() == 1);

  //On tourne notre pièce 4 fois et on veut qu'elle revienne à la même position
  PieceTest1->setPosx(0,4);
  PieceTest1->setPosy(0,8);
  PieceTest2->setPosx(0,4);
  PieceTest2->setPosy(0,8);
  for (i=1;i<4;i++) {
    PieceTest1->setPosx(i,3+i);
    PieceTest1->setPosy(i,9);
    PieceTest2->setPosx(i,3+i);
    PieceTest2->setPosy(i,9);
  }
  for (i=0;i<4;i++) {
    PieceTest1->Rotate(*BoardTest);
  }
  CPPUNIT_ASSERT(PieceTest1->getetat() == 1);
  for (i=0;i<4;i++) {
    CPPUNIT_ASSERT(PieceTest2->getPosx(i) == PieceTest1->getPosx(i));
    CPPUNIT_ASSERT(PieceTest2->getPosy(i) == PieceTest1->getPosy(i));
  }

}

CPPUNIT_TEST_SUITE_REGISTRATION(TestPiece_L);

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
    ofstream xmlFileOut("cppTestPiece_L.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}
