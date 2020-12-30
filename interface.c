#include "interface.h"
#include "board.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int get_players(){
  
  char buf[256];
  int players_nb;

  printf("Veuillez saisir le nombre de joueurs :\n\n");
  fgets(buf,256,stdin);
  sscanf(buf,"%d",&players_nb);
  printf("\n");

  return players_nb;
}

int get_board_size(){
  
  char buf[256];
  int board_size;

  printf("Veuillez saisir la taille du plateau souhaitée :\n\n");
  fgets(buf,256,stdin);
  sscanf(buf,"%d",&board_size);
  printf("\n");

  return board_size;
}

void print_board(board b, int board_size){

  int i,j;

  //On va afficher le plateau en traitant de maniere exhaustive les valeurs de i et de j
  for (i = 0; i < board_size + 2; i++){
    for (j = 0; j < board_size + 2; j++){

      if (i == 0 && j == 0)
	printf(" ");

      else if ((i == 1 && j == 0) || (i == 1 && j == board_size + 1))
	printf("-");

      else if (i == 1 && j == 1)
	printf("+-");

      else if (i == 1 && j > 1 && j <= board_size)
	printf("--");

      else if (j == 1 && i != 1)
	printf("|");

      else if (i == 0 && j > 1)
	printf("%d ",j-1);

      else if (j == 0 && i > 1)
	printf("%d",i-1);

      else{
	if (!is_empty_stack(b[i-2][j-2]))
	  printf("%d ",get_summit(b[i-2][j-2]));
	else
	  printf("  ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

void get_square(square* coordp){
  
  char buf[256];
  int line,col;

  printf("Quelle case choisissez-vous ?\n");
  fgets(buf,256,stdin);
  sscanf(buf,"%d %d",&line,&col);
  printf("\n");
  coordp->line = line-1;
  coordp->col = col-1;
}

void ask_confirmation(char* conf_pointer){
  char buf[256];

  printf("Voulez-vous jouer ici ?\n\n");
  fgets(buf,256,stdin);
  sscanf(buf,"%c",conf_pointer);
  printf("\n");
}

void print_winner(board b, int board_size, int nb_players){
  int* players_res = calloc(nb_players,sizeof(int)); //Tableau qui compte le nombre de jetons de chaque joueur sur le dessus du plateau à la fin de la partie
  int i,k;

  for (i = 0; i < nb_players; i++){
    for (k = 0; k < nb_players; k++)
      players_res[get_summit(b[i][k])-1]++;
  }
  
  int index_of_max;

  for (i = 1; i < nb_players; i++){
    if (players_res[i] > players_res[index_of_max]){
      index_of_max = i;
    }
  }

  free(players_res);

  printf("Le joueur %d remporte la partie !\n",index_of_max + 1);
}
