#ifndef JUEGO_H
#define JUEGO_H

void mostrarMenu();
int leerEntero();
int pedirOpcionMenu();
void mostrarInstrucciones();
int pedirDificultad();
int obtenerCantidadIntentos(int dificultad);
int elegirCodigoSecreto(int dificultad, int numeroPartida);
int pedirIntento();
int calcularPuntaje(int intentosRestantes, int dificultad);
void jugar(int numeroPartida);

#endif
