#include <stdio.h>
#include "include/evento.h"

/**
 *
 */
void nuevo_evento(evento *e){

}

/**
 * Obtiene y muestra por pantalla informacion de un evento determinado
 * desde el registro de eventos.
 * PARAMS.: - e: puntero a evento inicializado (memoria previamente
 *           asignada).
 */
void mostrar_evento(evento *e){
	FILE *db;
	evento reader;

	if ( (db = fopen("db.dat", "rb")) == NULL) {
		fprintf(stderr, "Error. No se pudo abrir el archivo 'db.dat'\n");
		return;
	}

	while (fread(&reader, sizeof(evento), 1, db) == 1) {
		if (reader.id == e->id) {
			printf("Evento #%d :: %s\n", reader.id,reader.titl);
			printf("%s\n", reader.desc);
			printf("%s\n", reader.estado == 0 ? "No Realizado" : "Realizado");
			fclose(db);
			return;
		}
	}

	fclose(db);

	printf("El evento #%d no existe\n", e->id);
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
