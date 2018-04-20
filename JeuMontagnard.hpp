#ifndef __JeuMontagnard_HPP__
#define __JeuMontagnard_HPP__
#include "Jeu.hpp"
#include "Personnage.hpp"

class JeuMontagnard : public Jeu {

  private:
    /*! /var temps est le nombre de millisecondes d'une partie de Tetris Montagnard d'un joueur (jusqu'à ce qu'il perde)*/
    int Temps;
    /*! /var p représente le Personnage du jeu Tetris Montagnard*/
    Personnage p;

  public:
    /*! \fn JeuMontagnard()
    * \brief Constructeur d'un JeuMontagnard, c'est-à-dire d'un Tetris avec un Personnage
    */
    JeuMontagnard();
    /*! \fn getTemps()
    * \brief Accesseur du temps d'une partie d'un JeuMontagnard pour un joueur
    * \return le temps du joueur
    */
    int getTemps();
    /*! \fn void MaJ()
    * \brief Met à jour la grille et le personnage après chaque action du joueur
    */
    void MaJ();
    /*! \fn void init()
    * \brief Initialise le jeu et le personnage en début de partie
    */
    void init();
    /*! \fn void play()
    * \brief Permet au joueur de jouer et réagit en fonction
    */
    void play();

};

#endif
