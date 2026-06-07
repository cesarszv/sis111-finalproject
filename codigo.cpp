// proyecto final de introduccion a la programacion.
// juego simple con logica y bucles.
#include <iostream>

using namespace std;

// funciones esenciales del juego.
void mostrarReglas();
int obtenerDigitoEnPosicion(int numero, int posicion);
bool existeDigito(int numero, int digitoBuscado);
int contarLugaresExactos(int codigoSecreto, int intento);
int contarCorrectosEnOtroLugar(int codigoSecreto, int intento);
int sumarDigitos(int numero);
int contarPares(int numero);
int ordenarAscendente(int numero);
int calcularClaveFinal(int codigoSecreto);
int calcularPuntaje(int intentosUsados, int revelacionesUsadas, int pistasUsadas, int erroresDesafio, bool gano);
void jugar();

int main() {
    int opcion = 0;

    while (opcion != 3) {
        cout << "\n========================================\n";
        cout << "              CODIGO SECRETO\n";
        cout << "========================================\n";
        cout << "1. jugar\n";
        cout << "2. ver reglas\n";
        cout << "3. salir\n";
        cout << "opcion: ";
        cin >> opcion;

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
    cout << "el codigo secreto tiene 5 digitos diferentes.\n";
    cout << "tienes 10 intentos para descubrirlo.\n";
    cout << "desde el inicio sabes que la posicion 3 es 2.\n";
    cout << "puedes revelar 2 datos exactos mas.\n";
    cout << "puedes pedir 3 pistas suaves.\n";
    cout << "usar ayudas baja tu puntaje.\n";
    cout << "cuando descubras el codigo hay un desafio final.\n";
    cout << "debes intercalar pares e impares de mayor a menor.\n";
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

int contarLugaresExactos(int codigoSecreto, int intento) {
    int exactos = 0;

    for (int i = 1; i <= 5; i++) {
        int digitoSecreto = codigoSecreto % 10;
        int digitoIntento = intento % 10;

        if (digitoSecreto == digitoIntento) {
            exactos++;
        }

        codigoSecreto = codigoSecreto / 10;
        intento = intento / 10;
    }

    return exactos;
}

int contarCorrectosEnOtroLugar(int codigoSecreto, int intento) {
    int existentes = 0;
    int exactos = contarLugaresExactos(codigoSecreto, intento);

    for (int i = 1; i <= 5; i++) {
        int digito = intento % 10;

        if (existeDigito(codigoSecreto, digito)) {
            existentes++;
        }

        intento = intento / 10;
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

int ordenarAscendente(int numero) {
    int copia = numero;
    int nuevoNumero = 0;

    for (int buscado = 0; buscado <= 9; buscado++) {
        numero = copia;

        while (numero > 0) {
            int digito = numero % 10;
            numero = numero / 10;

            if (digito == buscado) {
                nuevoNumero = nuevoNumero * 10 + digito;
            }
        }
    }

    return nuevoNumero;
}

int calcularClaveFinal(int codigoSecreto) {
    int numeroOrdenado = ordenarAscendente(codigoSecreto);
    int copiaPar = numeroOrdenado;
    int copiaImpar = numeroOrdenado;
    int claveFinal = 0;

    while (copiaPar > 0 || copiaImpar > 0) {
        bool encontre = false;

        while (copiaPar > 0 && encontre == false) {
            int digito = copiaPar % 10;
            copiaPar = copiaPar / 10;

            if (digito % 2 == 0) {
                claveFinal = claveFinal * 10 + digito;
                encontre = true;
            }
        }

        encontre = false;

        while (copiaImpar > 0 && encontre == false) {
            int digito = copiaImpar % 10;
            copiaImpar = copiaImpar / 10;

            if (digito % 2 != 0) {
                claveFinal = claveFinal * 10 + digito;
                encontre = true;
            }
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
    int codigoSecreto = 58274;
    int intentosMaximos = 10;
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
    cout << "codigo secreto, 5 digitos diferentes.\n";
    cout << "dato gratis, posicion 3 es 2.\n";

    while (intentosUsados < intentosMaximos && encontroCodigo == false && rendirse == false) {
        int opcion = 0;

        cout << "\n----------------------------------------\n";
        cout << "intentos, " << intentosUsados << " de " << intentosMaximos << "\n";
        cout << "revelaciones usadas, " << revelacionesUsadas << " de 2\n";
        cout << "pistas usadas, " << pistasUsadas << " de 3\n";
        cout << "----------------------------------------\n";
        cout << "1. probar codigo\n";
        cout << "2. revelar dato exacto\n";
        cout << "3. pedir pista suave\n";
        cout << "4. rendirme\n";
        cout << "opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            int intento = 0;
            int d1 = 0;
            int d2 = 0;
            int d3 = 0;
            int d4 = 0;
            int d5 = 0;
            bool codigoValido = true;

            cout << "\ningresa tu codigo: ";
            cin >> intento;

            d1 = obtenerDigitoEnPosicion(intento, 1);
            d2 = obtenerDigitoEnPosicion(intento, 2);
            d3 = obtenerDigitoEnPosicion(intento, 3);
            d4 = obtenerDigitoEnPosicion(intento, 4);
            d5 = obtenerDigitoEnPosicion(intento, 5);

            if (intento < 10000 || intento > 99999) {
                codigoValido = false;
            }

            if (d1 == d2 || d1 == d3 || d1 == d4 || d1 == d5 ||
                d2 == d3 || d2 == d4 || d2 == d5 ||
                d3 == d4 || d3 == d5 ||
                d4 == d5) {
                codigoValido = false;
            }

            if (codigoValido == false) {
                cout << "ese codigo no sirve, debe tener 5 digitos diferentes.\n";
            } else {
                intentosUsados++;

                if (intento == codigoSecreto) {
                    encontroCodigo = true;
                } else {
                    cout << "\nrespuesta\n";
                    cout << "lugares exactos, " << contarLugaresExactos(codigoSecreto, intento) << "\n";
                    cout << "digitos correctos en otro lugar, ";
                    cout << contarCorrectosEnOtroLugar(codigoSecreto, intento) << "\n";
                }
            }
        } else if (opcion == 2) {
            if (revelacionesUsadas == 0) {
                cout << "\ndato exacto, posicion 1 es ";
                cout << obtenerDigitoEnPosicion(codigoSecreto, 1) << ".\n";
                revelacionesUsadas++;
            } else if (revelacionesUsadas == 1) {
                cout << "\ndato exacto, posicion 5 es ";
                cout << obtenerDigitoEnPosicion(codigoSecreto, 5) << ".\n";
                revelacionesUsadas++;
            } else {
                cout << "\nya no tienes revelaciones.\n";
            }
        } else if (opcion == 3) {
            if (pistasUsadas == 0) {
                cout << "\npista suave, la suma de los digitos es ";
                cout << sumarDigitos(codigoSecreto) << ".\n";
                pistasUsadas++;
            } else if (pistasUsadas == 1) {
                int pares = contarPares(codigoSecreto);
                cout << "\npista suave, hay " << pares << " pares y ";
                cout << 5 - pares << " impares.\n";
                pistasUsadas++;
            } else if (pistasUsadas == 2) {
                cout << "\npista suave, el codigo es mayor que 50000.\n";
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
        cout << "ahora intercala pares e impares de mayor a menor.\n";
        cout << "tienes 2 oportunidades.\n";

        while (erroresDesafio < 2 && gano == false) {
            cout << "\nclave final: ";
            cin >> intentoFinal;

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
