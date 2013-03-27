#include "function.h"
#include "include/evento.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void parse_action(int counter, char *values[]){
	evento e;

	switch(counter) {
		case 1:
			fprintf(stderr, "Error. Debe ingresar los arguentos\n");
			return;
			break;

		case 2:
			if ( ! strcmp("list", values[1]))
				listar_eventos();
			else if ( ! strcmp("clear", values[1]))
				vaciar_eventos();
			else
				printf("Argumento inválido\n");
			break;

		case 3:
			e.id = atoi(values[2]);
			if ( ! strcmp("do", values[1]))
				concretar_evento(&e);
			else if ( ! strcmp("get", values[1]))
				mostrar_evento(&e);
			else if ( ! strcmp("delete", values[1]))
				eliminar_evento(&e);
			else
				printf("Argumento inválido\n");
			break;

		case 4:
			sprintf(e.titl, "%s", values[2]);
			sprintf(e.desc, "%s", values[3]);
			e.id = 0;
			e.estado = 0;
			if ( ! strcmp("new", values[1]))
				nuevo_evento(&e);
			else
				printf("Argumento inválido\n");
			break;

		case 5:
			if ( ! strcmp("update", values[1]) && ( ! strcmp("-t", values[3]) ||  ! strcmp("-d", values[3]))) {
				e.id = atoi(values[2]);
				switch(values[3][1]) {
					case 't':
						e.estado = 2;
						sprintf(e.titl, "%s", values[4]);
						break;

					case 'd':
						e.estado = 3;
						sprintf(e.desc, "%s", values[4]);
				}
				modificar_evento(&e);
			}
			else
				printf("Argumento inválido\n");
			break;

		case 6:
			if ( ! strcmp("update", values[1]) && ! strcmp("-b", values[3])) {
				e.id = atoi(values[2]);
				e.estado = 4;
				sprintf(e.titl, "%s", values[4]);
				sprintf(e.desc, "%s", values[5]);
				modificar_evento(&e);
			}else {
				printf("Argumento inválido\n");
			}
			break;

		default:
			printf("Argumento inválido\n");
	}
}

void inicializar() {
	funciones_base[0] = &nuevo_evento;
	funciones_base[1] = &mostrar_evento;
	funciones_base[2] = &eliminar_evento;
	funciones_base[3] = &modificar_evento;
	funciones_base[4] = &concretar_evento;

	funciones_base2[0] = &listar_eventos;
	funciones_base2[1] = &vaciar_eventos;
}