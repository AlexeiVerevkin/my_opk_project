#ifndef TREE_H
#include <stdlib.h>
#include "Lex_gen.h"
#define TREE_H
#define STMT 1 /*statement - basic*/
#define LEXPR 2 /*left part of statement*/
#define EXPR 3 /*some expression*/
#define ARITH 4 /*arithmeticl equation*/
#define OPER 5 /*binary operator value*/
#define CALL 6 /*functions call*/
#define ARR 7 /*array call*/
#define F_ARGS 8 /*argument of functions*/
#define ARR_ARGS 9 /*arguments of array*/
#define LINE 10 /*line that splits in statement and call*/
#define BLOCK 11 /*block of lines*/
typedef struct tBranch Branch;
Branch * create_tree(Lex * plex); /*returns poiter to the root of the created tree of Lexems*/
void tree_print(Branch * root);/*print out AST*/
void tree_free(Branch * root);/*free memory after tree using*/
int child_n(Branch * root);/*return the number of children*/
int get_mean(Branch * root); /*return the meaning value*/
char * t_value(Branch * root); /*return value of Node*/
Branch ** kids(Branch * root); /*return pointer to the kids array*/
#undef TREE_H
#endif