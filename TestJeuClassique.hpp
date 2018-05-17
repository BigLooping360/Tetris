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
#include "JeuClassique.hpp"
#include "Piece.hpp"
#include "Piece_I.hpp"
#include "Piece_O.hpp"

using namespace CppUnit;
using namespace std;

/*! \class TestJeuClassique
 * \brief Classe Test de JeuClassique
 * \author Léa Lefrançois
 * \version 1.0
 * \date mai 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module sert de test unitaire à la classe JeuClassique
*/


class TestJeuClassique : public CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE(TestJeuClassique);
    CPPUNIT_TEST(testMaJ1);
    CPPUNIT_TEST(testMaJ2);
    CPPUNIT_TEST(testMaJ3);
    CPPUNIT_TEST(testMaJ4);
    CPPUNIT_TEST_SUITE_END();

  public:
    void setUp(void);
    void tearDown(void);

  protected:
    /*! \fn void testMaJ1()
    * \brief Teste si le score a bien été augmenté après qu'une ligne soit complétée.
    */
    void testMaJ1(void);
    /*! \fn void testMaJ1()
    * \brief Teste si le score a bien été augmenté après que 2 lignes soit complétées.
    */
    void testMaJ2(void);
    /*! \fn void testMaJ1()
    * \brief Teste si le score a bien été augmenté après que 3 lignes soit complétées.
    */
    void testMaJ3(void);
    /*! \fn void testMaJ1()
    * \brief Teste si le score a bien été augmenté après que 4 lignes soit complétées.
    */
    void testMaJ4(void);

  private:
    /*! *JeuTest1 est le pointeur sur un JeuClassique de test*/
    JeuClassique *JeuTest1;
    /*! *JeuTest2 est le pointeur sur un JeuClassique de test*/
    JeuClassique *JeuTest2;
    /*! *JeuTest3 est le pointeur sur un JeuClassique de test*/
    JeuClassique *JeuTest3;
    /*! *JeuTest4 est le pointeur sur un JeuClassique de test*/
    JeuClassique *JeuTest4;


};
