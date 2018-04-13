#ifndef __Board_HPP__
#define __Board_HPP__
#include <iostream>
using namespace std;

/*! \class Board
 * \brief Représentation d'une grille de jeu
 * \author Victor Le Maistre
 * \version 1.0
 * \date avril 2018
 * \bug Rien à signaler
 * \warning Rien à signaler
 *
 *Ce module permet de représenter une grille de jeu dont on peut choisir la dimension en largeur (horizontalement) et en hauteur (verticalement).
 *On pourra modifier la largeur et la hauteur de cette grille.
 *Un élément de la grille vaut 1 s'il contient quelque chose, 0 sinon.
 *Pour finir, on pourra avoir accès et modifier les éléments de la grille.
*/
class Board {

  // Largeur et Hauteur sont static et const pour pouvoir initialiser Grille
  /*! /var Largeur représente le nombre de colonnes de la grille. Par défaut, elle est fixée à 10.*/
  static const int Largeur=10;
  /*! /var Hauteur représente le nombre de lignes de la grille. Par défaut, elle est fixée à 20.*/
  static const int Hauteur=20;

  /*! /var Grille est un tableau de dimension Largeur x Hauteur. Attention, l'origine de notre grille est fixée en bas à gauche alors que l'origine d'un tableau est fixée en haut à gauche. */
  int Grille[Largeur][Hauteur];
  public :
  /*! \fn int getLargeur() const
  * \brief renvoie la largeur de la grille, c'est-à-dire le nombre de colonnes
  */
  int getLargeur() const;
  /*! \fn int getHauteur() const
  * \brief renvoie la hauteur de la grille, c'est-à-dire le nombre de lignes
  */
  int getHauteur() const;
  /*! \fn int getGrille(int x, int y)
  * \brief renvoie l'élément de la grille se situant à x en abscisse, y en ordonnée.
  */
  int getGrille(int x, int y) const;
  /*! \fn void setGrille(int x, int y)
  * \brief modifie la valeur de la grille dans la case en [x,y]
  */
  void setGrille(int x, int y);
  //Le changer en constructeur
  /*! \fn void init()
  * \brief initialise une grille en début de jeu en la remplissant de 0
  */
  void init();
  /*! \fn friend ostream  &operator <<(ostream &out,  Board &)
  * \brief Cette classe ami permet d'afficher la grille sur un terminal, affiche un x lorsque la grille comprend un 1, et affiche 0 sinon.
  */
  friend ostream  &operator <<(ostream &out,  Board &);

};

ostream & operator<<(ostream &out,  Board &b);
#endif
