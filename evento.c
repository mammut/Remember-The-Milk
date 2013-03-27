#include <stdio.h>
#include "include/evento.h"

/**
 *
 */
void nuevo_evento(evento *e){

}

/**
 *
 */
void mostrar_evento(evento *e){

}

/**
 *
 */
void eliminar_evento(evento *e){

}

/**
 *
 */
void modificar_evento(evento *e){

}

/**
 *
 */
void concretar_evento(evento *e){

}

/**
 *
 */
void listar_eventos(){

}

/**
 * Elimina el registro de eventos.
 */
void vaciar_eventos(){
	FILE *db;

	if ( (db = fopen("db.dat", "wb")) == NULL) {
		fprintf(stderr, "Error. No se pudo abrir el archivo 'db.dat'\n");
		return;
	}

	fclose(db);
}
