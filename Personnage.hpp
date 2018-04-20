#ifndef __Personnage_HPP__
#define __Personnage_HPP__
#include "Board.hpp"

/*! \class Personnage
 * \brief Représentation du Personnage pour la version montagnarde du Tetris
 * \author Victor Le Maistre
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet de représenter et d'utiliser le Personnage du Tetris montagnard.
 *On pourra donc avoir accès à sa position en x et en y,
 *et savoir s'il est bloqué et dans quelle direction il va
*/

class Personnage {

  private:
    /*! /var Posx est la position en x du Personnage dans une grille de jeu*/
    int Posx;
    /*! /var Posy est la position en y du Personnage dans une grille de jeu*/
    int Posy;
    /*! /var bloque est le booleen qui permet de savoir si le personnage est bloqué ou non*/
    bool bloque;
    /*! /var Direction est le booleen qui vaut true si le Personnage se dirige vers la droite, false si c'est vers la gauche*/
    bool Direction;

  public:
    /*! \fn int getPosx()
    * \brief Accesseur de la position en x du personnage
    * \return l'entier correspondant à la position en x du personnage dans une grille de jeu
    */
    int getPosx();
    /*! \fn int getPosy()
    * \brief Accesseur de la position en y du personnage
    * \return l'entier correspondant à la position en y du personnage dans une grille de jeu
    */
    int getPosy();
    /*! \fn bool getbloque()
    * \brief Accesseur du booléen bloqué du Personnage
    * \return Retourne true si le personnage peut toujours avancer, false sinon
    */
    bool getbloque();
    /*! \fn bool getDirection()
    * \brief Accesseur du booléen Direction du Personnage
    * \return Retourne le booléen Direction
    */
    bool getDirection();
    /*! \fn void Deplacement(Board b)
    * \brief Permet le déplacement du Personnage dans notre grille dès que possible
    * \param b est notre grille de Tetris
    */
    void Deplacement(Board b);
    /*! \fn Piece()
    * \brief Constructeur du Personnage pour la version montagnarde. A son initialisation, il se situe au plus bas de la grille.
    */
    Personnage();

};

endif;
