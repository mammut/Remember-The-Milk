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
 * Modifica informacion de un evento determinado en el registro de eventos.
 * PARAMS.: - e: puntero a evento inicializado (memoria previamente
 *           asignada).
 */
void modificar_evento(evento *e){
	FILE *db;
	evento reader;

	if ( (db = fopen("db.dat", "rb+")) == NULL) {
		fprintf(stderr, "Error. No se pudo abrir el archivo 'db.dat'\n");
		return;
	}

	while (fread(&reader, sizeof(evento), 1, db) == 1) {
		if (reader.id == e->id) {
			switch(e->estado) {
				case 2:
					sprintf(reader.titl, "%s", e->titl);
					break;
				case 3:
					sprintf(reader.desc, "%s", e->desc);
					break;
				case 4:
					sprintf(reader.titl, "%s", e->titl);
					sprintf(reader.desc, "%s", e->desc);
					break;
			}
			fseek(db, -sizeof(evento), SEEK_CUR);
			fwrite(&reader, sizeof(evento), 1, db);
			fclose(db);
			printf("Evento #%d modificado exitosamente!", e->id);
			return;
		}
	}

	fclose(db);

	printf("El evento #%d no existe\n", e->id);
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
