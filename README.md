# Remember The Milk en C #

Tarea 1 de LP 2013.1 Remember The Milk en C utilizando funciones a punteros y bibliotecas externas no estándar.

## Uso ###

``tarea1 <comandos> [ID] [-tdb] [título] [descripción]``

ID es un número entero correlativo al evento.

### Comandos ###

*  ``new``: Crea un evento nuevo. Necesita título y descripción.
*  ``get``: Obtener un evento. Necesita un ID.
*  ``delete``: Borra un evento. Necesita un ID.
*  ``update``: Modifica un evento. Necesita una opción t: título, d: descripción, b: ambos y título y descripción según corresponda.
*  ``do``: Marca un evento como realizado. Necesita un ID.
*  ``list``: Muestra la lista de eventos por pantalla. No recibe parámetros.
*  ``clear``: Borra la lista de eventos del sistema. No recibe parámetros.
