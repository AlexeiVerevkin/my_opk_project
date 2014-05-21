#ifndef LEX_GENERATOR_H
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LEX_GENERATOR_H
#define ID 0 /*Identificator of variable, function*/
#define NUM 1 /*Number, justsimple number*/
#define LP1 5 /*<(>*/
#define RP1 6 /*<)>*/
#define LP2 7 /*<{>*/
#define RP2 8 /*<}>*/
#define LP3 9 /*<[>*/
#define RP3 10 /*<]>*/
#define SEMIC 11 /*<;>*/
#define EMPTY_P 12 /*<()>*/
typedef struct tLex Lex;
Lex * create_Lex(char * input);/*create a new current of Lex*/
Lex * get_next(Lex * plex); /*return next lex*/
void append(Lex * plex); /*include new lex*/
int Lex_token(Lex * pLex); /* return token value of Lex */
char * Lex_value(Lex * plex); /*return a char expression for this Lex (ID or NUMB for example)*/
int Lex_length(Lex * plex); /*return length of current Lex current*/
void destroy_Lex(Lex * pLex);
#undef LEX_GENERATOR_H
#endif