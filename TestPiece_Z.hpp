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
#include "Piece_Z.hpp"
#include "Board.hpp"

using namespace CppUnit;
using namespace std;


//-----------------------------------------------------------------------------

class TestPiece_Z : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestPiece_Z);
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
    Piece *mTestPiece1;
    Piece *mTestPiece2;
    Piece *mTestPiece3;
    Piece *mTestPiece4;
    Board *mTestBoard;

};
