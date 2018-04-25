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

class TestCellule : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestCellule);
    CPPUNIT_TEST(testGetPosition());
    CPPUNIT_TEST(testGetNaissance());
    CPPUNIT_TEST(testGetColonie());
    CPPUNIT_TEST(testGetDoitMourir());
    CPPUNIT_TEST(testGetDoitNaitre());
    CPPUNIT_TEST(testDoitMourir());
    CPPUNIT_TEST(testNaitre());
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testMoveLeft(void);
  private:
    Piece *PieceTest1;
    Piece *PieceTest;
    Board *BoardTest;


};
