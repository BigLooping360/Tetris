#ifndef __JeuClassique_HPP__
#define __JeuClassique_HPP__
#include "Jeu.hpp"

/*! \class JeuClassique
 * \brief Gestion du déroulement d'un Jeu Classique
 * \author Léa Lefrançois
 * \author Laura Couret
 * \version 1.0
 * \date mai 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet l'initialisation du début d'une partie de Tetris classique,
 *la mise à jour des différents paramètres suite aux actions d'un joueur,
 *et actionne le déplacement d'une Piece.
*/

class JeuClassique : public Jeu {

  private:
    /*! points est le nombre de points gagnés par le joueur dans une partie de JeuClassique*/
    int points;

  public:
    /*! \fn JeuClassique()
    * \brief Constructeur d'un JeuClassique, c'est-à-dire d'un Tetris classique
    */
    JeuClassique();
    /*! \fn int getpoints()
    * \brief Accesseur du nombre de points pour un JeuClassique
    * \return le score du joueur
    */
    int getpoints();
    /*! \fn void setpoints()
    * \brief Modifie le nombre de points du jeu
    * \param l est l'entier que l'on veut ajouter au nombre de points actuels
    */
    void setpoints(int l);
    /*! \fn void MaJ()
    * \brief Met à jour le Board après chaque action du joueur
    */
    void MaJ();

};

#endif
