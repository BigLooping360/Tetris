#ifndef __JeuMontagnard_HPP__
#define __JeuMontagnard_HPP__
#include "Jeu.hpp"
#include "Personnage.hpp"

/*! \class JeuMontagnard
 * \brief Gestion du déroulement d'un Jeu Montagnard
 * \author Victor Le Maistre
 * \author Laura Couret
 * \version 1.0
 * \date mai 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet l'initialisation du début d'une partie de JeuMontagnard,
 *la mise à jour des différents paramètres suite aux actions d'un joueur,
 *et actionne le déplacement d'une Piece et du Personnage en cas de besoin.
*/

class JeuMontagnard : public Jeu {

  private:
    /*! temps est le temps de secondes d'une partie de JeuMontagnard d'un joueur (jusqu'à ce qu'il perde)*/
    float temps;
    /*! p représente le Personnage du JeuMontagnard*/
    Personnage p;

  public:
    /*! \fn JeuMontagnard()
    * \brief Constructeur d'un JeuMontagnard, c'est-à-dire d'un Tetris avec un Personnage
    */
    JeuMontagnard();

    JeuMontagnard(Board b);
    /*! \fn getTemps()
    * \brief Accesseur du temps de partie d'un JeuMontagnard pour un joueur
    * \return le temps du joueur
    */
    float getTemps();
    /*! \fn void MaJ()
    * \brief Met à jour le Board et le Personnage après chaque action du joueur
    */
    void MaJ();
    /*! \fn Personnage getPersonnage()
    * \brief Accesseur du personnage
    * \return Retourne le personnage
    */
    Personnage getPersonnage();
    /*! \fn void DeplacerPersonnage()
    * \brief Donne l'ordre au personnage de bouger
    */
    void DeplacerPersonnage();

};

#endif
