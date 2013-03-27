#include <stdio.h>
#include "include/evento.h"
#include "function.h"

int main(int argc, char *argv[])
{
	inicializar();
	parse_action(argc, argv);

	return 0;
}
