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

#include "TestPiece_S.hpp"

#include "Piece.hpp"
#include "Board.hpp"
#include "Piece_S.hpp"

using namespace CppUnit;
using namespace std;

void TestPiece_S::setUp() {
  	mTestPiece1 = new Piece_S();
    mTestPiece2 = new Piece_S();
    mTestPiece3 = new Piece_S();
    mTestPiece4 = new Piece_S();
    mTestBoard = new Board();
}

void TestPiece_S::tearDown() {
    delete mTestPiece1;
    delete mTestPiece2;
    delete mTestPiece3;
    delete mTestPiece4;
    delete mTestBoard;
}

void TestPiece_S::testisRotateable() {

// La pièce peut tourner peut importe sa position intiale

    mTestPiece1->setPosx(0,3);
    mTestPiece1->setPosx(1,4);
    mTestPiece1->setPosx(2,4);
    mTestPiece1->setPosx(3,5);

    mTestPiece1->setPosy(0,7);
    mTestPiece1->setPosy(1,7);
    mTestPiece1->setPosy(2,8);
    mTestPiece1->setPosy(3,8);
    CPPUNIT_ASSERT(mTestPiece1->isRotateable(*mTestBoard));

    mTestPiece2->setetat(2);
    mTestPiece2->setPosx(0,3);
    mTestPiece2->setPosx(1,3);
    mTestPiece2->setPosx(2,4);
    mTestPiece2->setPosx(3,4);

    mTestPiece2->setPosy(0,5);
    mTestPiece2->setPosy(1,4);
    mTestPiece2->setPosy(2,4);
    mTestPiece2->setPosy(3,3);
    CPPUNIT_ASSERT(mTestPiece2->isRotateable(*mTestBoard));

    mTestPiece3->setetat(3);
    mTestPiece3->setPosx(0,5);
    mTestPiece3->setPosx(1,4);
    mTestPiece3->setPosx(2,4);
    mTestPiece3->setPosx(3,3);

    mTestPiece3->setPosy(0,18);
    mTestPiece3->setPosy(1,18);
    mTestPiece3->setPosy(2,17);
    mTestPiece3->setPosy(3,17);
    CPPUNIT_ASSERT(mTestPiece3->isRotateable(*mTestBoard));

    mTestPiece4->setetat(4);
    mTestPiece4->setPosx(0,8);
    mTestPiece4->setPosx(1,8);
    mTestPiece4->setPosx(2,7);
    mTestPiece4->setPosx(3,7);

    mTestPiece4->setPosy(0,3);
    mTestPiece4->setPosy(1,4);
    mTestPiece4->setPosy(2,4);
    mTestPiece4->setPosy(3,5);


    CPPUNIT_ASSERT(mTestPiece4->isRotateable(*mTestBoard));

    //Cas limite

    //Piece a l'etat 1

    // Une piece l'empeche de tourner
    mTestBoard->setGrille(5,6);
    mTestBoard->setGrille(5,7);


	   CPPUNIT_ASSERT(false == mTestPiece1->isRotateable(*mTestBoard));
     mTestBoard->setGrille(5,6);
     mTestBoard->setGrille(5,7);


  //Piece a l'etat 2

  // Une piece l'empeche de tourner

    mTestBoard->setGrille(2,3);// je bloque un bloc du tableau
    mTestBoard->setGrille(3,3);

    CPPUNIT_ASSERT(false == mTestPiece2->isRotateable(*mTestBoard));
    mTestBoard->setGrille(2,3);// je debloque le bloc du tableau
    mTestBoard->setGrille(3,3);
    //Piece a l'etat 3

    // Une piece l'empeche de tourner

    mTestBoard->setGrille(3,18);
    mTestBoard->setGrille(3,19);

    CPPUNIT_ASSERT(false == mTestPiece3->isRotateable(*mTestBoard));
    mTestBoard->setGrille(3,18);
    mTestBoard->setGrille(3,19);

    //Piece a l'etat 4

    // Une piece l'empeche de tourner

      mTestBoard->setGrille(7,3);
      mTestBoard->setGrille(9,4);

      CPPUNIT_ASSERT(false == mTestPiece4->isRotateable(*mTestBoard));
      mTestBoard->setGrille(7,3);
      mTestBoard->setGrille(9,4);


     // Piece à l'état 1 : trop pres du bord du tableau il ne peut pas tourner


      mTestPiece1->setPosy(0,0);
      mTestPiece1->setPosy(1,0);
      mTestPiece1->setPosy(2,1);
      mTestPiece1->setPosy(3,1);

      CPPUNIT_ASSERT(false == mTestPiece1->isRotateable(*mTestBoard));

      // Piece à l'état 2 : trop pres du bord du tableau il ne peut pas tourner


       mTestPiece2->setPosx(0,0);
       mTestPiece2->setPosx(1,0);
       mTestPiece2->setPosx(2,1);
       mTestPiece2->setPosx(3,1);

       CPPUNIT_ASSERT(false == mTestPiece2->isRotateable(*mTestBoard));

       // Piece à l'état 3 : trop pres du bord du tableau il ne peut pas tourner


       mTestPiece3->setPosy(0,19);
       mTestPiece3->setPosy(1,19);
       mTestPiece3->setPosy(2,18);
       mTestPiece3->setPosy(3,18);

        CPPUNIT_ASSERT(false == mTestPiece3->isRotateable(*mTestBoard));

        // Piece à l'état 4 : trop pres du bord du tableau il ne peut pas tourner

        mTestPiece4->setPosx(0,0);
        mTestPiece4->setPosx(1,0);
        mTestPiece4->setPosx(2,1);
        mTestPiece4->setPosx(3,1);

        CPPUNIT_ASSERT(false == mTestPiece4->isRotateable(*mTestBoard));





}

void TestPiece_S::testRotate() {


    mTestPiece1->setPosx(0,3);
    mTestPiece1->setPosx(1,4);
    mTestPiece1->setPosx(2,4);
    mTestPiece1->setPosx(3,5);

    mTestPiece1->setPosy(0,7);
    mTestPiece1->setPosy(1,7);
    mTestPiece1->setPosy(2,8);
    mTestPiece1->setPosy(3,8);

    mTestPiece1->Rotate(*mTestBoard);
    CPPUNIT_ASSERT(mTestPiece1->getetat()==2);

    CPPUNIT_ASSERT(mTestPiece1->getPosx(0)==4);
    CPPUNIT_ASSERT(mTestPiece1->getPosx(1)==4);
    CPPUNIT_ASSERT(mTestPiece1->getPosx(2)==5);
    CPPUNIT_ASSERT(mTestPiece1->getPosx(3)==5);

    CPPUNIT_ASSERT(mTestPiece1->getPosy(0)==8);
    CPPUNIT_ASSERT(mTestPiece1->getPosy(1)==7);
    CPPUNIT_ASSERT(mTestPiece1->getPosy(2)==7);
    CPPUNIT_ASSERT(mTestPiece1->getPosy(3)==6);

    mTestPiece1->Rotate(*mTestBoard);
    CPPUNIT_ASSERT(mTestPiece1->getetat()==3);

    CPPUNIT_ASSERT(mTestPiece1->getPosx(0)==5);
    CPPUNIT_ASSERT(mTestPiece1->getPosx(1)==4);
    CPPUNIT_ASSERT(mTestPiece1->getPosx(2)==4);
    CPPUNIT_ASSERT(mTestPiece1->getPosx(3)==3);

    CPPUNIT_ASSERT(mTestPiece1->getPosy(0)==7);
    CPPUNIT_ASSERT(mTestPiece1->getPosy(1)==7);
    CPPUNIT_ASSERT(mTestPiece1->getPosy(2)==6);
    CPPUNIT_ASSERT(mTestPiece1->getPosy(3)==6);

    mTestPiece1->Rotate(*mTestBoard);
    CPPUNIT_ASSERT(mTestPiece1->getetat()==4);

    CPPUNIT_ASSERT(mTestPiece1->getPosx(0)==4);
    CPPUNIT_ASSERT(mTestPiece1->getPosx(1)==4);
    CPPUNIT_ASSERT(mTestPiece1->getPosx(2)==3);
    CPPUNIT_ASSERT(mTestPiece1->getPosx(3)==3);

    CPPUNIT_ASSERT(mTestPiece1->getPosy(0)==6);
    CPPUNIT_ASSERT(mTestPiece1->getPosy(1)==7);
    CPPUNIT_ASSERT(mTestPiece1->getPosy(2)==7);
    CPPUNIT_ASSERT(mTestPiece1->getPosy(3)==8);

    mTestPiece1->Rotate(*mTestBoard);
    CPPUNIT_ASSERT(mTestPiece1->getetat()==1);

    CPPUNIT_ASSERT(mTestPiece1->getPosx(0)==3);
    CPPUNIT_ASSERT(mTestPiece1->getPosx(1)==4);
    CPPUNIT_ASSERT(mTestPiece1->getPosx(2)==4);
    CPPUNIT_ASSERT(mTestPiece1->getPosx(3)==5);

    CPPUNIT_ASSERT(mTestPiece1->getPosy(0)==7);
    CPPUNIT_ASSERT(mTestPiece1->getPosy(1)==7);
    CPPUNIT_ASSERT(mTestPiece1->getPosy(2)==8);
    CPPUNIT_ASSERT(mTestPiece1->getPosy(3)==8);



    }





CPPUNIT_TEST_SUITE_REGISTRATION(TestPiece_S);

int main(int argc, char* argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("cppTestPiece_S.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}
