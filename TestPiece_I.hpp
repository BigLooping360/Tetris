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
 *Ce module sert de test unitaire à la classe Piece_I
 *On testera si la Piece_I peut tourner dans plusieurs situations, et qu'elle
 *est bien bloquée lorsqu'elle ne peut pas tourner.
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
    /*! \fn void isRotateable_Piece_I(void)
    * \brief Teste la rotation de la Piece_I dans plusieurs situations (normales et extremes)
    */
    void isRotateable_Piece_I(void);
    /*! \fn void Rotate_Piece_I(void)
    * \brief Teste si la rotation de la Piece_I se fait bien dans plusieurs situations (normales et extremes)
    */
    void Rotate_Piece_I(void);
  private:
    /*! *PieceTest1 est le pointeur sur une Piece_I de test*/
    Piece *PieceTest1;
    /*! *BoardTest est le pointeur sur un Board de test*/
    Board *BoardTest;
};
