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
#include "Piece_T.hpp"
#include "Board.hpp"

using namespace CppUnit;
using namespace std;

/*! \class TestPiece_T
 * \brief Classe Test de Piece_T
 * \author Victor LE MAISTRE
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module sert de test unitaire à la classe Piece_T
 *On testera si la Piece_T peut tourner dans plusieurs situations, et qu'elle
 *est bien bloqué lorsqu'elle ne peut pas tourner.
 *et on testera la rotation en elle-même.
*/
//-----------------------------------------------------------------------------



class TestPiece_T : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestPiece_T);
    CPPUNIT_TEST(isRotateable_Piece_T);
    CPPUNIT_TEST(Rotate_Piece_T);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    /*! \fn void testisRotateable()
    * \brief Teste si la rotation d'une Piece_S est possible dans plusieurs situations (normales et extremes)
    */
    void isRotateable_Piece_T(void);
    /*! \fn void testRotate()
    * \brief Test de la rotation d'une Piece_S : on testera si les rotations se font biens et si 4 rotations ramènent bien la Piece_T dans son état original
    */
    void Rotate_Piece_T(void);

  private:
    /*! *PieceTest1 est le pointeur sur une Piece_T de test*/
    Piece *PieceTest1;
    /*! *BoardTest est le pointeur sur un Board de test*/
    Board *BoardTest;
};
