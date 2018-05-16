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
#include "JeuMontagnard.hpp"
#include "Jeu.hpp"
#include "Personnage.hpp"

using namespace CppUnit;
using namespace std;

/*! \class Test_JeuMontagnard
 * \brief Classe Test de JeuMontagnard
 * \author Victor LE MAISTRE
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module sert de test unitaire de la classe JeuMontagnard
 *On testera la méthode MaJ en regardant si le personnage et le board sont bien
 *mis à jour
*/

//-----------------------------------------------------------------------------


class Test_JeuMontagnard : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Test_JeuMontagnard);
    //CPPUNIT_TEST(test_MaJ);
    CPPUNIT_TEST(test_DeplacerPersonnage);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    /*! \fn void test_MaJ(void)
    * \brief Test si les pièces sont bien intégrées et si le personnage se déplace bien
    */
    void test_MaJ(void);
    /*! \fn void  test_DeplacerPersonnage()
    * \brief Teste les déplacements du personnages
    */
    void test_DeplacerPersonnage();

  private:
    /*! Initialise le jeu montagnard que l'on testera*/
    JeuMontagnard jeum;

};
