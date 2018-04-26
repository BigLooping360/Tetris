#include "TestPiece.hpp"
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

void TestPiece::testLeft(void){
  //Cas limite
  PieceTest1->setPosx(0,0);
  PieceTest1->setPosx(1,0);
  PieceTest1->setPosx(2,0);
  PieceTest1->setPosx(3,0);
  for (size_t i = 0; i < 20; i++) {
  PieceTest1->setPosy(0,i);
  PieceTest1->setPosy(0,i);
  PieceTest1->setPosy(0,i);
  PieceTest1->setPosy(0,i);
  CPPUNIT_ASSERT(!PieceTest1->Left(*BoardTest));
}
  //Lorsque la grille est vide
  for (size_t i = 1; i < 10; i++) {
    PieceTest1->setPosx(0,i);
    PieceTest1->setPosx(1,i);
    PieceTest1->setPosx(2,i);
    PieceTest1->setPosx(3,i);
    for (size_t j = 0; j < 20; j++) {
      PieceTest1->setPosy(0,j);
      PieceTest1->setPosy(1,j);
      PieceTest1->setPosy(2,j);
      PieceTest1->setPosy(3,j);
      CPPUNIT_ASSERT(PieceTest1->Left(*BoardTest));
    }
  }
  // Est ce que la pièce se bloque toute seule ?
  for (size_t i = 1; i < 6; i++) {
    PieceTest1->setPosx(0,i);
    PieceTest1->setPosx(1,i+1);
    PieceTest1->setPosx(2,i+2);
    PieceTest1->setPosx(3,i+3);
    for (size_t j = 0; j < 17; j++) {
      PieceTest1->setPosy(0,j);
      PieceTest1->setPosy(0,j+1);
      PieceTest1->setPosy(0,j+2);
      PieceTest1->setPosy(0,j+3);
      CPPUNIT_ASSERT(PieceTest1->Left(*BoardTest));
    }
  }
  //Est ce que la pièce est bien bloqué par une autre pièce ?
  for (size_t i = 0; i < 9; i++) {
    PieceTest1->setPosx(0,i+1);
    PieceTest1->setPosx(1,i+1);
    PieceTest1->setPosx(2,i+1);
    PieceTest1->setPosx(3,i+1);
    for (size_t j = 0; j < 20; j++) {
      BoardTest->setGrille(i,j);
      PieceTest1->setPosy(0,j);
      PieceTest1->setPosy(1,j);
      PieceTest1->setPosy(2,j);
      PieceTest1->setPosy(3,j);
      CPPUNIT_ASSERT(!PieceTest1->Left(*BoardTest));
    }
  }

}


void TestPiece::isRotateable_Piece_I(){
  PieceTest1 = new Piece_I();
  //Cas banal dans les 4 positions
  PieceTest1->setPosx(0,5);
  PieceTest1->setPosx(1,5);
  PieceTest1->setPosx(2,5);
  PieceTest1->setPosx(3,5);

  PieceTest1->setPosy(0,10);
  PieceTest1->setPosy(1,11);
  PieceTest1->setPosy(2,12);
  PieceTest1->setPosy(3,13);
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest));

  PieceTest1->setetat(2);
  PieceTest1->setPosx(0,3);
  PieceTest1->setPosx(1,4);
  PieceTest1->setPosx(2,5);
  PieceTest1->setPosx(3,6);

  PieceTest1->setPosy(0,10);
  PieceTest1->setPosy(1,10);
  PieceTest1->setPosy(2,10);
  PieceTest1->setPosy(3,10);
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest));

  PieceTest1->setetat(3);
  PieceTest1->setPosx(0,5);
  PieceTest1->setPosx(1,5);
  PieceTest1->setPosx(2,5);
  PieceTest1->setPosx(3,5);

  PieceTest1->setPosy(0,10);
  PieceTest1->setPosy(1,11);
  PieceTest1->setPosy(2,12);
  PieceTest1->setPosy(3,13);
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest));

  PieceTest1->setetat(4);
  PieceTest1->setPosx(0,3);
  PieceTest1->setPosx(1,4);
  PieceTest1->setPosx(2,5);
  PieceTest1->setPosx(3,6);

  PieceTest1->setPosy(0,10);
  PieceTest1->setPosy(1,10);
  PieceTest1->setPosy(2,10);
  PieceTest1->setPosy(3,10);
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest));

  //Cas limite

  PieceTest1->setetat(1);
  for (size_t i = 0; i < 2; i++) {
    PieceTest1->setPosx(0,i);
    PieceTest1->setPosx(1,i);
    PieceTest1->setPosx(2,i);
    PieceTest1->setPosx(3,i);
    for (size_t j = 0; j < 16; j++) {
      PieceTest1->setPosy(0,j);
      PieceTest1->setPosy(1,j+1);
      PieceTest1->setPosy(2,j+2);
      PieceTest1->setPosy(3,j+3);
      CPPUNIT_ASSERT(!PieceTest1->isRotateable(*BoardTest));
    }
  }
  PieceTest1->setPosx(0,9);
  PieceTest1->setPosx(1,9);
  PieceTest1->setPosx(2,9);
  PieceTest1->setPosx(3,9);
  for (size_t j = 0; j < 16; j++) {
    PieceTest1->setPosy(0,j);
    PieceTest1->setPosy(1,j+1);
    PieceTest1->setPosy(2,j+2);
    PieceTest1->setPosy(3,j+3);
    CPPUNIT_ASSERT(!PieceTest1->isRotateable(*BoardTest));
  }




  PieceTest1->setetat(2);
  for (size_t i = 0; i < 2; i++) {
    PieceTest1->setPosy(0,i);
    PieceTest1->setPosy(1,i);
    PieceTest1->setPosy(2,i);
    PieceTest1->setPosy(3,i);
    for (size_t j = 0; j < 16; j++) {
      PieceTest1->setPosx(0,j);
      PieceTest1->setPosx(1,j+1);
      PieceTest1->setPosx(2,j+2);
      PieceTest1->setPosx(3,j+3);
      CPPUNIT_ASSERT(!PieceTest1->isRotateable(*BoardTest));
    }
  }
  PieceTest1->setPosy(0,19);
  PieceTest1->setPosy(1,19);
  PieceTest1->setPosy(2,19);
  PieceTest1->setPosy(3,19);
  for (size_t j = 0; j < 10; j++) {
    PieceTest1->setPosx(0,j);
    PieceTest1->setPosx(1,j+1);
    PieceTest1->setPosx(2,j+2);
    PieceTest1->setPosx(3,j+3);
    CPPUNIT_ASSERT(!PieceTest1->isRotateable(*BoardTest));
  }


  PieceTest1->setetat(3);
  for (size_t i = 8; i < 10; i++) {
    PieceTest1->setPosx(0,i);
    PieceTest1->setPosx(1,i);
    PieceTest1->setPosx(2,i);
    PieceTest1->setPosx(3,i);
    for (size_t j = 0; j < 16; j++) {
      PieceTest1->setPosy(0,j);
      PieceTest1->setPosy(1,j+1);
      PieceTest1->setPosy(2,j+2);
      PieceTest1->setPosy(3,j+3);
      CPPUNIT_ASSERT(!PieceTest1->isRotateable(*BoardTest));
    }
  }
  PieceTest1->setPosx(0,0);
  PieceTest1->setPosx(1,0);
  PieceTest1->setPosx(2,0);
  PieceTest1->setPosx(3,0);
  for (size_t j = 0; j < 16; j++) {
    PieceTest1->setPosy(0,j);
    PieceTest1->setPosy(1,j+1);
    PieceTest1->setPosy(2,j+2);
    PieceTest1->setPosy(3,j+3);
    CPPUNIT_ASSERT(!PieceTest1->isRotateable(*BoardTest));
  }

  PieceTest1->setetat(4);
  for (size_t i = 18; i < 20; i++) {
    PieceTest1->setPosy(0,i);
    PieceTest1->setPosy(1,i);
    PieceTest1->setPosy(2,i);
    PieceTest1->setPosy(3,i);
    for (size_t j = 0; j < 16; j++) {
      PieceTest1->setPosx(0,j);
      PieceTest1->setPosx(1,j+1);
      PieceTest1->setPosx(2,j+2);
      PieceTest1->setPosx(3,j+3);
      CPPUNIT_ASSERT(!PieceTest1->isRotateable(*BoardTest));
    }
  }
  PieceTest1->setPosy(0,0);
  PieceTest1->setPosy(1,0);
  PieceTest1->setPosy(2,0);
  PieceTest1->setPosy(3,0);
  for (size_t j = 0; j < 10; j++) {
    PieceTest1->setPosx(0,j);
    PieceTest1->setPosx(1,j+1);
    PieceTest1->setPosx(2,j+2);
    PieceTest1->setPosx(3,j+3);
    CPPUNIT_ASSERT(!PieceTest1->isRotateable(*BoardTest));
  }


}


void TestPiece::Rotate_Piece_I(){
  PieceTest1 = new Piece_I;

  PieceTest1->setPosx(0,5);
  PieceTest1->setPosx(1,5);
  PieceTest1->setPosx(2,5);
  PieceTest1->setPosx(3,5);

  PieceTest1->setPosy(0,10);
  PieceTest1->setPosy(1,11);
  PieceTest1->setPosy(2,12);
  PieceTest1->setPosy(3,13);

  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat()==2);
  for (size_t i = 0; i < 4; i++) {
    CPPUNIT_ASSERT(PieceTest1->getPosy(i)==11);
  }
  CPPUNIT_ASSERT(PieceTest1->getPosx(0)==6);
  CPPUNIT_ASSERT(PieceTest1->getPosx(1)==5);
  CPPUNIT_ASSERT(PieceTest1->getPosx(2)==4);
  CPPUNIT_ASSERT(PieceTest1->getPosx(3)==3);


  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat()==3);
  for (size_t i = 0; i < 4; i++) {
    CPPUNIT_ASSERT(PieceTest1->getPosx(i)==5);
  }
  CPPUNIT_ASSERT(PieceTest1->getPosy(0)==12);
  CPPUNIT_ASSERT(PieceTest1->getPosy(1)==11);
  CPPUNIT_ASSERT(PieceTest1->getPosy(2)==10);
  CPPUNIT_ASSERT(PieceTest1->getPosy(3)==9);

  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat()==4);
  for (size_t i = 0; i < 4; i++) {
    CPPUNIT_ASSERT(PieceTest1->getPosy(i)==11);
  }
  CPPUNIT_ASSERT(PieceTest1->getPosx(0)==4);
  CPPUNIT_ASSERT(PieceTest1->getPosx(1)==5);
  CPPUNIT_ASSERT(PieceTest1->getPosx(2)==6);
  CPPUNIT_ASSERT(PieceTest1->getPosx(3)==7);

  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat()==1);
  for (size_t i = 0; i < 4; i++) {
    CPPUNIT_ASSERT(PieceTest1->getPosx(i)==5);
  }
  CPPUNIT_ASSERT(PieceTest1->getPosy(0)==10);
  CPPUNIT_ASSERT(PieceTest1->getPosy(1)==11);
  CPPUNIT_ASSERT(PieceTest1->getPosy(2)==12);
  CPPUNIT_ASSERT(PieceTest1->getPosy(3)==13);
}




void TestPiece::setUp(void)
{
	PieceTest1 = new Piece_I();
  PieceTest2 = new Piece_I();
  BoardTest = new Board();
}
void TestPiece::tearDown(void)
{
	delete PieceTest1;
  delete PieceTest2;
  delete BoardTest;

}
//-----------------------------------------------------------------------------
CPPUNIT_TEST_SUITE_REGISTRATION( TestPiece );
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
	ofstream xmlFileOut("cppTestPiece.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();
	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}
