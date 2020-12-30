#ifndef _BOARD_H
#define _BOARD_H

#include "stack.h"



/*--------------------------------- INTERFACE DES LISTES DE CASES ---------------------------------*/



//Type case (square) qui permettra de plus facilement acceder a une case du plateau
typedef struct square{
  int line;
  int col;
} square;

//Creation du type abstrait s_list (square_list)
typedef struct square_list_base* s_list;

//Alias du type int en type player
typedef int player;

//Type concret du plateau qui est donc une matrice dont les elements sont des piles
typedef stack** board;

/*@requires nothing
  assigns une square_list
  ensures retourne une square_list vide */
s_list empty_s_list();

/*@requires l valide
  assigns nothing
  ensures retourne 1 si l est vide, 0 sinon */
int is_empty_s_list(s_list l);

/*@requires *lp valide et d'adresse valide, lp valide, coord valide
  assigns *lp
  ensures rajoute coord a *lp */
void push_s_list(square coord, s_list* lp);

/*@requires *lp valide et d'adresse valide
  assigns *lp
  ensures retourne le dernier element ajoute a *lp */
square pop_s_list(s_list* lp);

/*@requires coord valide
  assigns nothing
  ensures retourne la case a gauche de celle passee en parametre si possible */
square left_square(square coord);

/*@requires coord valide
  assigns nothing
  ensures retourne la case au-dessus de celle passee en parametre si possible */
square upper_square(square coord);

/*@requires coord valide
  assigns nothing
  ensures retourne la case a droite de celle passee en parametre si possible */
square right_square(square coord);

/*@requires coord valide
  assigns nothing
  ensures retourne en-dessous de celle passee en parametre si possible */
square lower_square(square coord);

/*@requires coord valide
  assigns nothing
  ensures retourne la case en haut a gauche de celle passee en parametre si possible */
square upp_left_square(square coord);

/*@requires coord valide
  assigns nothing
  ensures retourne la case en bas a droite de celle passee en parametre si possible */
square low_right_square(square coord);

/*@requires *lp liste et adresse valides
  assigns *lp
  ensures retourne retourne les cases adjacentes ou il est possible de jouer */
void available_squares(s_list* lp, square coord, board b, int board_size);



/*--------------------------------- INTERFACE DU PLATEAU ---------------------------------*/



/*@requires nothing
  assigns un plateau
  ensures retourne un plateau vide de taille n */
board empty_board(int n);

/*@requires nothing
  assigns nothing
  ensures retourne 1 si le plateau est plein, 0 sinon */
int is_board_full(board b, int board_size);

/*@requires bp a une adresse valide et *bp un plateau valide
  assigns *bp
  ensures libere le plateau une fois que la partie est terminee */
void free_board(board* bp, int board_size);

/*@requires *bp valide et d'adresse valide, bp valide
  assigns *bp
  ensures desactive toutes les cases activees pendant un tour a la fin de celui-ci */
void desactivate_board(board* bp, int board_size);

/*@requires *bp[real_coord.line][real_coord.col] pile et adresse valides et
            bp[real_coord.line][real_coord.col] valide
  assigns *bp[real_coord.line][real_coord.col] et potentiellement les cases adjacentes
          si elles n'ont pas ete activees
  ensures joue le jeton j sur la pile *bp[real_coord.line][real_coord.col]
	  et sur les piles adjacentes si besoin */
void play(player j, board* bp, int board_size, square real_coord);

#endif
