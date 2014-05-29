#ifndef LEX_GEN_H
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEX_GEN_H
#define NUM -1 /*Number token*/
#define ID -2 /*variable token*/
#define ASSIGN -3 /*<:=> token*/
#define F_ID -4 /*Function's ID token*/
#define ARR_ID -5 /*Array ID token*/
#define BEGIN -6 /*begin token*/
#define END -7 /*end token*/
#define IF -8 /*if-construction token*/
#define ELSE -9 /*else-construction token*/
#define WHILE -10 /*while construction token*/
#define PROGR -11 /*programm header token*/
#define LOE -12 /*<= token*/
#define MOE -13 /*>= token*/
#define EQ -14 /*== token*/
typedef struct tLex Lex; /*Current of Lexes*/
typedef struct tNode Node; /*Node of one Lex*/
Lex * create_Lex(char * input); /*Create a current of Lex*/
Node * get_next (Node * in); /*Get Next Node */
Node * get_prev(Node * in); /*Get Previous Node*/
void destroy_Lex(Lex * plex); /*Free memory from Lex*/
int get_token(Node * in); /*Get token from Node*/
Node * get_first(Lex * plex); /*Get first Node of Lex*/
Node * get_last(Lex * plex); /*Get last Node of Lex*/
char * get_value(Node * in); /*Get value of Next*/
#undef LEX_GEN_H
#endif