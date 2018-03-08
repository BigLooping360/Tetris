#ifndef __Bloc_HPP__
#define __Bloc_HPP__
using namespace std;
class Bloc{
  int Posx;
  int Posy;
  public :
  Bloc(int x, int y);
  //Accesseurs :
  int getPosx() const;
  int getPosy() const;
  //Mutateurs :
  void setPosx(int x);
  void setPosy(int y);
};
#endif
