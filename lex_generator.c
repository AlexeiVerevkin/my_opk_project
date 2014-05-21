#include "lex_generator.h"
#define ASSIGN ":="
#define ENDOL ';'
#define BOP "begin"
#define PROG "program"
#define EOP "end."
#define ADD_S '+'
#define SUB_S '-'
#define MULT_S '*'
#define DIV '/'
#define DIVN "div"
#define DIVOST "mod"
#define POINT '.'
#define LP1_S '('
#define RP1_S ')'
#define EOS '\0'
typedef struct tLex {
	int token;
	char * value;
	struct tLex * next;
};
void append (Lex * plex, int ntoken, char * nvalue) /*include new lex*/
{
	Lex * new_one;
	Lex * past = plex;
	if (past == NULL)
	{
		printf("Invalid pointer.\n");
		return;
	}
	while (past->next != NULL)
	{
		past = past->next;
	}
	new_one = (Lex *)malloc(sizeof (Lex));
	if (new_one == NULL)
	{
		printf("Not enough memory.\n");
		return;
	}
	new_one->next = NULL;
	new_one->token = ntoken;
	new_one->value = nvalue;
	past->next = new_one;
}
Lex * create(char * input)
{
	Lex * new_one = (Lex *)malloc(sizeof (Lex));
	if (new_one == NULL)
	{
		printf("Not enough memory.\n");
		return NULL;
	}
	new_one->next = NULL;
	if (input == NULL)
	{
		printf("Invalid input data.\n");
		return NULL;
	}
	char c = getc(input);
	while (c != EOS)
	{
		char * str;
		if (isdigit(c))
		{
			while (isdigit(c) || c == POINT)
			{
				str = strcat(str, c);
				c = getc(input);
			}
			append(new_one, NUM, str);
		}
		if (c == LP1_S)
		{
			append(new_one, LP1, NULL);
		}
		if (c == RP1_S)
		{
			append(new_one, RP1, NULL);
		}
		if (c == ADD_S)
		{
		}
	}
}