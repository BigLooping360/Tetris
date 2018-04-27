#include <iostream>
#include <string>
#include <list>
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
#include <netinet/in.h>
#include "Piece.hpp"
#include "Piece_I.hpp"
#include "Board.hpp"
using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class TestPiece : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestPiece);
	CPPUNIT_TEST(testMoveDown);
	CPPUNIT_TEST(testDown);
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp(void);
	void tearDown(void);
protected:
	void testMoveDown(void);
	void testDown(void);

private:
	Piece *mTestPiece1;
  Piece *mTestPiece2;
	Piece *mTestPiece3;
	Board *mTestBoard;
};
//-----------------------------------------------------------------------------
void TestPiece::setUp(void)
{
	mTestPiece1 = new Piece_I();
	mTestPiece2 = new Piece_I();
	mTestPiece3 = new Piece_I();
	mTestBoard = new Board();
}

void TestPiece::testDown(void)
{ for (int i=0;i<4;i++){
		mTestPiece1->setPosy(i,9);
		mTestPiece1->setPosx(i,4+i);
		}

	CPPUNIT_ASSERT(true == mTestPiece1->Down(mTestBoard)); // je peux descendre

	for (int i=0;i<4;i++){
		mTestPiece1->setPosy(i,0);
		mTestPiece1->setPosx(i,i);
		}

	CPPUNIT_ASSERT(false ==mTestPiece1->Down(mTestBoard));// je suis deja en bas

	for (int i=0;i<4;i++){
		 mTestPiece1->setPosy(i,1);
		 mTestPiece1->setPosx(i,i+4);
		 mTestPiece2->setPosy(i,0);
		 mTestPiece2->setPosx(i,i+5);}
	CPPUNIT_ASSERT(false ==mTestPiece1->Down(mTestBoard));//une piece m'empeche de descendre

}

void TestPiece::testMoveDown(void)
{ for (int i=0;i<4;i++){
		mTestPiece1->setPosy(i,9);
		mTestPiece1->setPosx(i,4+i);
		mTestPiece2->setPosy(i,8);
		mTestPiece2->setPosx(i,4+i);}

	CPPUNIT_ASSERT(mTestPiece2== mTestPiece1->testMoveDown(mTestBoard)); //je peux descendre

	for (int i=0;i<4;i++){
		mTestPiece1->setPosy(i,0);
		mTestPiece1->setPosx(i,i);
		mTestPiece2->setPosy(i,0);
		mTestPiece2->setPosx(i,i);
		}

	CPPUNIT_ASSERT(mTestPiece2== mTestPiece1->testMoveDown(mTestBoard)); //je suis deja en bas

	for (int i=0;i<4;i++){
		mTestPiece1->setPosy(i,1);
		mTestPiece1->setPosx(i,i);
		mTestPiece2->setPosy(i,1);
		mTestPiece2->setPosx(i,i)
		mTestPiece3->setPosy(i,0);
		mTestPiece3->setPosx(i,i);
		}
	CPPUNIT_ASSERT(mTestPiece2== mTestPiece1->testMoveDown(mTestBoard));//une piece m'empeche de descendre

}


void TestBasicMath::tearDown(void)
{
	delete *mTestPiece1;
  delete *mTestPiece2;
	delete *mTestPiece3;
}
//-----------------------------------------------------------------------------
CPPUNIT_TEST_SUITE_REGISTRATION( TestBasicMath );
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
	ofstream xmlFileOut("cppTestBasicMathResults.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();
	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
