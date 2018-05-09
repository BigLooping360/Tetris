#ifndef __JeuClassique_HPP__
#define __JeuClassique_HPP__
#include "Jeu.hpp"

/*! \class JeuClassique
 * \brief Gestion du déroulement d'un Jeu Classique
 * \author Léa Lefrançois
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet l'initialisation du début d'une partie de Tetris classique,
 *la mise à jour des différents paramètres suite aux actions d'un joueur,
 *et actionne le déplacement d'une Piece.
*/

class JeuClassique : public Jeu {

  private:
    /*! /var points est le nombre de point gagné par le joueur dans une partie de JeuClassique*/
    int points;

  public:
    /*! \fn JeuClassique()
    * \brief Constructeur d'un JeuClassique, c'est-à-dire d'un Tetris classique
    */
    JeuClassique();
    /*! \fn getpoints()
    * \brief Accesseur du nombre de points pour un JeuClassique
    * \return le score du joueur
    */
    int getpoints();
    /*! \fn setpoints()
    * \brief Modifie le nombre de points du jeu
    */
    void setpoints(int l);
    /*! \fn void MaJ()
    * \brief Met à jour le Board après chaque action du joueur
    */
    void MaJ();

};

#endif
