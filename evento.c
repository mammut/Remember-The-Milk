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
 * Cambia el estado de un evento a REALIZADO en el registro de eventos.
 * PARAMS.: - e: puntero a evento inicializado (memoria previamente
 *           asignada).
 */
void concretar_evento(evento *e){
	FILE *db;
	evento reader;

	if ( (db = fopen("db.dat", "rb+")) == NULL) {
		fprintf(stderr, "Error. No se pudo abrir el archivo 'db.dat'\n");
		return;
	}

	while (fread(&reader, sizeof(evento), 1, db) == 1) {
		if (reader.id == e->id) {
			if (reader.estado == 0) {
				reader.estado = 1;
				fseek(db, -sizeof(evento), SEEK_CUR);
				fwrite(&reader, sizeof(evento), 1, db);
				printf("Evento #%d marcado como realizado!\n", e->id);
				fclose(db);
				return;
			}else {
				printf("El evento #%d ya se ha marcado como concretado!\n", e->id);
				fclose(db);
				return;
			}
		}
	}

	fclose(db);

	printf("El evento #%d no existe!\n", e->id);
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
