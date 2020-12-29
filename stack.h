#ifndef _STACK_H
#define _STACK_H

//Aliase du type int en type player
typedef int player;

//Creation du type abstrait stack
typedef struct stack_base* stack;

/*@requires nothing
  assigns une nouvelle pile en mémoire
  ensures retourne une pile vide*/
stack empty_stack();

int is_empty_stack(stack s);

int is_activated(stack s);

void desactivate(stack* sp);

void push(player p, stack* sp);

player get_summit(stack s);

void pop(stack* sp);

void full_pop(stack* sp);

void free_stack(stack *sp);

void print_stack(stack s);

#endif
