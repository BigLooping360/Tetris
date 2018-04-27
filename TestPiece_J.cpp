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

#include "TestPiece_J.hpp"

#include "Piece.hpp"
#include "Board.hpp"
#include "Piece_J.hpp"

using namespace CppUnit;
using namespace std;

void TestPiece_J::setUp() {
  	PieceTest1 = new Piece_J();
    PieceTest2 = new Piece_J(); //mTestPiece2 est la pièce test utilisee pour la comparaison
    BoardTest = new Board();
}

void TestPiece_J::tearDown() {
    delete PieceTest1;
    delete PieceTest2;
    delete BoardTest;
}

void TestPiece_J::testisRotateable() {

  //cas normal : la pièce est au milieu d'une grille vide, rien ne l'empêche de tourner d'un cran vers la gauche
  int i;
  PieceTest1->setPosx(0,6);
  PieceTest1->setPosy(0,9);
  for (i=1;i<4;i++) {
    PieceTest1->setPosx(i,7-i);
    PieceTest1->setPosy(i,10);
  }
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest));

  //cas où une case pleine à côté de la Piece n'empêche pas la pièce de tourner
  BoardTest->setGrille(5,9);
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest));

  //cas où une case pleine de la grille empêche la pièce de tourner
  BoardTest->setGrille(6,11);
  CPPUNIT_ASSERT(!PieceTest1->isRotateable(*BoardTest));

  //cas où une case pleine de la grille empêche la pièce de tourner
  BoardTest->setGrille(6,11);
  BoardTest->setGrille(6,12);
  CPPUNIT_ASSERT(!PieceTest1->isRotateable(*BoardTest));

  //cas où la Piece_J est collé au bord droit de la grille dans l'état 1 (mais n'empêche pas la rotation)
  PieceTest1->setPosx(0,BoardTest->getLargeur()-1);
  PieceTest1->setPosy(0,9);
  for (i=1;i<4;i++) {
    PieceTest1->setPosx(i,BoardTest->getLargeur()-i);
    PieceTest1->setPosy(i,10);
  }
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest));

  //cas où la Piece_J est collé au bord droit de la grille dans l'etat 2 (et empêche la rotation)
  PieceTest1->setetat(2);
  PieceTest1->setPosx(0,BoardTest->getLargeur()-2);
  PieceTest1->setPosy(0,10);
  for (i=1;i<4;i++) {
    PieceTest1->setPosx(i,BoardTest->getLargeur()-1);
    PieceTest1->setPosy(i,9+i);
  }
  CPPUNIT_ASSERT(!PieceTest1->isRotateable(*BoardTest));

}

void TestPiece_J::testRotate() {

  int i;

  //cas normal : la pièce est au milieu d'une grille vide, rien ne l'empêche de tourner d'un cran vers la gauche
  PieceTest1->setPosx(0,6);
  PieceTest1->setPosy(0,9);
  PieceTest2->setPosx(0,5);
  PieceTest2->setPosy(0,10);
  for (i=1;i<4;i++) {
    PieceTest1->setPosx(i,7-i);
    PieceTest1->setPosy(i,10);
    PieceTest2->setPosx(i,6);
    PieceTest2->setPosy(i,9+i);
  }
  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat() == 2);
  for (i=0;i<4;i++) {
    CPPUNIT_ASSERT(PieceTest2->getPosx(i) == PieceTest1->getPosx(i));
    CPPUNIT_ASSERT(PieceTest2->getPosy(i) == PieceTest1->getPosy(i));
  }

  //On effectue un 2e rotation et on vérifie que les positions sont bonnes et que l'état a augmenté
  PieceTest2->setPosx(0,6);
  PieceTest2->setPosy(0,11);
  for (i=1;i<4;i++) {
    PieceTest2->setPosx(i,5+i);
    PieceTest2->setPosy(i,10);
  }
  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat() == 3);

  //On effectue une 3e rotation et on vérifie que les positions sont bonnes et que l'état a augmenté
  PieceTest2->setPosx(0,7);
  PieceTest2->setPosy(0,10);
  for (i=1;i<4;i++) {
    PieceTest2->setPosx(i,6);
    PieceTest2->setPosy(i,11-i);
  }
  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat() == 4);

  //On effectue une 4e rotation et on vérifie que les positions sont bonnes et que l'état est revenu à 1
  PieceTest2->setPosx(0,6);
  PieceTest2->setPosy(0,9);
  for (i=1;i<4;i++) {
    PieceTest2->setPosx(i,7-i);
    PieceTest2->setPosy(i,10);
  }
  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat() == 1);

  //On tourne notre pièce 4 fois et on veut qu'elle revienne à la même position
  PieceTest1->setPosx(0,6);
  PieceTest1->setPosy(0,9);
  PieceTest2->setPosx(0,6);
  PieceTest2->setPosy(0,9);
  for (i=1;i<4;i++) {
    PieceTest1->setPosx(i,7-i);
    PieceTest1->setPosy(i,10);
    PieceTest2->setPosx(i,7-i);
    PieceTest2->setPosy(i,10);
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

CPPUNIT_TEST_SUITE_REGISTRATION(TestPiece_J);

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
    ofstream xmlFileOut("cppTestPiece_J.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}
