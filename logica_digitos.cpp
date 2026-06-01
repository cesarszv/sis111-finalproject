#include "logica_digitos.h"

bool tieneTresDigitos(int numero) {
    return numero >= 100 && numero <= 999;
}

bool existeDigito(int numero, int digitoBuscado) {
    bool encontrado = false;

    while (numero > 0 && encontrado == false) {
        int digito = numero % 10;
        numero = numero / 10;

        if (digito == digitoBuscado) {
            encontrado = true;
        }
    }

    return encontrado;
}

bool tieneDigitosRepetidos(int numero) {
    bool tieneRepetidos = false;

    while (numero > 0 && tieneRepetidos == false) {
        int digito = numero % 10;
        numero = numero / 10;

        if (existeDigito(numero, digito)) {
            tieneRepetidos = true;
        }
    }

    return tieneRepetidos;
}

bool esIntentoValido(int numero) {
    return tieneTresDigitos(numero) && tieneDigitosRepetidos(numero) == false;
}

int contarDigitosBienUbicados(int codigoSecreto, int intento) {
    int bienUbicados = 0;

    for (int posicion = 1; posicion <= 3; posicion++) {
        int digitoSecreto = codigoSecreto % 10;
        int digitoIntento = intento % 10;

        if (digitoSecreto == digitoIntento) {
            bienUbicados++;
        }

        codigoSecreto = codigoSecreto / 10;
        intento = intento / 10;
    }

    return bienUbicados;
}

int contarDigitosMalUbicados(int codigoSecreto, int intento) {
    int existentes = 0;
    int bienUbicados = contarDigitosBienUbicados(codigoSecreto, intento);

    for (int posicion = 1; posicion <= 3; posicion++) {
        int digito = intento % 10;

        if (existeDigito(codigoSecreto, digito)) {
            existentes++;
        }

        intento = intento / 10;
    }

    return existentes - bienUbicados;
}
