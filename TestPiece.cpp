#include "TestPiece.hpp"


void TestBasicMath::testAddition(void)
{
	CPPUNIT_ASSERT(5 == mTestObj->Addition(2,3));
}
void TestBasicMath::testMultiply(void)
{
	CPPUNIT_ASSERT(6 == mTestObj->Multiply(2,3));
}
void TestPiece::setUp(void)
{
	PieceTest1 = new Piece_I();
  PieceTest2 = new Piece_I()
  BoardTest = new Board();
}
void TestBasicMath::tearDown(void)
{
	delete mTestObj;
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
}
