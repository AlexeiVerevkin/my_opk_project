#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include "Lex_gen.h"
#include "tree.h"
#include "code_translator.h"
int main()
{
	FILE * out;
	out = fopen("errors.txt","w");
	int i = 1;
<<<<<<< HEAD
<<<<<<< HEAD
	Lex * test = create_Lex("begin call(1,i); begin y := 12+13; end");
=======
	Lex * test = create_Lex("count(1,1);");
>>>>>>> 2c3966412189431bdc21e7392dfe67bf62e747dc
=======
	Lex * test = create_Lex("count(1,1);");
>>>>>>> 2c3966412189431bdc21e7392dfe67bf62e747dc
	Node * past = get_first(test);
	Branch * tree;
	while (past != NULL)
	{
		printf("%d token is %d with value %s\n", i, get_token(past), get_value(past));
		past = get_next(past);
		i++;
	}
	tree = create_tree(test, out);
	fclose(out);
	if (tree == NULL)
	{
		printf("Unable to create tree.\n");
	}
	destroy_Lex(test);
	tree_print(tree);
	translate(tree, "out.c");
	tree_free(tree);
	_CrtDumpMemoryLeaks();
	return 0;
}