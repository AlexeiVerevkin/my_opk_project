#include "code_translator.h"
char * create_string(Branch * root);
int shift;
void translate(Branch * root, char * filename)
{
	FILE * out;
	out = fopen(filename, "w");
	if (out == NULL)
	{
		printf("Sorry, but we can't create file %s.\n", filename);
		return;
	}
	if (root == NULL)
	{
		fprintf(out, "/*Invalid code was translated. Please try again later.*/");
	}
	else
	{
		shift = 0;
		fprintf(out, "%s", create_string(root));
	}
	fclose(out);
}
char * create_string(Branch * root)
{
	int past_shift;
	int k;
	char str[30000];
	int mean = get_mean(root);
<<<<<<< HEAD
<<<<<<< HEAD
	if (mean == BLOCK)
	{
		past_shift = shift;
		shift = shift + 4;
		int i;
		strcpy(str, "{\n");
		for (i = 0; i < child_n(root); i++)
		{
			for (k = 0; k < shift; k++)
			{
				strcat(str, " ");
			}
			strcat(str, create_string(kids(root)[i]));
			strcat(str, "\n");
		}
		for (k = 0; k < past_shift; k++)
		{
			strcat(str, " ");
		}
		strcat(str, "}");
	}
=======
>>>>>>> 2c3966412189431bdc21e7392dfe67bf62e747dc
=======
>>>>>>> 2c3966412189431bdc21e7392dfe67bf62e747dc
	if (mean == LINE)
	{
		strcpy(str, create_string(kids(root)[0]));
		strcat(str, ";");
	}
	if (mean == STMT)
	{
		strcpy(str,create_string(kids(root)[0]));
		strcat(str, " = ");
		strcat(str, create_string(kids(root)[1]));
	}
	if (mean == LEXPR)
	{
		strcpy(str,create_string(kids(root)[0]));
	}
	if (mean == ID)
	{
		strcpy(str, (t_value(root)));
	}
	if (mean == EXPR)
	{
		strcpy(str,create_string(kids(root)[0]));
	}
	if (mean == ARITH)
	{
		int i;
		strcpy(str,"(");
		for (i = 0; i < child_n(root); i++)
		{
			strcat(str, create_string(kids(root)[i]));
		}
		strcat(str, ")");
	}
	if (mean == NUM)
	{
		strcpy(str, t_value(root));
	}
	if (mean == '+')
	{
		strcpy(str," + ");
	}
	if (mean == '-')
	{
		strcpy(str, " - ");
	}
	if (mean == '*')
	{
		strcpy(str, " * ");
	}
	if (mean == '/')
	{
		strcpy(str, " / ");
	}
	if (mean == CALL)
	{
		strcpy(str, create_string(kids(root)[0]));
		strcat(str, create_string(kids(root)[1]));
	}
	if (mean == F_ID)
	{
		strcpy(str, t_value(root));
	}
	if (mean == F_ARGS)
	{
		if (child_n(root) != 0)
		{
			int i;
			strcpy(str, "(");
			for (i = 0; i < child_n(root) - 1; i++)
			{
				strcat(str, create_string(kids(root)[i]));
				strcat(str, ",");
			}
			strcat(str, create_string(kids(root)[child_n(root) - 1]));
			strcat(str, ")");
		}
		else
		{
			strcpy(str, "()");
		}
	}
	if (mean == ARR)
	{
		strcpy(str, create_string(kids(root)[0]));
		strcat(str, create_string(kids(root)[1]));
	}
	if (mean == ARR_ID)
	{
		strcpy(str, t_value(root));
	}
	if (mean == ARR_ARGS)
	{
		strcpy(str, "[");
		strcat(str, create_string(kids(root)[0]));
		strcat(str, "]");
	}
	if (mean == ARR)
	{
		strcpy(str, create_string(kids(root)[0]));
		strcat(str, create_string(kids(root)[1]));
	}
	if (mean == ARR_ID)
	{
		strcpy(str, t_value(root));
	}
	if (mean == ARR_ARGS)
	{
		strcpy(str, "[");
		strcat(str, create_string(kids(root)[0]));
		strcat(str, "]");
	}
	if (mean == ARR)
	{
		strcpy(str, create_string(kids(root)[0]));
		strcat(str, create_string(kids(root)[1]));
	}
	if (mean == ARR_ID)
	{
		strcpy(str, t_value(root));
	}
	if (mean == ARR_ARGS)
	{
		strcpy(str, "[");
		strcat(str, create_string(kids(root)[0]));
		strcat(str, "]");
	}
	return str;
}