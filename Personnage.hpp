#ifndef __Personnage_HPP__
#define __Personnage_HPP__
#include "Board.hpp"

/*! \class Personnage
 * \brief Représentation du Personnage pour le JeuMontagnard du Tetris
 * \author Victor Le Maistre
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet de représenter et d'utiliser le Personnage du JeuMontagnard.
 *On pourra donc avoir accès à sa position en x et en y,
 *et savoir s'il est bloqué et dans quelle direction il va
*/

class Personnage {

  private:
    /*! /var Posx est la position en x du Personnage dans notre Board*/
    int Posx;
    /*! /var Posy est la position en y du Personnage dans notre Board*/
    int Posy;
    /*! /var bloque est le booleen qui permet de savoir si le Personnage est bloqué ou non*/
    bool bloque;
    /*! /var Direction est le booleen qui vaut true si le Personnage se dirige vers la droite, false si c'est vers la gauche*/
    bool Direction;

  public:
    /*! \fn int getPosx()
    * \brief Accesseur de la position en x du Personnage
    * \return l'entier correspondant à la position en x du Personnage dans un Board
    */
    int getPosx();
    /*! \fn int getPosy()
    * \brief Accesseur de la position en y du Personnage
    * \return l'entier correspondant à la position en y du personnage dans un Board
    */
    int getPosy();
    /*! \fn bool getbloque()
    * \brief Accesseur du booléen bloqué du Personnage
    * \return Retourne true si le Personnage peut toujours avancer, false sinon
    */
    bool getbloque();
    /*! \fn void setbloque()
    * \brief Mutateur du booléen bloqué du Personnage, permet d'inverser la valeur du booléen bloque
    */
    void setbloque();
    /*! \fn bool getDirection()
    * \brief Accesseur du booléen Direction du Personnage
    * \return Retourne le booléen Direction
    */
    bool getDirection();
    /*! \fn void Deplacement(Board b)
    * \brief Permet le déplacement du Personnage dans notre Board dès que possible
    * \param b est notre Board
    */
    void Deplacement(Board b);
    /*! \fn Piece()
    * \brief Constructeur du Personnage pour le JeuMontagnard. A son initialisation, il se situe au plus bas du Board.
    */
    Personnage();

};

#endif
