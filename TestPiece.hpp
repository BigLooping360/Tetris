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
#include "Piece.hpp"
#include "Piece_I.hpp"
#include "Board.hpp"

using namespace CppUnit;
using namespace std;


class TestPiece : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestPiece);
    CPPUNIT_TEST(testLeft);
    CPPUNIT_TEST(testMoveLeft);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testLeft(void);
    void testMoveLeft(void);

  private:
    Piece *PieceTest1;
    Piece *PieceTest2;
    Board *BoardTest;
};
