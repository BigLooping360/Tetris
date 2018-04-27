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
#include <netinet/in.h>
#include "Piece.hpp"
#include "Piece_J.hpp"
#include "Board.hpp"

using namespace CppUnit;
using namespace std;


//-----------------------------------------------------------------------------

class TestPiece_J : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestPiece_J);
  CPPUNIT_TEST(testisRotateable);
  CPPUNIT_TEST(testRotate);
  CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

protected:
    void testisRotateable();
    void testRotate();

private:
    Piece *mTestPiece;
    Piece *mTestPiece2;
    Board *mTestBoard;

};
