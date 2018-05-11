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
#include "Piece_S.hpp"
#include "Board.hpp"

using namespace CppUnit;
using namespace std;

/*! \class TestPiece_S
 * \brief Classe Test de Piece_S
 * \author Léa Lefrançois
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module sert de test unitaire à la classe Piece_S
 *On testera si la Piece_S peut tourner dans plusieurs situations
 *et on testera la rotation en elle-même.
*/


//-----------------------------------------------------------------------------

class TestPiece_S : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestPiece_S);
  CPPUNIT_TEST(testisRotateable);
  CPPUNIT_TEST(testRotate);
  CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

protected:
    /*! \fn void testisRotateable()
    * \brief Teste si la rotation d'une Piece_S est possible dans plusieurs situations : au milieu d'un Board vide, lorsqu'un élément empêche la rotation et à la frontière d'un Board.
    */
    void testisRotateable();

    /*! \fn void testRotate()
    * \brief Test de la rotation d'une Piece_S : on testera si les rotations se font biens et si 4 rotations ramènent bien la Piece_S dans son état original
    */
    void testRotate();

private:
    /*! *mTestPiece1 est le pointeur sur une Piece_S de test*/
    Piece *mTestPiece1;
    /*! *mTestPiece2 est le pointeur sur une Piece_S de test*/
    Piece *mTestPiece2;
    /*! *mTestPiece3 est le pointeur sur une Piece_S de test*/
    Piece *mTestPiece3;
    /*! *mTestPiece4 est le pointeur sur une Piece_S de test*/
    Piece *mTestPiece4;
    /*! *mTestBoard est le pointeur sur un Board de test*/
    Board *mTestBoard;

};
