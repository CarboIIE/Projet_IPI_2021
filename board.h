#ifndef _BOARD_H
#define _BOARD_H

#include "stack.h"

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

s_list empty_s_list();

int is_empty_s_list(s_list l);

void push_s_list(square coord, s_list* lp);

square pop_s_list(s_list* lp);

void print_s_list(s_list l);

square left_square(square coord);

square upper_square(square coord);

square right_square(square coord);

square lower_square(square coord);

square upp_left_square(square coord);

square low_right_square(square coord);

/*@requires *lp liste et adresse valides
  assigns *lp
  ensures retourne retourne les cases adjacentes ou il est possible de jouer */
void available_squares(s_list* lp, square coord, board b, int board_size);

//Signatures des procedures et fonctions gerant le plateau en soi

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

void desactivate_board(board* bp, int board_size);

//Fonction temporaire d'affichage pour voir le plateau
void print_matrix(board b, int board_size);

/*@requires *bp[real_coord.line][real_coord.col] pile et adresse valides et
            bp[real_coord.line][real_coord.col] valide
  assigns *bp[real_coord.line][real_coord.col] et potentiellement les cases adjacentes
          si elles n'ont pas ete activees
  ensures joue le jeton j sur la pile *bp[real_coord.line][real_coord.col]
	  et sur les piles adjacentes si besoin */
void play(player j, board* bp, int board_size, square real_coord);

#endif
