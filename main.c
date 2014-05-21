#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include "lex_generator.h"
int main()
{
	Lex * test = create_Lex("x := 10 + 5 - 4");
	while (test != NULL)
	{
		printf("%d", Lex_token(test));
		test = get_next(test);
	}
	_CrtDumpMemoryLeaks();
	return 0;
}