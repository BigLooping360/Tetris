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

/*! \class TestPiece
 * \brief Classe Test de Piece
 * \author Léa Lefrançois, Laura Couret et Victor Le Maistre
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module sert de test unitaire à la classe Piece
 *On testera si la Piece peut se déplacer vers la gauche, vers et la droite et descendre
 *Ces tests sont les mêmes quel que soit la forme du Tetrimino, c'est pour cette raison qu'ils sont fait dans la classe Piece dont ils heritent tous
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

    /*! \fn void testLeft(void)
    * \brief Teste si la Piece peut se déplacer vers la gauche dans plusieurs cas (normales et extremes)
    */
    void testLeft(void);
    /*! \fn void testMoveLeft(void)
    * \brief Teste si la Piece se déplace bien vers la gauche dans plusieurs cas (normales et extremes)
    */
    void testMoveLeft(void);
    /*! \fn void testRight(void)
    * \brief Teste si la Piece peut se déplacer vers la droite dans plusieurs cas (normales et extremes)
    */
    void testRight(void);
    /*! \fn void testMoveRight(void)
    * \brief Teste si la Piece se déplace bien vers la droite dans plusieurs cas (normales et extremes)
    */
    void testMoveRight(void);
    /*! \fn void testDown()
    * \brief Teste si la Piece peut descendre dans plusieurs situations : au milieu d'un Board vide, lorsqu'un élément l'empêche de descendre et quand elle est à la frontière d'un Board.
    */
    void testDown(void);
    /*! \fn void testMoveDown()
    * \brief Teste la descente d'une Piece : on testera si la pièce est bien descendue
    */
    void testMoveDown(void);



  private:
    /*! *Piece1Test1 est le pointeur sur une Piece de test*/
    Piece *PieceTest1;
    /*! *Piece1Test2 est le pointeur sur une Piece de test*/
    Piece *PieceTest2;
    /*! *BoardTest est le pointeur sur un Board de test*/
    Board *BoardTest;
};
