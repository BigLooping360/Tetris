#ifndef __JeuClassique_HPP__
#define __JeuClassique_HPP__
#include "Jeu.hpp"

class JeuClassique : public Jeu {

  private:
    /*! /var points est le nombre de point gagné par le joueur dans une partie de Tetris Classique*/
    int points;

  public:
    /*! \fn JeuClassique()
    * \brief Constructeur d'un JeuClassique, c'est-à-dire d'un Tetris classique
    */
    JeuClassique();
    /*! \fn getpoints()
    * \brief Accesseur du nombre de points pour un Tetris Classique
    * \return le score du joueur
    */
    int getpoints();
    /*! \fn void MaJ()
    * \brief Met à jour la grille après chaque action du joueur
    */
    void MaJ();
    /*! \fn void init()
    * \brief Initialise le jeu en début de partie
    */
    void init();
    /*! \fn void play()
    * \brief Permet au joueur de jouer et réagit en fonction
    */
    void play();

};

#endif
