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
#include "Piece_L.hpp"
#include "Board.hpp"

using namespace CppUnit;
using namespace std;

/*! \class TestPiece_L
 * \brief Classe Test de Piece_L
 * \author Laura Couret
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module sert de test unitaire à la classe Piece_L
 *On testera si la Piece_L peut tourner dans plusieurs situations
 *et on testera la rotation en elle-même.
*/


class TestPiece_L : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(TestPiece_L);
  CPPUNIT_TEST(testisRotateable);
  CPPUNIT_TEST(testRotate);
  CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

protected:
    /*! \fn void testisRotateable()
    * \brief Teste si la rotation d'une Piece_L est possible dans plusieurs situations : au milieu d'un Board vide, lorsqu'un élément empêche la rotation et à la frontière d'un Board.
    */
    void testisRotateable();
    /*! \fn void testRotate()
    * \brief Test de la rotation d'une Piece_L : on testera si les rotations se font biens et si 4 rotations ramènent bien la Piece_L dans son état original
    */
    void testRotate();

private:
    /*! *PieceTest1 est le pointeur sur une Piece_L de test*/
    Piece_L *PieceTest1;
    /*! *PieceTest2 est le pointeur sur une Piece_L qui servira de comparaison pour les tests*/
    Piece_L *PieceTest2;
    /*! *BoardTest est le pointeur sur un Board de test*/
    Board *BoardTest;

};
