#include "TestPiece_T.hpp"
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



void TestPiece_T::isRotateable_Piece_T(void){
  PieceTest1 = new Piece_T();
  //Cas banal dans les 4 positions
  PieceTest1->setPosx(0,4);
  PieceTest1->setPosx(1,5);
  PieceTest1->setPosx(2,6);
  PieceTest1->setPosx(3,5);

  PieceTest1->setPosy(0,10);
  PieceTest1->setPosy(1,10);
  PieceTest1->setPosy(2,10);
  PieceTest1->setPosy(3,11);
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest));

  PieceTest1->setetat(2);
  PieceTest1->setPosx(0,5);
  PieceTest1->setPosx(1,5);
  PieceTest1->setPosx(2,5);
  PieceTest1->setPosx(3,4);

  PieceTest1->setPosy(0,9);
  PieceTest1->setPosy(1,10);
  PieceTest1->setPosy(2,11);
  PieceTest1->setPosy(3,10);
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest));

  PieceTest1->setetat(3);
  PieceTest1->setPosx(0,4);
  PieceTest1->setPosx(1,5);
  PieceTest1->setPosx(2,6);
  PieceTest1->setPosx(3,5);

  PieceTest1->setPosy(0,10);
  PieceTest1->setPosy(1,10);
  PieceTest1->setPosy(2,10);
  PieceTest1->setPosy(3,9);
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest));

  PieceTest1->setetat(4);
  PieceTest1->setPosx(0,5);
  PieceTest1->setPosx(1,5);
  PieceTest1->setPosx(2,5);
  PieceTest1->setPosx(3,6);

  PieceTest1->setPosy(0,9);
  PieceTest1->setPosy(1,10);
  PieceTest1->setPosy(2,11);
  PieceTest1->setPosy(3,10);
  CPPUNIT_ASSERT(PieceTest1->isRotateable(*BoardTest));


  //Cas limite
  PieceTest1->setetat(1);
  PieceTest1->setPosy(0,0);
  PieceTest1->setPosy(1,0);
  PieceTest1->setPosy(2,0);
  PieceTest1->setPosy(3,1);
  for (size_t i = 0; i < 7; i++) {
    PieceTest1->setPosx(0,i);
    PieceTest1->setPosx(1,i+1);
    PieceTest1->setPosx(2,i+2);
    PieceTest1->setPosx(3,i+1);
    CPPUNIT_ASSERT(!PieceTest1->isRotateable(*BoardTest));
  }

  PieceTest1->setetat(2);
  PieceTest1->setPosx(0,9);
  PieceTest1->setPosx(1,9);
  PieceTest1->setPosx(2,9);
  PieceTest1->setPosx(3,8);
  for (size_t i = 0; i < 18; i++) {
    PieceTest1->setPosy(0,i);
    PieceTest1->setPosy(1,i+1);
    PieceTest1->setPosy(2,i+2);
    PieceTest1->setPosy(3,i+1);
    CPPUNIT_ASSERT(!PieceTest1->isRotateable(*BoardTest));
  }

  PieceTest1->setetat(3);
  PieceTest1->setPosy(0,19);
  PieceTest1->setPosy(1,19);
  PieceTest1->setPosy(2,19);
  PieceTest1->setPosy(3,18);
  for (size_t i = 0; i < 7; i++) {
    PieceTest1->setPosx(0,i+2);
    PieceTest1->setPosx(1,i+1);
    PieceTest1->setPosx(2,i+1);
    PieceTest1->setPosx(3,i+1);
    CPPUNIT_ASSERT(!PieceTest1->isRotateable(*BoardTest));
  }

  PieceTest1->setetat(4);
  PieceTest1->setPosx(0,0);
  PieceTest1->setPosx(1,0);
  PieceTest1->setPosx(2,0);
  PieceTest1->setPosx(3,1);
  for (size_t i = 0; i < 18; i++) {
    PieceTest1->setPosy(0,i+2);
    PieceTest1->setPosy(1,i+1);
    PieceTest1->setPosy(2,i);
    PieceTest1->setPosy(3,i+1);
    CPPUNIT_ASSERT(!PieceTest1->isRotateable(*BoardTest));
  }
}

void TestPiece_T::Rotate_Piece_T(void){
  PieceTest1 = new Piece_T();

  PieceTest1->setPosx(0,4);
  PieceTest1->setPosx(1,5);
  PieceTest1->setPosx(2,6);
  PieceTest1->setPosx(3,5);

  PieceTest1->setPosy(0,10);
  PieceTest1->setPosy(1,10);
  PieceTest1->setPosy(2,10);
  PieceTest1->setPosy(3,11);

  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat()==2);
  for (size_t i = 0; i < 3; i++) {
    CPPUNIT_ASSERT(PieceTest1->getPosx(i)==5);
  }
  CPPUNIT_ASSERT(PieceTest1->getPosx(3)==4);
  CPPUNIT_ASSERT(PieceTest1->getPosy(0)==9);
  CPPUNIT_ASSERT(PieceTest1->getPosy(1)==10);
  CPPUNIT_ASSERT(PieceTest1->getPosy(2)==11);
  CPPUNIT_ASSERT(PieceTest1->getPosy(3)==10);

  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat()==3);
  for (size_t i = 0; i < 3; i++) {
    CPPUNIT_ASSERT(PieceTest1->getPosy(i)==10);
  }
  CPPUNIT_ASSERT(PieceTest1->getPosy(3)==9);
  CPPUNIT_ASSERT(PieceTest1->getPosx(0)==6);
  CPPUNIT_ASSERT(PieceTest1->getPosx(1)==5);
  CPPUNIT_ASSERT(PieceTest1->getPosx(2)==4);
  CPPUNIT_ASSERT(PieceTest1->getPosx(3)==5);

  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat()==4);
  for (size_t i = 0; i < 3; i++) {
    CPPUNIT_ASSERT(PieceTest1->getPosx(i)==5);
  }
  CPPUNIT_ASSERT(PieceTest1->getPosx(3)==6);
  CPPUNIT_ASSERT(PieceTest1->getPosy(0)==11);
  CPPUNIT_ASSERT(PieceTest1->getPosy(1)==10);
  CPPUNIT_ASSERT(PieceTest1->getPosy(2)==9);
  CPPUNIT_ASSERT(PieceTest1->getPosy(3)==10);

  PieceTest1->Rotate(*BoardTest);
  CPPUNIT_ASSERT(PieceTest1->getetat()==1);
  for (size_t i = 0; i < 3; i++) {
    CPPUNIT_ASSERT(PieceTest1->getPosy(i)==10);
  }
  CPPUNIT_ASSERT(PieceTest1->getPosy(3)==11);
  CPPUNIT_ASSERT(PieceTest1->getPosx(0)==4);
  CPPUNIT_ASSERT(PieceTest1->getPosx(1)==5);
  CPPUNIT_ASSERT(PieceTest1->getPosx(2)==6);
  CPPUNIT_ASSERT(PieceTest1->getPosx(3)==5);


}


void TestPiece_T::setUp(void)
{
	PieceTest1 = new Piece_T();
  BoardTest = new Board();
}
void TestPiece_T::tearDown(void)
{
	delete PieceTest1;
  delete BoardTest;

}
//-----------------------------------------------------------------------------
CPPUNIT_TEST_SUITE_REGISTRATION( TestPiece_T );
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
	ofstream xmlFileOut("cppTestPiece_T.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();
	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}
