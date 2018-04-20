#ifndef __Bloc_HPP__
#define __Bloc_HPP__
using namespace std;

/*! \class Bloc
 * \brief Représentation d'un élément dans l'espace
 * \author Victor Le Maistre
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet de représenter un élément dans l'espace, par sa position en x et sa position en y.
 *On pourra modifier ces positions.
*/

class Bloc {
  /*! /var Posx est un entier qui représente la position en abscisse*/
  int Posx;
  /*! /var Posy est un entier qui représente la position en ordonnée*/
  int Posy;
  public :
  Bloc(int x, int y);
  /*! \fn int getPosx()
  * \return renvoie la position en abscisse d'un bloc
  */
  int getPosx() const;
  /*! \fn int getPosy()
  * \return renvoie la position en ordonnée d'un bloc
  */
  int getPosy() const;
  /*! \fn void setPosx(int x)
  * \param x correspond à la position que l'on veut en abscisse en sortie de cette fonction
  * \brief modifie la position en abscisse d'un bloc
  */
  void setPosx(int x);
  /*! \fn void setPosy(int y)
  * \param y correspond à la position que l'on veut en ordonnée en sortie de cette fonction
  * \brief modifie la position en ordonnée d'un bloc
  */
  void setPosy(int y);

};
#endif
