#include "include/function.h"
#include "include/evento.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Parsea los argumentos entregados por consola.
 * segun esto se ejecutara alguna funcion del indice
 * del arreglo de funciones. Es la variable run quien
 * dicta que funcion ejecutar.
 */
void parse_action(int counter, char *values[]){
	evento e;
	int run = -1;
	int error = -1;

	switch(counter) {
		case 1:
			fprintf(stderr, "Error. Debe ingresar los argumentos\n");
			break;

		case 2:
			if ( ! strcmp("list", values[1]))
				run = 0;
			else if ( ! strcmp("clear", values[1]))
				run = 1;
			else if (comando_valido(values[1]) < 0)
				error = 0;
			else
				error = 2;
			break;

		case 3:
			if((e.id = atoi(values[2])) == 0)
				error = 3;
			else {
				if ( ! strcmp("do", values[1]))
					run = 6;
				else if ( ! strcmp("get", values[1]))
					run = 3;
				else if ( ! strcmp("delete", values[1]))
					run = 4;
				else if (comando_valido(values[1]) < 0)
					error = 0;
				else
					error = 2;
			}
			break;
		case 4:
			snprintf(e.titl, sizeof(char)*60, "%s", values[2]);
			snprintf(e.desc, sizeof(char)*120, "%s", values[3]);
			e.id = 0;
			e.estado = 0;
			if ( ! strcmp("new", values[1])) 
				run = 2;
			else 
				error = 0;
			break;
		case 5:
			if ( ! strcmp("update", values[1])){
				if ( ! strcmp("-t", values[3]) ||  ! strcmp("-d", values[3])) {
					if((e.id = atoi(values[2])) == 0)
						error = 3;
					else {
						switch(values[3][1]) {
							case 't':
								e.estado = 2;
								snprintf(e.titl, sizeof(char)*60, "%s", values[4]);
								break;

							case 'd':
								e.estado = 3;
								snprintf(e.desc, sizeof(char)*120, "%s", values[4]);
						}
						run = 5;
					}
				} else if(comando_valido(values[1]) == 3)
					error = 1;
				else
					error = 2;
			} else
				error = 0;
			break;
		case 6:
			if ( ! strcmp("update", values[1])){
				if ( ! strcmp("-b", values[3])) {
					if((e.id = atoi(values[2]))
					 == 0) 
						error = 3;
					else {
						e.estado = 4;
						snprintf(e.titl, sizeof(char)*60, "%s", values[4]);
						snprintf(e.desc, sizeof(char)*120, "%s", values[5]);
						run = 5;
					}
				} else 
					error = 1;
			} else
				error = 0;
			break;
	}

	if (run >= 0) {
		funciones_base[run](&e);
	} else if (error >= 0) {
		switch(error){
			case 0: 
				fprintf(stderr, "El comando seleccionado no existe.\nComandos válidos: new, get, delete, update, do, list, clear.\n"); 
				break;
			case 1:
				fprintf(stderr, "Argumentos para el comando 'update' no reconocido.\n");
				break;
			case 2:
				fprintf(stderr, "Faltan argumentos.\n");
				break;
			case 3:
				fprintf(stderr, "Argumento inválido.\n");
				break;
			default:
				fprintf(stderr, "Error desconocido.\n");
		}
	}
}

/**
 * Devuelve un -1 en caso de que no se reconozca el comando.
 * De otro modo devuelve un entero del 0 al 6 indicando el comando seleccionado.
 */
int comando_valido(char *value){
	if ( ! strcmp("new", value)){
		return 0;
	} else if ( ! strcmp("get", value)){
		return 1;
	} else if ( ! strcmp("delete", value)){
		return 2;
	} else if ( ! strcmp("update", value)){
		return 3;
	} else if ( ! strcmp("do", value)){
		return 4;
	} else if ( ! strcmp("list", value)){
		return 5;
	} else if ( ! strcmp("clear", value)){
		return 6;
	}
	return -1;
}

/**
 * Inicializa el arreglo de punteros a funciones asignando
 * a cada indice una funcion. Luego este arreglo se utiliza
 * desde el parseador.
 */
void inicializar() {
	funciones_base[0] = &listar_eventos;
	funciones_base[1] = &vaciar_eventos;
	funciones_base[2] = &nuevo_evento;
	funciones_base[3] = &mostrar_evento;
	funciones_base[4] = &eliminar_evento;
	funciones_base[5] = &modificar_evento;
	funciones_base[6] = &concretar_evento;
}