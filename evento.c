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
	FILE *db;
	evento reader;
	int printed = 0;

	if ( (db = fopen("db.dat", "rb")) == NULL) {
		fprintf(stderr, "Error. No se pudo abrir el archivo 'db.dat'\n");
		return;
	}


	while ( fread(&reader, sizeof(evento), 1, db) == 1) {
		if (printed++ == 0)	printf("ID | Titulo | Estado\n");

		printf("%d | %s | %s\n", reader.id, reader.titl, reader.estado == 1 ? "Realizado" : "No realiado");
	}
	if (printed == 0)
		printf("No hay eventos en el registro!\n");

	fclose(db);
}

/**
 *
 */
void vaciar_eventos(){

}
