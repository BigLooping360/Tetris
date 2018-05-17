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
#include "Piece_I.hpp"
#include "Piece_O.hpp"

using namespace CppUnit;
using namespace std;

/*! \class TestJeu
 * \brief Classe Test de JeuClassique
 * \author Léa Lefrançois
 * \version 1.0
 * \date mai 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module sert de test unitaire à la classe JeuClassique
*/


class TestJeu : public CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE(TestJeu);
    CPPUNIT_TEST(testMaJ1);
    CPPUNIT_TEST(testMaJ2);
    CPPUNIT_TEST(testMaJ3);
    CPPUNIT_TEST(testMaJ4);
    CPPUNIT_TEST_SUITE_END();

  public:
    void setUp(void);
    void tearDown(void);

  protected:
    void testMaJ1(void);
    void testMaJ2(void);
    void testMaJ3(void);
    void testMaJ4(void);

  private:
    Jeu *JeuTest1;
    Jeu *JeuTest2;
    Jeu *JeuTest3;
    Jeu *JeuTest4;


};
