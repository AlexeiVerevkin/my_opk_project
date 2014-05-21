#include "lex_generator.h"
#define ASSIGN_S ":="
#define ENDOL_S ';'
#define BOP_S "begin"
#define PROG_S "program"
#define EOP_S "end."
#define ADD_S '+'
#define SUB_S '-'
#define MULT_S '*'
#define DIV_S '/'
#define DIVN_S "div"
#define DIVOST_S "mod"
#define POINT_S '.'
#define LP1_S '('
#define RP1_S ')'
#define EOS_S '\0'
typedef struct tLex {
	int token;
	char * value;
	struct tLex * next;
};
void append (Lex * plex, int ntoken, char * nvalue) /*include new lex*/
{
	Lex * past = plex;
	if (past == NULL)
	{
		printf("Invalid pointer.\n");
		return;
	}
	if (past->token == NULL)
	{
		past->token = ntoken;
		past->value = nvalue;
	}
	else
	{

		Lex * new_one;
		new_one = (Lex *)malloc(sizeof (Lex));
		if (new_one == NULL)
		{
			printf("Not enough memory.\n");
			return;
		}
		while (past->next != NULL)
		{
			past = past->next;
		}
		new_one->next = NULL;
		new_one->token = ntoken;
		new_one->value = nvalue;
		past->next = new_one;
	}
}
Lex * create_Lex(char * input)
{
	Lex * new_one = (Lex *)malloc(sizeof (Lex));
	if (new_one == NULL)
	{
		printf("Not enough memory.\n");
		return NULL;
	}
	new_one->next = NULL;
	new_one->token = NULL;
	if (input == NULL)
	{
		printf("Invalid input data.\n");
		return NULL;
	}
	char c = *(input++);
	while (c != EOS_S)
	{
		if (isdigit(c))
		{
			char * str = "";
			while (isdigit(c) || c == POINT_S)
			{
				str = strcat(str, c);
				c = *(input++);
			}
			append(new_one, NUM, str);
		}
		if (c == LP1_S)
		{
			append(new_one, LP1, NULL);
			c = *(input++);
		}
		if (c == RP1_S)
		{
			append(new_one, RP1, NULL);
			c = *(input++);
		}
		if (c == ADD_S)
		{
			append(new_one, ADD, NULL);
			c = *(input++);
		}
		if (c == SUB_S)
		{
			append(new_one, SUB, NULL);
			c = *(input++);
		}
		if (c == MULT_S)
		{
			append(new_one, MULT, NULL);
			c = *(input++);
		}
		if (c == DIV_S)
		{
			append(new_one, DIV, NULL);
			c = *(input++);
		}
		if (c == ENDOL_S)
		{
			append(new_one, ENDOL, NULL);
			c = *(input++);
		}
		if (c == EOS)
		{
			append(new_one, EOS, NULL);
		}
		if (isspace(c))
		{
			c = *(input++);
		}
		else
		{
			int check = 0;
			char str [256] = "";
			while (!isspace(c) || c != ';' || c != EOS_S)
			{
				strcat(str, c);
				c = *(input++);
			}
			if (strcmp(str, DIVN_S) == 0)
			{
				append(new_one, DIVN, NULL);
				check++;
			}
			if (strcmp(str,DIVOST_S) == 0)
			{
				append(new_one, DIVOST, NULL);
				check++;
			}
			if (strcmp(str,PROG_S) == 0)
			{
				append(new_one, PROG, NULL);
				check++;
			}
			if (strcmp(str,BOP_S) == 0)
			{
				append(new_one, BOP, NULL);
				check++;
			}
			if (strcmp(str,EOP_S) == 0)
			{
				append(new_one, EOP, NULL);
				check++;
			}
			if (strcmp(str, ASSIGN_S) == 0)
			{
				append(new_one, ASSIGN, NULL);
				check++;
			}
			if (check == 0)
			{
				append(new_one, ID, str);
			}
		}
	}
	append(new_one, EOS, NULL);
	return new_one;
}
Lex * get_next(Lex * plex)
{
	return plex->next;
}
int Lex_token(Lex * plex)
{
	return plex->token;
}
char * Lex_value(Lex * plex)
{
	return plex->value;
}
void destroy_Lex(Lex * plex)
{
	if (plex == NULL)
	{
		printf("It hasbeen already freed.\n");
		return;
	}
	Lex * past = plex;
	Lex * current = past->next;
	while (current != NULL)
	{
		free(past);
		past = current;
		current = past->next;
	}
	free(past);
}