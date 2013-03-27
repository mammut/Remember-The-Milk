#include <stdio.h>
#include "include/evento.h"

/**
 *
 */
void nuevo_evento(evento *e){
	FILE *db;
	evento reader;

	if ( (db = fopen("db.dat", "ab+")) == NULL) {
		fprintf(stderr, "Error. No se pudo abrir el archivo 'db.dat'\n");
		return;
	}

	fseek(db, sizeof(evento),SEEK_END);

	if ( fread(&reader, sizeof(evento), 1, db) != 1 ) {
		e->id = 1;
	}else {
		e->id = reader.id + 1;
	}

	fwrite(e, sizeof(evento), 1, db);

	fclose(db);
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
 *
 */
void vaciar_eventos(){

}
