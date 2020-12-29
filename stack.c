#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

//Creation de la structure de maillon pour implementer avec les listes chainees
struct stack_base{
  player p;
  int activated;
  struct stack_base* next;
};

stack empty_stack(){
  stack res = malloc(sizeof(struct stack_base));
  res->p = 0;
  res->activated = 0;
  res->next = NULL;
  return res;
}

int is_empty_stack(stack s){
  return s->next == NULL; //La case peut quand meme avoir ete activee et s->p vaut 0
}                         //quand s->next vaut NULL (et inversement)

int is_activated(stack s){
  return s->activated;
}

void desactivate(stack* sp){
  (*sp)->activated--;
}

void push(player play, stack* sp){
  if (!is_activated(*sp)){
    stack res = empty_stack();
    res->p = play;
    //res->activated = 0; implicite car deja fait dans empty_stack()
    res->next = *sp;
    *sp = res;
  }

  return; //On sort de push sans rien faire si la case a deja ete activee ce tour
}

player get_summit(stack s){
  return s->p;
}

void pop(stack* sp){
  if (!is_empty_stack(*sp)){
    stack tmp = *sp;
    *sp = (*sp)->next;
    (*sp)->activated = 1;
    free(tmp);
  }
  return;
}

void full_pop(stack* sp){
  while (!is_empty_stack(*sp))
    pop(sp);
}

void free_stack(stack* sp){
  full_pop(sp);
  free(sp);
}

void print_stack(stack s){
  while (s != NULL){
    printf("%2d\n",s->p);
    s = s->next;
  }
  printf("---\n\n");
}
