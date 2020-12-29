#include <stdlib.h>
#include <stdio.h>
#include "interface.h"
#include "board.h"
#include "stack.h"

int main(int argc, char** argv){

  //On demande le nombre j de joueurs
  int j = get_players();
  
  //Variable qui va varier de 1 a j pour faire jouer tous les joueurs
  int i = 1;

  //On demande la taille de plateau souhaitee
  int board_size = get_board_size();
  
  //Creation du plateau de jeu vide de taille board_size
  board b = empty_board(board_size);

  //Case courante selectionnee par un joueur
  square coord;

  /*Boucle qui s'arrete lorsque la partie est terminee,
    donc lorsque le plateau est rempli (cf is_board_full) */
  while (!is_board_full(b,board_size)){     
      
    for (i = 1; i <= j; i++){     //Tous les joueurs effectueront les memes actions

      char conf = 'n'; 

      while (conf == 'n'){ //La boucle ne s'arrete pas tant que le joueur n'a pas joué
	
        printf("Tour du joueur %i.\n\n",i);
	print_board(b,board_size);

	get_square(&coord);
	print_stack(b[coord.line][coord.col]); //On affiche le contenu de la case

	ask_confirmation(&conf);
      }

      /*Si on est sorti de la boucle, cela veut dire que le joueur a bien posé son jeton
	donc le code qui va suivre gere le cas ou un jeton est pose (activation de cases etc) */

      play(i,&b,board_size,coord);

      desactivate_board(&b,board_size);
    }
  }

  print_board(b,board_size); //On affiche une derniere fois le tableau a la fin de la partie

  print_winner(b,board_size,j);
  
  return 0;
}
  
     

  
/*   user_coord.line = 2; */
/*   user_coord.col = 1; */

/*   square real_coord = upp_left_square(user_coord); */

/*   push(1,&b[real_coord.line][real_coord.col]); */
/*   push(1,&b[2][0]); */
/*   /\* printf("Apres push : %d\n",is_activated(b[real_coord.line][real_coord.col])); *\/ */
/*   print_matrix(b,board_size); */

/*   play(1,&b,board_size,real_coord); */
/*   /\* printf("Apres play : %d\n",is_activated(b[real_coord.line][real_coord.col])); *\/ */
/*   print_matrix(b,board_size); */

/*   /\* s_list l = empty_s_list(); *\/ */
/*   /\* available_squares(&l,coord,b,board_size); *\/ */
/*   /\* print_s_list(l); *\/ */

/*   return 0; */
/*   //  } */
/*   //  } */
/* } */
