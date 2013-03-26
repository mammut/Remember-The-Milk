#ifndef _EVENTO_H_
#define _EVENTO_H_

/**
 * Estructura que define un EVENTO. Almacena diferentes tipos de datos.
 * CAMPOS: - id: identificador del evento.
 *         - titl: titulo del evento.
 *         - desc: descripcion del evento.
 *         - estado: estado del evento.
 */
typedef struct _evento {
  int id;
  char titl[60];
  char desc[120];
  int estado;
} evento;

/**
 * Definicion de las funciones base como parte del nucleo
 * de la aplicación.
 */
typedef void (*ptr_funcion)(evento *);

/**
 * Almacena un nuevo evento en el registro de eventos.
 * PARAMS.: - e: puntero a evento inicializado (memoria previamente
 *           asignada).
 */
void nuevo_evento(evento *);

/**
 * Obtiene y muestra por pantalla informacion de un evento determinado
 * desde el registro de eventos.
 * PARAMS.: - e: puntero a evento inicializado (memoria previamente
 *           asignada).
 */
void mostrar_evento(evento *);

/**
 * Elimina un evento determinado en el registro de eventos.
 * PARAMS.: - e: puntero a evento inicializado (memoria previamente
 *           asignada).
 */
void eliminar_evento(evento *);

/**
 * Modifica informacion de un evento determinado en el registro de eventos.
 * PARAMS.: - e: puntero a evento inicializado (memoria previamente
 *           asignada).
 */
void modificar_evento(evento *);

/**
 * Cambia el estado de un evento a REALIZADO en el registro de eventos.
 * PARAMS.: - e: puntero a evento inicializado (memoria previamente
 *           asignada).
 */
void concretar_evento(evento *);

/**
 * Muestra por pantalla la lista de eventos disponibles en el registro
 * de eventos.
 */
void listar_eventos();

/**
 * Elimina el registro de eventos.
 */
void vaciar_eventos();

/**
 * Arreglo de punteros a funciones del nucleo.
 */
extern ptr_funcion funciones_base[7];

#endif
