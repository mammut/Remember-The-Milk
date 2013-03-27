#include <stdio.h>
#include "include/evento.h"
#include "function.h"

int main(int argc, char *argv[])
{
	//parse_action(argc, argv);

	/* nuevo_evento */
	evento e;

	e.id = 0;
	sprintf(e.titl, "Comprar leche");
	sprintf(e.desc, "Lorem ipsum dolor sit amet, consectetur adipisicing elit. Odio molestias soluta");
	e.estado = 0;

	nuevo_evento(&e);

	return 0;
}
