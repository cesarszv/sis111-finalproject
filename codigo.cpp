// proyecto final de introduccion a la programacion.
#include <iostream>

using namespace std;

// funciones principales.
void mostrarReglas();
void jugar();

// funciones de apoyo.
bool leerEntero(int &numero);
int obtenerDigitoEnPosicion(int numero, int posicion);
bool existeDigito(int numero, int digitoBuscado);
bool tieneCincoDigitos(int numero);
bool tieneDigitosDiferentes(int numero);
bool intentoEsValido(int intento);
int contarLugaresExactos(int codigoSecreto, int intento);
int contarCorrectosEnOtroLugar(int codigoSecreto, int intento);
int sumarDigitos(int numero);
int contarPares(int numero);
int calcularClaveFinal(int codigoSecreto);
int calcularPuntaje(int intentosUsados, int revelacionesUsadas, int pistasUsadas, int erroresDesafio, bool gano);

int main() {
    int opcion = 0;

    while (opcion != 3 && cin.eof() == false) {
        cout << "\n========================================\n";
        cout << "              CODIGO SECRETO\n";
        cout << "========================================\n";
        cout << "1. jugar\n";
        cout << "2. ver reglas\n";
        cout << "3. salir\n";
        cout << "opcion: ";

        opcion = 0;
        if (leerEntero(opcion) == false) {
            continue;
        }

        if (opcion == 1) {
            jugar();
        } else if (opcion == 2) {
            mostrarReglas();
        } else if (opcion != 3) {
            cout << "\nopcion invalida.\n";
        }
    }

    cout << "\ngracias por jugar codigo secreto.\n";

    return 0;
}

void mostrarReglas() {
    cout << "\n------------- reglas -------------\n";
    cout << "codigo, 5 digitos diferentes.\n";
    cout << "intentos, 10.\n";
    cout << "dato gratis, posicion 3 = 2.\n";
    cout << "ayudas, 2 revelaciones y 3 pistas suaves.\n";
    cout << "puntaje, baja si usas intentos o ayudas.\n";
    cout << "final, arma una clave alternando pares e impares de mayor a menor.\n";
}

bool leerEntero(int &numero) {
    if (cin >> numero) {
        return true;
    }

    if (cin.eof()) {
        return false;
    }

    cin.clear();
    cin.ignore(1000, '\n');
    cout << "\nentrada invalida, escribe solo numeros.\n";

    return false;
}

int obtenerDigitoEnPosicion(int numero, int posicion) {
    int divisor = 10000;

    for (int i = 1; i < posicion; i++) {
        divisor = divisor / 10;
    }

    return (numero / divisor) % 10;
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

bool tieneCincoDigitos(int numero) {
    return numero >= 10000 && numero <= 99999;
}

bool tieneDigitosDiferentes(int numero) {
    int d1 = obtenerDigitoEnPosicion(numero, 1);
    int d2 = obtenerDigitoEnPosicion(numero, 2);
    int d3 = obtenerDigitoEnPosicion(numero, 3);
    int d4 = obtenerDigitoEnPosicion(numero, 4);
    int d5 = obtenerDigitoEnPosicion(numero, 5);
    bool diferentes = true;

    if (d1 == d2 || d1 == d3 || d1 == d4 || d1 == d5 ||
        d2 == d3 || d2 == d4 || d2 == d5 ||
        d3 == d4 || d3 == d5 ||
        d4 == d5) {
        diferentes = false;
    }

    return diferentes;
}

bool intentoEsValido(int intento) {
    bool valido = true;

    if (tieneCincoDigitos(intento) == false) {
        valido = false;
    } else if (tieneDigitosDiferentes(intento) == false) {
        valido = false;
    }

    return valido;
}

int contarLugaresExactos(int codigoSecreto, int intento) {
    int exactos = 0;

    for (int posicion = 1; posicion <= 5; posicion++) {
        int digitoSecreto = obtenerDigitoEnPosicion(codigoSecreto, posicion);
        int digitoIntento = obtenerDigitoEnPosicion(intento, posicion);

        if (digitoSecreto == digitoIntento) {
            exactos++;
        }
    }

    return exactos;
}

int contarCorrectosEnOtroLugar(int codigoSecreto, int intento) {
    int existentes = 0;
    int exactos = contarLugaresExactos(codigoSecreto, intento);

    for (int posicion = 1; posicion <= 5; posicion++) {
        int digito = obtenerDigitoEnPosicion(intento, posicion);

        if (existeDigito(codigoSecreto, digito)) {
            existentes++;
        }
    }

    return existentes - exactos;
}

int sumarDigitos(int numero) {
    int suma = 0;

    while (numero > 0) {
        int digito = numero % 10;
        numero = numero / 10;
        suma = suma + digito;
    }

    return suma;
}

int contarPares(int numero) {
    int pares = 0;

    while (numero > 0) {
        int digito = numero % 10;
        numero = numero / 10;

        if (digito % 2 == 0) {
            pares++;
        }
    }

    return pares;
}

int calcularClaveFinal(int codigoSecreto) {
    int claveFinal = 0;
    int parBuscado = 8;
    int imparBuscado = 9;

    while (parBuscado >= 0 || imparBuscado >= 1) {
        while (parBuscado >= 0 && existeDigito(codigoSecreto, parBuscado) == false) {
            parBuscado = parBuscado - 2;
        }

        if (parBuscado >= 0) {
            claveFinal = claveFinal * 10 + parBuscado;
            parBuscado = parBuscado - 2;
        }

        while (imparBuscado >= 1 && existeDigito(codigoSecreto, imparBuscado) == false) {
            imparBuscado = imparBuscado - 2;
        }

        if (imparBuscado >= 1) {
            claveFinal = claveFinal * 10 + imparBuscado;
            imparBuscado = imparBuscado - 2;
        }
    }

    return claveFinal;
}

int calcularPuntaje(int intentosUsados, int revelacionesUsadas, int pistasUsadas, int erroresDesafio, bool gano) {
    int puntaje = 100;

    if (gano == false) {
        puntaje = 0;
    } else {
        puntaje = puntaje - (intentosUsados * 4);
        puntaje = puntaje - (revelacionesUsadas * 12);
        puntaje = puntaje - (pistasUsadas * 8);
        puntaje = puntaje - (erroresDesafio * 10);

        if (puntaje < 0) {
            puntaje = 0;
        }
    }

    return puntaje;
}

void jugar() {
    const int codigoSecreto = 58274;
    const int intentosMaximos = 10;
    const int revelacionesMaximas = 2;
    const int pistasMaximas = 3;

    int intentosUsados = 0;
    int revelacionesUsadas = 0;
    int pistasUsadas = 0;
    int erroresDesafio = 0;
    bool encontroCodigo = false;
    bool gano = false;
    bool rendirse = false;

    cout << "\n========================================\n";
    cout << "              nueva partida\n";
    cout << "========================================\n";
    cout << "encuentra el codigo secreto.\n";
    cout << "dato gratis, posicion 3 = 2.\n";

    while (intentosUsados < intentosMaximos &&
           encontroCodigo == false &&
           rendirse == false &&
           cin.eof() == false) {
        int opcion = 0;

        cout << "\n----------------------------------------\n";
        cout << "turno, " << intentosUsados + 1 << " de " << intentosMaximos << "\n";
        cout << "dato fijo, posicion 3 = 2\n";
        cout << "revelaciones disponibles, " << revelacionesMaximas - revelacionesUsadas << "\n";
        cout << "pistas disponibles, " << pistasMaximas - pistasUsadas << "\n";
        cout << "----------------------------------------\n";
        cout << "1. probar codigo\n";
        cout << "2. revelar dato exacto\n";
        cout << "3. pedir pista suave\n";
        cout << "4. rendirme\n";
        cout << "opcion: ";

        if (leerEntero(opcion) == false) {
            continue;
        }

        if (opcion == 1) {
            int intento = 0;

            cout << "\ningresa tu codigo: ";
            if (leerEntero(intento) == false) {
                continue;
            }

            if (intentoEsValido(intento) == false) {
                cout << "codigo invalido, escribe 5 digitos sin repetir.\n";
                cout << "no cuenta como intento.\n";
            } else {
                intentosUsados++;

                if (intento == codigoSecreto) {
                    encontroCodigo = true;
                } else {
                    cout << "\nrespuesta\n";
                    cout << "lugares exactos, ";
                    cout << contarLugaresExactos(codigoSecreto, intento) << "\n";
                    cout << "digitos correctos en otro lugar, ";
                    cout << contarCorrectosEnOtroLugar(codigoSecreto, intento) << "\n";
                }
            }
        } else if (opcion == 2) {
            if (revelacionesUsadas == 0) {
                cout << "\ndato exacto, posicion 1 = ";
                cout << obtenerDigitoEnPosicion(codigoSecreto, 1) << ".\n";
                revelacionesUsadas++;
            } else if (revelacionesUsadas == 1) {
                cout << "\ndato exacto, posicion 5 = ";
                cout << obtenerDigitoEnPosicion(codigoSecreto, 5) << ".\n";
                revelacionesUsadas++;
            } else {
                cout << "\nya no tienes revelaciones.\n";
            }
        } else if (opcion == 3) {
            if (pistasUsadas == 0) {
                cout << "\npista 1, suma de digitos = ";
                cout << sumarDigitos(codigoSecreto) << ".\n";
                pistasUsadas++;
            } else if (pistasUsadas == 1) {
                int pares = contarPares(codigoSecreto);
                cout << "\npista 2, hay " << pares << " pares y ";
                cout << 5 - pares << " impares.\n";
                pistasUsadas++;
            } else if (pistasUsadas == 2) {
                cout << "\npista 3, el codigo es mayor que 50000.\n";
                pistasUsadas++;
            } else {
                cout << "\nya no tienes pistas.\n";
            }
        } else if (opcion == 4) {
            rendirse = true;
        } else {
            cout << "\nopcion invalida.\n";
        }
    }

    if (encontroCodigo == true) {
        int claveFinal = calcularClaveFinal(codigoSecreto);
        int intentoFinal = 0;

        cout << "\n========================================\n";
        cout << "              desafio final\n";
        cout << "========================================\n";
        cout << "encontraste el codigo, " << codigoSecreto << ".\n";
        cout << "forma la clave final.\n";
        cout << "regla, mayor par, mayor impar, siguiente par, siguiente impar.\n";
        cout << "tienes 2 oportunidades.\n";

        while (erroresDesafio < 2 && gano == false && cin.eof() == false) {
            cout << "\nclave final: ";

            if (leerEntero(intentoFinal) == false) {
                continue;
            }

            if (intentoFinal == claveFinal) {
                gano = true;
            } else {
                erroresDesafio++;

                if (erroresDesafio < 2) {
                    cout << "no es la clave final, intenta una vez mas.\n";
                }
            }
        }

        if (gano == false) {
            cout << "\nla clave final era " << claveFinal << ".\n";
        }
    }

    cout << "\n========================================\n";
    cout << "                resultado\n";
    cout << "========================================\n";

    if (gano == true) {
        cout << "ganaste el juego completo.\n";
    } else if (encontroCodigo == true) {
        cout << "encontraste el codigo pero fallaste el desafio.\n";
    } else if (rendirse == true) {
        cout << "te rendiste, el codigo era " << codigoSecreto << ".\n";
    } else {
        cout << "se acabaron los intentos, el codigo era " << codigoSecreto << ".\n";
    }

    cout << "intentos usados, " << intentosUsados << "\n";
    cout << "revelaciones usadas, " << revelacionesUsadas << "\n";
    cout << "pistas usadas, " << pistasUsadas << "\n";
    cout << "puntaje, ";
    cout << calcularPuntaje(intentosUsados, revelacionesUsadas, pistasUsadas, erroresDesafio, gano);
    cout << " de 100.\n";
}
