#ifndef _INTERFACE_H
#define _INTERFACE_H

#include "board.h"

/*@requires nothing
  assigns un entier qui représente le nombre de joueurs
  ensures retourne un entier qui est le nombre de joueurs dans la partie,
          la question sera posee a l'utilisateur via un printf */
int get_players();

/*@requires nothing
  assigns un entier qui représente la taille du plateau
  ensures retourne la taille du terrain souhaitee par l'utilisateur,
          la question sera posee via un printf */
int get_board_size();

/*@requires plateau valide et la taille est bien la sienne (celle demandee en debut de partie)
  assigns nothing
  ensures affiche le plateau de jeu donc le dessus de chaque pile d'une case */
void print_board(board b, int board_size);

/*@requires *coordp a une adresse et une valeur valides, coordp valide
  assigns *coordp
  ensures affecte les coordonnees d'une case, rentrees par le joueur, dans *coordp */
void get_square(square* coordp);

void ask_confirmation(char* conf_pointer);

void print_winner(board b, int board_size, int nb_players);

#endif
