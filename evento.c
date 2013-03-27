#include <stdio.h>
#include "include/evento.h"

/**
 * Almacena un nuevo evento en el registro de eventos.
 * Se lee el último registro del archivo, y se incrementa en 1 su ID
 * PARAMS.: - e: puntero a evento inicializado (memoria previamente
 *               asignada).
 */
void nuevo_evento(evento *e){
	FILE *db;
	evento reader;

	if ( (db = fopen("db.dat", "ab+")) == NULL) {
		fprintf(stderr, "Error. No se pudo abrir el archivo 'db.dat'\n");
		return;
	}

	fseek(db, -sizeof(evento), SEEK_END);

	if ( fread(&reader, sizeof(evento), 1, db) != 1 )
		e->id = 1;
	else
		e->id = reader.id + 1;

	fwrite(e, sizeof(evento), 1, db);

	fclose(db);

	printf("Evento #%d creado exitosamente!\n", e->id);
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
			printf("Evento #%d modificado exitosamente!\n", e->id);
			return;
		}
	}

	fclose(db);

	printf("El evento #%d no existe\n", e->id);
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
	FILE *db;
	evento reader;

	if ( (db = fopen("db.dat", "rb")) == NULL) {
		fprintf(stderr, "Error. No se pudo abrir el archivo 'db.dat'\n");
		return;
	}

	printf("ID | Titulo | Estado\n");
	while ( fread(&reader, sizeof(evento), 1, db) == 1) {
		printf("%d | %s | %s\n", reader.id, reader.titl, reader.estado == 1 ? "Realizado" : "No realiado");
	}

	fclose(db);
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

	printf("El registro de eventos ha sido eliminado!\n");
}
