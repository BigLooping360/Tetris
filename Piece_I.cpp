#include <string>
#include<vector>
#include <iostream>
#include "Piece_I.hpp"
Piece_I::Piece_I():tab(5,Bloc(0,0)) {

  for (int i = 0; i < 4; i++)
    tab[i] = Bloc(5,19-i);

  bloque=false;
  //On pose 1 comme le premier état sur 4
  etat=1;
}

bool Piece::isRotateable(Board b){
          switch (etat){
            case 1:
              if ( (getPosx(1)<b.getLargeur()-1) and (getPosx(1)>1) and (b.getGrille(getPosx(1)+1,getPosy(1))==0) and (b.getGrille(getPosx(1)-1,getPosy(1))==0) and (b.getGrille(getPosx(1)-2,getPosy(1))==0))
                return true;
              else
                return false;
              break;

            case 2:
              if ( (getPosy(1)>0) and (getPosy(1)<b.getHauteur()-2) and (b.getGrille(getPosx(1),getPosy(1)-1)==0) and (b.getGrille(getPosx(1),getPosy(1)+1)==0) and (b.getGrille(getPosx(1),getPosy(1)+2)==0)  )
                return true;
              else
                return false;
              break;

            case 3:
              if ( (getPosx(1)<b.getLargeur()-2) and (getPosx(1)>0) and (b.getGrille(getPosx(1)+1,getPosy(1))==0) and (b.getGrille(getPosx(1)-1,getPosy(1))==0) and (b.getGrille(getPosx(1)+2,getPosy(1))==0))
                return true;
              else
                return false;
              break;

            case 4 :
              if ( (getPosy(1)>1) and (getPosy(1)<b.getHauteur()-1) and (b.getGrille(getPosx(1),getPosy(1)-1)==0) and (b.getGrille(getPosx(1),getPosy(1)+1)==0) and (b.getGrille(getPosx(1),getPosy(1)-2)==0)  )
                return true;
              else
                return false;
              break;


          }
        }

void Piece::Rotate(Board b){
          switch (etat){
            case 1:
              if (isRotateable(b)){
                setPosx(0,getPosx(1)+1);
                setPosy(0,getPosy(1));

                setPosx(2,getPosx(1)-1);
                setPosy(2,getPosy(1));

                setPosx(3,getPosx(1)-2);
                setPosy(3,getPosy(1));
                etat++;
              }
              break;

            case 2:
            if (isRotateable(b)){
              setPosx(0,getPosx(1));
              setPosy(0,getPosy(1)-1);

              setPosx(2,getPosx(1));
              setPosy(2,getPosy(1)+1);

              setPosx(3,getPosx(1));
              setPosy(3,getPosy(1)+2);
              etat++;
              }
              break;

            case 3:
            if (isRotateable(b)){
              setPosx(0,getPosx(1)-1);
              setPosy(0,getPosy(1));

              setPosx(2,getPosx(1)+1);
              setPosy(2,getPosy(1));

              setPosx(3,getPosx(1)+2);
              setPosy(3,getPosy(1));
              etat++;
              }
              break;

            case 4 :
            if (isRotateable(b)){
              setPosx(0,getPosx(1));
              setPosy(0,getPosy(1)+1);

              setPosx(2,getPosx(1));
              setPosy(2,getPosy(1)-1);

              setPosx(3,getPosx(1));
              setPosy(3,getPosy(1)-2);
              etat=1;
              }
              break;


          }
        }
