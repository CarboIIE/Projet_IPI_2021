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

/*@requires s valide
  assigns nothing
  ensures retourne 1 si la pile est vide, 0 sinon */
int is_empty_stack(stack s);

/*@requires s valide
  assigns nothing
  ensures retourne 1 si la case a ete activee, 0 sinon */
int is_activated(stack s);

/*@requires *sp valide et d'adresse valide, sp valide
  assigns *sp
  ensures passe (*sp)->activated a 1 si nécessaire */
void desactivate(stack* sp);

/*@requires *sp valide et d'adresse valide, sp valide
  assigns *sp et un nouveau maillon contenant p
  ensures ajoute le jeton du joueur p a la pile *sp */
void push(player p, stack* sp);

/*@requires s valide
  assigns nothing
  ensures retoutrne le sommet de la pile s */
player get_summit(stack s);

/*@requires *sp valide et d'adresse valide, sp valide
  assigns *sp
  ensures supprime le sommet de la pile *sp */
void pop(stack* sp);

/*@requires *sp valide et d'adresse valide; sp valide
  assigns *sp
  ensures depile tous les elements d'une pile */
void full_pop(stack* sp);

/*@requires *sp valide et d'adresse valide, sp valide
  assigns *sp
  ensures libere *sp */
void free_stack(stack *sp);

/*@requires s valide
  assigns nothing
  ensures affiche s */
void print_stack(stack s);

#endif
