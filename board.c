#include "board.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

/*----------------- DEFINITIONS, FONCTIONS ET PROCEDURES SUR LES CASES -----------------*/

//Creation de la structure de maillon pour implementer avec les listes chainees
struct square_list_base{
  square coord;
  s_list next;
};

s_list empty_s_list(){
  return NULL;
}

int is_empty_s_list(s_list l){
  return l == NULL;
}

void push_s_list(square real_coord, s_list* lp){
  s_list res = malloc(sizeof(struct square_list_base));
  res->coord = real_coord;
  res->next = *lp;
  *lp = res;
}

square pop_s_list(s_list* lp){
  square real_coord = (*lp)->coord;
  s_list tmp = *lp;
  *lp = (*lp)->next;
  free(tmp);
  return real_coord;
}

void print_s_list(s_list l){
  while (l != NULL){
    printf("(%d,%d)",low_right_square(l->coord).line,low_right_square(l->coord).col);
    l = l->next;
  }
  printf("\n");
}

square left_square(square coord){
  square left = coord;
  left.col--;
  return left;
}

square upper_square(square coord){
  square upper = coord;
  upper.line--;
  return upper;
}

square right_square(square coord){
  square right = coord;
  right.col++;
  return right;
}

square lower_square(square coord){
  square lower = coord;
  lower.line++;
  return lower;
}

square upp_left_square(square coord){
  return upper_square(left_square(coord));
}

square low_right_square(square coord){
  return lower_square(right_square(coord));
}

void available_squares(s_list* lp, square real_coord, board b, int board_size){

  square coord = real_coord;

  if (coord.col == 0 && coord.line == 0){
    
    square right = right_square(coord);
    square lower = lower_square(coord);

    if (!is_activated(b[right.line][right.col]))
      push_s_list(right,lp);
    
    if (!is_activated(b[lower.line][lower.col]))
      push_s_list(lower,lp);
  }

  else if (coord.line == 0 && coord.col == board_size - 1){
    
    square left = left_square(coord);
    square lower = lower_square(coord);

    if (!is_activated(b[left.line][left.col]))
      push_s_list(left,lp);
    
    if (!is_activated(b[lower.line][lower.col]))
      push_s_list(lower,lp);
  }

  else if (coord.line == board_size - 1 && coord.col == 0){
    
    square upper = upper_square(coord);
    square right = right_square(coord);

    if (!is_activated(b[upper.line][upper.col]))
      push_s_list(upper,lp);
    
    if (!is_activated(b[right.line][right.col]))
      push_s_list(right,lp);
  }

  else if (coord.line == board_size - 1 && coord.col == board_size - 1){
    
    square left = left_square(coord);
    square upper = upper_square(coord);

    if (!is_activated(b[upper.line][upper.col]))
      push_s_list(upper,lp);
    
    if (!is_activated(b[left.line][left.col]))
      push_s_list(left,lp);
  }

  else if (coord.col == 0 && coord.line > 0 && coord.line <= board_size){
    
    square upper = upper_square(coord);
    square right = right_square(coord);
    square lower = lower_square(coord);
  
    if (!is_activated(b[upper.line][upper.col]))
      push_s_list(upper,lp);
    
    if (!is_activated(b[right.line][right.col]))
      push_s_list(right,lp);
    
    if (!is_activated(b[lower.line][lower.col]))
      push_s_list(lower,lp);
  }

  else if (coord.line == 0 && coord.col > 0 && coord.col <= board_size){
    
    square left = left_square(coord);
    square right = right_square(coord);
    square lower = lower_square(coord);

    if (!is_activated(b[left.line][left.col]))
      push_s_list(left,lp);
    
    if (!is_activated(b[right.line][right.col]))
      push_s_list(right,lp);
    
    if (!is_activated(b[lower.line][lower.col]))
      push_s_list(lower,lp);
  }

  else if (coord.col == board_size - 1 && coord.line > 0 && coord.line <= board_size){
       
    square left = left_square(coord);
    square upper = upper_square(coord);
    square lower = lower_square(coord);

    if (!is_activated(b[upper.line][upper.col]))
      push_s_list(upper,lp);
    
    if (!is_activated(b[lower.line][lower.col]))
      push_s_list(lower,lp);
    
    if (!is_activated(b[left.line][left.col]))
      push_s_list(left,lp);
  }

  else if (coord.line == board_size - 1 && coord.col > 0 && coord.col <= board_size){
    
    square left = left_square(coord);
    square upper = upper_square(coord);
    square right = right_square(coord);

    if (!is_activated(b[left.line][left.col]))
      push_s_list(left,lp);
    
    if (!is_activated(b[upper.line][upper.col]))
      push_s_list(upper,lp);
    
    if (!is_activated(b[right.line][right.col]))
      push_s_list(right,lp);
  }

  /*Si on arrive ici sans etre entre dans un if, alors on n'est ni sur un bord
    ni dans un coin donc on rajoute les cases adjacentes pas encore activees */

  else{
    square left = left_square(coord);
    square upper = upper_square(coord);
    square right = right_square(coord);
    square lower = lower_square(coord);

    if (!is_activated(b[left.line][left.col]))
      push_s_list(left,lp);

    if (!is_activated(b[upper.line][upper.col]))
      push_s_list(upper,lp);
  
    if (!is_activated(b[right.line][right.col]))
      push_s_list(right,lp);
  
    if (!is_activated(b[lower.line][lower.col]))
      push_s_list(lower,lp);
  }
}

/*-------------------- DEFINITIONS, FONCTIONS ET PROCEDURES DU PLATEAU -----------------*/

board empty_board(int n){
  board b = malloc(n*sizeof(stack*));
  int i,j;
  
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++)
      b[i] = malloc(n*sizeof(stack));

    for (j = 0; j < n; j++)
      b[i][j] = empty_stack();
  }

  return b;
}

int is_board_full(board b, int board_size){
  int i,j;

  for (i = 0; i < board_size; i++){
    for (j = 0; j < board_size; j++){
      if (is_empty_stack(b[i][j]))      //On regarde si toutes les piles du plateau sont pleines
	return 0;
    }
  }

  return 1;
}

void free_board(board* bp, int board_size){
  int i,j;

  for (i = 0; i < board_size; i++){
    for (j = 0; j < board_size; j++)
      full_pop(bp[i][j]);
  }

  free(bp);
}

void desactivate_board(board* bp, int board_size){

  int i,j;

  for (i = 0; i < board_size; i++){
    for (j = 0; j < board_size; j++){
      if (is_activated((*bp)[i][j]))
	desactivate(&(*bp)[i][j]);
    }
  }
}

void print_matrix(board b, int board_size){
  int i,j;
  for (i = 0; i < board_size; i++){
    for (j = 0; j < board_size; j++){
      if (!is_empty_stack(b[i][j]))
	printf("%2d",get_summit(b[i][j]));
      else
	printf("%2d",0);
    }
    printf("\n");
  }
  printf("\n");
}

void play(player j, board* bp, int board_size, square real_coord){

  if (get_summit((*bp)[real_coord.line][real_coord.col]) != j){ //Cas ou il n'y a pas besoin d'activer
    push(j,&(*bp)[real_coord.line][real_coord.col]);
    return;
  }

  pop(&(*bp)[real_coord.line][real_coord.col]); //Arriver ici signifie que la case doit etre activee donc il faut pop

  s_list l = empty_s_list();
  available_squares(&l,real_coord,*bp,board_size);

  while (!is_empty_s_list(l)){
    //s_list tmp = l;
    square tmp_coord = pop_s_list(&l);
    play(j,bp,board_size,tmp_coord);
  }

  free(l);
}
