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

  protected:
  /*! Posx est un entier qui représente la position en abscisse*/
  int Posx;
  /*! Posy est un entier qui représente la position en ordonnée*/
  int Posy;

  public:
  /*! \fn Bloc(int x,int y)
  * \brief Constructeur d'un Bloc
  */
  Bloc(int x, int y);
  /*! \fn int getPosx() const
  * \return renvoie la position en abscisse d'un Bloc
  */
  int getPosx() const;
  /*! \fn int getPosy() const
  * \return renvoie la position en ordonnée d'un Bloc
  */
  int getPosy() const;
  /*! \fn void setPosx(int x)
  * \param x correspond à la position que l'on veut en abscisse en sortie de cette fonction
  * \brief modifie la position en abscisse d'un Bloc
  */
  void setPosx(int x);
  /*! \fn void setPosy(int y)
  * \param y correspond à la position que l'on veut en ordonnée en sortie de cette fonction
  * \brief modifie la position en ordonnée d'un Bloc
  */
  void setPosy(int y);

};
#endif
