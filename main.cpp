#include <iostream>
//#include "Board.cpp"
//#include "Piece.cpp"
#include "Jeu.cpp"
//#include "Bloc.cpp"
#include <vector>
#include <time.h>
//#include <ncurses.h>
using namespace std;

int main() {
/*Ncurses :*/

//  initscr();
  //  noecho();
//  nodelay(stdscr, TRUE);

  // printw("Hi guys\n");
  // mvaddch(1,1,'1');
  // mvaddch(2,0,'2');
  // refresh();
  // mvaddch(2,0,'3');
  // while(1 ){
  //int n=getch();
  // //if ((char)n=='a')
  //   //printw("n possède la valeur %d pour le caractère %c\n",n,(char)n);
  // endwin();
  // cout<<"bla"<<endl;






/*Test Proto 1*/
  Jeu j;
  j.init();
  j.play();

  /* Test timer
  clock_t temps=clock();
  int i=1;
  while (i<60){
    if (clock()-temps>CLOCKS_PER_SEC){
      std::cout << i << '\n';
      i++;
      temps=clock();
    }
  }*/

  /*Test Piece
   Board b;
   b.init();
   Piece p;
   //T est du booléen de move
   //Cas 1 false car bloc en-dessous :
   //b.setGrille(4,0);
   // Cas 2 false car ne peux plus descendre :

   std::cout << p.isMoveable(b) << '\n';
   p.afficher(b);
   */



  /*Test unit de Board
  Board b;
  b.init();
  b.setGrille(4,19);
  for (int i = 0; i < b.getHauteur(); i++) {
    for (int j = 0; j < b.getLargeur(); j++) {
      std::cout <<  b.getGrille(j,i);
      }
      std::cout << '\n';
    }

  cout<<b;*/


  /* Test unité de Bloc
  Bloc bloc1(123, 23);
  cout<<bloc1.getPosx()<<endl;
  cout<<bloc1.getPosy()<<endl;
  bloc1.setPosx(23);
  bloc1.setPosy(123);
  cout<<bloc1.getPosx()<<endl;
  std::cout << bloc1.getPosy() << '\n';
  */


}
