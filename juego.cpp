#include <iostream>

#include "juego.h"
#include "logica_digitos.h"

using namespace std;

int leerEntero() {
    int numero = 0;
    bool entradaValida = false;

    while (entradaValida == false) {
        if (cin >> numero) {
            entradaValida = true;
        } else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada invalida. Ingrese un numero entero: ";
        }
    }

    return numero;
}

void mostrarMenu() {
    cout << "\n=== CODIGO SECRETO ===\n";
    cout << "1. Jugar\n";
    cout << "2. Ver instrucciones\n";
    cout << "3. Salir\n";
}

int pedirOpcionMenu() {
    int opcion = 0;

    cout << "Seleccione una opcion: ";
    opcion = leerEntero();

    while (opcion < 1 || opcion > 3) {
        cout << "Opcion invalida. Seleccione 1, 2 o 3: ";
        opcion = leerEntero();
    }

    return opcion;
}

void mostrarInstrucciones() {
    cout << "\n=== INSTRUCCIONES ===\n";
    cout << "Descubra el codigo secreto de 3 digitos.\n";
    cout << "Los digitos del codigo no se repiten.\n";
    cout << "Cada pista indica cuantos digitos estan bien ubicados\n";
    cout << "y cuantos existen, pero estan en otra posicion.\n";
}

int pedirDificultad() {
    int dificultad = 0;

    cout << "\n=== DIFICULTAD ===\n";
    cout << "1. Facil: 10 intentos\n";
    cout << "2. Normal: 7 intentos\n";
    cout << "3. Dificil: 5 intentos\n";
    cout << "Seleccione una dificultad: ";
    dificultad = leerEntero();

    while (dificultad < 1 || dificultad > 3) {
        cout << "Dificultad invalida. Seleccione 1, 2 o 3: ";
        dificultad = leerEntero();
    }

    return dificultad;
}

int obtenerCantidadIntentos(int dificultad) {
    int cantidadIntentos = 0;

    if (dificultad == 1) {
        cantidadIntentos = 10;
    } else if (dificultad == 2) {
        cantidadIntentos = 7;
    } else {
        cantidadIntentos = 5;
    }

    return cantidadIntentos;
}

int elegirCodigoSecreto(int dificultad, int numeroPartida) {
    int selector = (dificultad + numeroPartida) % 5;
    int codigoSecreto = 0;

    if (selector == 0) {
        codigoSecreto = 527;
    } else if (selector == 1) {
        codigoSecreto = 731;
    } else if (selector == 2) {
        codigoSecreto = 864;
    } else if (selector == 3) {
        codigoSecreto = 392;
    } else {
        codigoSecreto = 615;
    }

    return codigoSecreto;
}

int pedirIntento() {
    int intento = 0;

    cout << "Ingrese un codigo de 3 digitos sin repetir: ";
    intento = leerEntero();

    while (esIntentoValido(intento) == false) {
        cout << "Codigo invalido. Ingrese 3 digitos diferentes: ";
        intento = leerEntero();
    }

    return intento;
}

int calcularPuntaje(int intentosRestantes, int dificultad) {
    return dificultad * 100 + intentosRestantes * 50;
}

void jugar(int numeroPartida) {
    int dificultad = pedirDificultad();
    int cantidadIntentos = obtenerCantidadIntentos(dificultad);
    int codigoSecreto = elegirCodigoSecreto(dificultad, numeroPartida);
    int intentosUsados = 0;
    bool gano = false;

    cout << "\n=== INICIA LA PARTIDA ===\n";

    while (intentosUsados < cantidadIntentos && gano == false) {
        int intento = 0;
        int bienUbicados = 0;
        int malUbicados = 0;

        cout << "\nIntento " << intentosUsados + 1;
        cout << " de " << cantidadIntentos << "\n";
        intento = pedirIntento();
        intentosUsados++;

        if (intento == codigoSecreto) {
            gano = true;
        } else {
            bienUbicados = contarDigitosBienUbicados(codigoSecreto, intento);
            malUbicados = contarDigitosMalUbicados(codigoSecreto, intento);

            cout << "Digitos correctos y bien ubicados: " << bienUbicados << "\n";
            cout << "Digitos correctos pero mal ubicados: " << malUbicados << "\n";
        }
    }

    if (gano == true) {
        int intentosRestantes = cantidadIntentos - intentosUsados;
        int puntaje = calcularPuntaje(intentosRestantes, dificultad);

        cout << "\nDescubriste el codigo secreto.\n";
        cout << "Puntaje final: " << puntaje << "\n";
    } else {
        cout << "\nNo quedan intentos. El codigo secreto era: ";
        cout << codigoSecreto << "\n";
    }
}
