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
 * Elimina un evento determinado en el registro de eventos.
 * PARAMS.: - e: puntero a evento inicializado (memoria previamente
 *           asignada).
 */
void eliminar_evento(evento *e){
	FILE *db;
	FILE *new_db;
	evento reader;
	int status = 0;

	if ( (db = fopen("db.dat", "rb")) == NULL) {
		fprintf(stderr, "Error. No se pudo abrir el archivo 'db.dat'\n");
		return;
	}
	if ( (new_db = fopen("new_db.dat", "wb")) == NULL) {
		fprintf(stderr, "Error. No se pudo abrir el archivo 'new_db.dat'\n");
		return;
	}

	while (fread(&reader, sizeof(evento), 1, db) == 1)
		if (reader.id != e->id)
			fwrite(&reader, sizeof(evento), 1, new_db);
		else
			status = 1;

	fclose(db);
	fclose(new_db);

	remove("db.dat");
	rename("new_db.dat", "db.dat");

	if (status == 1)
		printf("Evento #%d eliminado exitosamente!\n", e->id);
	else
		printf("El evento #%d no existe\n", e->id);
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
