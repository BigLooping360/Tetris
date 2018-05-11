#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
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
#include "Score.hpp"

using namespace CppUnit;
using namespace std;

/*! \class TestScore
 * \brief Classe Test de Score
 * \author Laura Couret
 * \author Léa Lefrançois
 * \version 1.0
 * \date mai 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module sert de test unitaire à la classe Score
 *On testera le constructeur de Score, l'ajout d'un score dans le palmares, et si un score peut rentrer dans le palmares ou non
*/


class TestScore : public CppUnit::TestFixture {

    CPPUNIT_TEST_SUITE(TestScore);
    CPPUNIT_TEST(testaddscore);
    CPPUNIT_TEST(testmeilleurescore);
    CPPUNIT_TEST(testScore);
    CPPUNIT_TEST_SUITE_END();

  public:
    void setUp(void);
    void tearDown(void);

  protected:

    /*! \fn void testaddscore(void)
    * \brief Teste l'ajout d'un meilleur score dans le palmares, et vérifie si le score se range bien au bon endroit dans le palmares (du meilleur au pire score)
    */
    void testaddscore(void);
    /*! \fn void testmeilleurescore(void)
    * \brief Teste si on détermine bien quand il s'agit d'un meilleur score ou non
    */
    void testmeilleurescore(void);
    /*! \fn void testScore(string)
    * \brief Vérifie si le fichier se créé bien et qu'on pourra le modifier
    */
    void testScore(void);

  private:
    Score *ScoreClassique;
    Score *ScoreMontagnard;

};
