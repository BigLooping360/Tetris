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
 * \brief Classe Test de Piece_L
 * \author Laura Couret
 * \author Léa Lefrançois
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module sert de test unitaire à la classe Score
 *On testera
*/


class TestScore : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestScore);
    CPPUNIT_TEST_SUITE_END();

  public:
    void setUp(void);
    void tearDown(void);
    void testaddscore(int,string);
    void testmeilleurescore(int);
    /*! \fn void testScore(string);
    * \brief Vérifie si le fichier se créé bien et qu'on pourra le modifier
    */
    void testScore(void);

  protected:

  private:
    Score *ScoreClassique;
    Score *ScoreMontagnard;

};
