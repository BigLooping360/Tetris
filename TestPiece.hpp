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

/*! \class TestPiece_S
 * \brief Classe Test de Piece
 * \author Léa Lefrançois, Laura Couret et Léa Lefrançois
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module sert de test unitaire à la classe Piece
 *On testera si la Piece peut se déplacer vers la gauche, vers et la droite et descendre

*/

class TestPiece : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestPiece);
    CPPUNIT_TEST(testLeft);
    CPPUNIT_TEST(testMoveLeft);
    CPPUNIT_TEST(testRight);
    CPPUNIT_TEST(testMoveRight);
    CPPUNIT_TEST(testDown);
    CPPUNIT_TEST(testMoveDown);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:

    void testLeft(void);
    void testMoveLeft(void);
    void testRight(void);
    void testMoveRight(void);
    /*! \fn void testDown()
    * \brief Teste si la Piece peut descendre dans plusieurs situations : au milieu d'un Board vide, lorsqu'un élément l'empêche de descendre et quand elle est à la frontière d'un Board.
    */
    void testDown(void);
    /*! \fn void testMoveDown()
    * \brief Test  la descente d'une Piece : on testera si la pièce est bien descendu
    */
    void testMoveDown(void);



  private:
    /*! /var *Piece1Test1 est le pointeur sur une Piece de test*/
    Piece *PieceTest1;
    /*! /var *Piece1Test2 est le pointeur sur une Piece de test*/
    Piece *PieceTest2;
    /*! /var *BoardTest est le pointeur sur un Board de test*/
    Board *BoardTest;
};
