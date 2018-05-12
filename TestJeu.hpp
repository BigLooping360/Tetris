#include <stdio.h>
#include <stdlib.h>
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
#include "Jeu.hpp"
#include "Piece.hpp"
#include "Board.hpp"

using namespace CppUnit;
using namespace std;

/*! \class TestJeu
 * \brief Classe Test de Jeu
 * \author Laura Couret
 * \version 1.0
 * \date mai 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module sert de test unitaire à la classe Jeu
*/


class TestJeu : public CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE(TestJeu);
    CPPUNIT_TEST(testMaJPiece);
    CPPUNIT_TEST_SUITE_END();

  public:
    void setUp(void);
    void tearDown(void);

  protected:
    //on doit tester que nb_ligneCompletee ok et que jeu devient bien false si besoin
    void testMaJPiece(void);

  private:
    //Piece *PieceTest;
    Jeu *JeuTest;
    //Board *BoardTest;


};
