#include <iostream>
#include <fstream>
#include <string.h>
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

}

void TestScore::tearDown(void) {

}

void TestScore::testaddscore(int score) {


}

void TestScore::testmeilleurescore(int mscore) {



}

//on vérifie que le fichier ch.txt s'est bien créé et qu'on pourra écrire dessus, et que l'attribut nomfichier de Score s'est bien mis à jour
void TestScore::testScore(string ch) {

  strcat(ch,".txt"); // On concatène .txt à ch
  CPPUNIT_ASSERT();
  FILE* fichier = NULL;
  fichier = fopen(ch,'r'+);
  CPPUNIT_ASSERT(fichier!=NULL);

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
