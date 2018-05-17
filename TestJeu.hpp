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
 * \brief Classe Test de Jeu
 * \author Laura Couret
 * \version 1.0
 * \date mai 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module sert de test unitaire à la classe Jeu. Plus précisément, on vérifiera la fonction MaJPiece.
 *Pour plus de lisibilité, on vérifiera dans 4 tests séparés les cas où 1, 2, 3 ou 4 lignes sont complétées en même temps.
*/


class TestJeu : public CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE(TestJeu);
    CPPUNIT_TEST(testMaJPiece1);
    CPPUNIT_TEST(testMaJPiece2);
    CPPUNIT_TEST(testMaJPiece3);
    CPPUNIT_TEST(testMaJPiece4);
    CPPUNIT_TEST_SUITE_END();

  public:
    void setUp(void);
    void tearDown(void);

  protected:
    /*! \fn void testMaJPiece1(void)
    * \brief Vérifie qu'on supprime bien une ligne une fois qu'elle est complétée
    */
    void testMaJPiece1(void);
    /*! \fn void testMaJPiece2(void)
    * \brief Vérifie qu'on supprime bien 2 lignes une fois qu'elle sont complétées
    */
    void testMaJPiece2(void);
    /*! \fn void testMaJPiece3(void)
    * \brief Vérifie qu'on supprime bien 3 lignes une fois qu'elle sont complétées
    */
    void testMaJPiece3(void);
    /*! \fn void testMaJPiece4(void)
    * \brief Vérifie qu'on supprime bien 4 lignes une fois qu'elle sont complétées
    */
    void testMaJPiece4(void);

  private:
    /*! *JeuTest1 est le pointeur sur un Jeu de test*/
    Jeu *JeuTest1;
    /*! *JeuTest2 est le pointeur sur un Jeu de test*/
    Jeu *JeuTest2;
    /*! *JeuTest3 est le pointeur sur un Jeu de test*/
    Jeu *JeuTest3;
    /*! *JeuTest4 est le pointeur sur un Jeu de test*/
    Jeu *JeuTest4;


};
