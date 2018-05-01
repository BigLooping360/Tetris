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
/*! \class TestPiece_I
 * \brief Classe Test de Piece_I
 * \author Victor LE MAISTRE
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module sert de test unitaire à la classe PieceI
 *On testera si la Piece_Z peut tourner dans plusieurs situations, et qu'elle
 *est bien bloqué lorsqu'elle ne peut pas tourner.
 *et on testera la rotation en elle-même.
*/
//-----------------------------------------------------------------------------


class TestPiece_I : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestPiece_I);
    CPPUNIT_TEST(isRotateable_Piece_I);
    CPPUNIT_TEST(Rotate_Piece_I);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void isRotateable_Piece_I(void);
    void Rotate_Piece_I(void);
  private:
    Piece *PieceTest1;
    Board *BoardTest;
};
