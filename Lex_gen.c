#include "Lex_gen.h"
#include <stdio.h>

struct tLex
{
	Node * first;
	Node * last;
};

struct tNode
{
	int token;
	char * value;
	Node * prev;
	Node * next;
};

void append(Lex * plex, int token, char * data) /*function*/
{
	if (plex != NULL)
	{
		Node * new_one = (Node *)malloc(sizeof (Node));
		Node * past;
		if (new_one == NULL)
		{
			printf("Not enough memory.\n");
			return;
		}
		else
		{
			new_one->value = data;
			new_one->token = token;
			new_one->next = NULL;
			if (plex->first == NULL && plex->last == NULL)
			{
				plex->first = new_one;
				plex->last = new_one;
				new_one->prev = NULL;
			}
			else
			{
				past = plex->last;
				past->next = new_one;
				new_one->prev = past;
				plex->last = new_one;
			}
		}
	}
	else
	{
		printf("Invalid pointer.\n");
		return;
	}
}

Lex * create_Lex(char * input)
{
	Lex * new_one;
	new_one = (Lex *)malloc(sizeof (Lex));
	if (new_one == NULL)
	{
		printf("Not enough memory.\n");
		return NULL;
	}
	new_one->first = NULL;
	new_one->last = NULL;
	char c = *(input++);
	while (c != '\0')
	{
		if (isdigit(c))
		{
			int i = 0;
			char str[256] = "";
			while (isdigit(c) || c == '.')
			{
				str[i] = c;
				c = *(input++);
				i++;
			}
			append(new_one, NUM, strdup(str));
		}
		else
		{
			if (isalpha(c))
			{
				int i = 0;
				int true = 0;
				char str[256] = "";
				while (isalpha(c) || (isdigit(c) || c == '_'))
				{
					str[i] = c;
					c = *(input++);
					i++;
				}
				if (strcmp(str, "if") == 0)
				{
					append(new_one, IF, NULL);
					true++;
				}
				if (strcmp(str, "else") == 0)
				{
					append(new_one, ELSE, NULL);
					true++;
				}
				if (strcmp(str, "begin") == 0)
				{
					append(new_one, BEGIN, NULL);
					true++;
				}
				if (strcmp(str, "end") == 0)
				{
					append(new_one, END, NULL);
					true++;
				}
				if (strcmp(str, "while") == 0)
				{
					append(new_one, WHILE, NULL);
					true++;
				}
				if (true == 0)
				{
					if (c == '(')
					{
						append(new_one, F_ID, strdup(str));
						true++;
					}
					if (c == '[')
					{
						append(new_one, ARR_ID, strdup(str));
						true++;
					}
					if (true == 0)
					{
						append(new_one, ID, strdup(str));
					}
				}
			}
			else
			{
				if (c == ':')
				{
					char k = *input;
					printf("%c\n", k);
					if (k == '=')
					{
						append(new_one, ASSIGN, NULL);
						c = *(input++);
					}
					else
					{
						append(new_one, ':', NULL);
					}
				}
				else
				{
					if (c == '#')
					{
						c = *(input++);
						while (c != '#')
						{
							if (c == '\0')
							{
								break;
							}
							c = *(input++);
						}
						c = *(input++);
					}
					if (!isspace(c))
					{
						append(new_one, (int)c, NULL);
					}
				}
				c = *(input++);
			}
		}
	}
	return new_one;
}

Node * get_next(Node * in)
{
	if (in == NULL)
	{
		printf("Invalid pointer.\n");
		return NULL;
	}
	return in->next;
}

Node * get_prev(Node * in)
{
	if (in == NULL)
	{
		printf("Invalid pointer.\n");
		return NULL;
	}
	return in->prev;
}

void destroy_Lex(Lex * plex)
{
	Node * past;
	if (plex == NULL)
	{
		return;
	}
	past = plex->first;
	while (past != NULL)
	{
		Node * new_past = past;
		past = past->next;
		if (new_past->value != NULL)
		{
			free(new_past->value);
		}
		free(new_past);
	}
	free(plex);
}

int get_token(Node * in)
{
	if (in == NULL)
	{
		printf("Invalid pointer.\n");
		return NULL;
	}
	return in->token;
}

char * get_value(Node * in)
{
	if (in == NULL)
	{
		printf("Invalid pointer.\n");
		return NULL;
	}
	return in->value;
}

Node * get_first(Lex * plex)
{
	if (plex == NULL)
	{
		printf("Invalid pointer.\n");
		return NULL;
	}
	return plex->first;
}

Node * get_last(Lex * plex)
{
	if (plex == NULL)
	{
		printf("Invalid pointer.\n");
		return NULL;
	}
	return plex->last;
}