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
#include "Bloc.hpp"

using namespace CppUnit;
using namespace std;


class TestPiece : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestPiece);
    CPPUNIT_TEST(testLeft);
    CPPUNIT_TEST(testRight);
    CPPUNIT_TEST(testMoveRight);
    CPPUNIT_TEST(isRotateable_Piece_I);
    CPPUNIT_TEST(Rotate_Piece_I);
    CPPUNIT_TEST(testDown);
    CPPUNIT_TEST(testMoveDown);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testLeft(void);
    void testRight(void);
    void testMoveRight(void);
    void isRotateable_Piece_I(void);
    void Rotate_Piece_I(void);
    void testMoveDown(void);
    void testDown(void);


  private:
    Piece *PieceTest1;
    Piece *PieceTest2;
    Piece *PieceTest3;
    Board *BoardTest;
};
