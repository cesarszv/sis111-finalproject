#include "juego.h"

int main() {
    int opcion = 0;
    int numeroPartida = 1;

    do {
        mostrarMenu();
        opcion = pedirOpcionMenu();

        if (opcion == 1) {
            jugar(numeroPartida);
            numeroPartida++;
        } else if (opcion == 2) {
            mostrarInstrucciones();
        }
    } while (opcion != 3);

    return 0;
}
