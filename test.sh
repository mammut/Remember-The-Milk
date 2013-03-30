#!/bin/bash
clear

# Nuevo evento
./tarea1 new "Evento 1" "Este es un evento"

# Mostrar evento
./tarea1 get 1

# Concretar evento
./tarea1 do 1

# Mostrar evento
./tarea1 get 1

# Modificar evento
./tarea1 update 1 -t "Evento bacan"

# Mostrar evento
./tarea1 get 1

# Concretar evento
./tarea1 do 1

# Nuevo evento
./tarea1 new "Evento 2" "Este es otro evento"

# Eliminar evento
./tarea1 delete 1

# Mostrar evento
./tarea1 get 1

# Nuevo evento
./tarea1 new "Evento 3" "Este es un evento"

# Concretar evento
./tarea1 do 3

# Listar Eventos
./tarea1 list
./tarea1 clear
./tarea1 list