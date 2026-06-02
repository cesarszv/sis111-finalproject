// Proyecto final de Introduccion a la Programacion.
// Todo el juego esta en un solo archivo y usa logica basica.
#include <iostream>

using namespace std;

// Funciones para trabajar con digitos.
bool tieneTresDigitos(int numero);
bool existeDigito(int numero, int digitoBuscado);
bool tieneDigitosRepetidos(int numero);
bool esCodigoValido(int numero);
int contarDigitosBienUbicados(int codigoSecreto, int intento);
int contarDigitosMalUbicados(int codigoSecreto, int intento);
int contarDigitosPares(int numero);
int sumarDigitos(int numero);

// Funciones para interactuar con el jugador.
int leerEntero();
void mostrarMenuPrincipal();
int pedirOpcionMenuPrincipal();
void mostrarComoJugar();
int pedirCantidadIntentos();
int pedirCodigoOComando();
void mostrarPistaExtra(int comando, int codigoSecreto);

// Funciones para controlar la partida.
int elegirCodigoSecreto(int numeroPartida);
void jugar(int numeroPartida);

int main() {
    int opcion = 0;
    int numeroPartida = 1;

    do {
        mostrarMenuPrincipal();
        opcion = pedirOpcionMenuPrincipal();

        if (opcion == 1) {
            jugar(numeroPartida);
            numeroPartida++;
        } else if (opcion == 2) {
            mostrarComoJugar();
        }
    } while (opcion != 3);

    cout << "\nGracias por jugar Codigo Secreto.\n";

    return 0;
}

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

bool esCodigoValido(int numero) {
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

int contarDigitosPares(int numero) {
    int cantidadPares = 0;

    while (numero > 0) {
        int digito = numero % 10;
        numero = numero / 10;

        if (digito % 2 == 0) {
            cantidadPares++;
        }
    }

    return cantidadPares;
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

void mostrarMenuPrincipal() {
    cout << "\n=================================\n";
    cout << "          CODIGO SECRETO\n";
    cout << "=================================\n";
    cout << "1. Jugar\n";
    cout << "2. Como jugar\n";
    cout << "3. Salir\n";
}

int pedirOpcionMenuPrincipal() {
    int opcion = 0;

    cout << "Seleccione una opcion: ";
    opcion = leerEntero();

    while (opcion < 1 || opcion > 3) {
        cout << "Opcion invalida. Seleccione 1, 2 o 3: ";
        opcion = leerEntero();
    }

    return opcion;
}

void mostrarComoJugar() {
    cout << "\n=== COMO JUGAR ===\n";
    cout << "Descubra el codigo secreto de 3 digitos diferentes.\n";
    cout << "Despues de cada intento recibira dos pistas automaticas:\n";
    cout << "- Digitos correctos y bien ubicados.\n";
    cout << "- Digitos correctos, pero ubicados en otra posicion.\n";
    cout << "Tambien puede pedir una pista extra sin perder intentos:\n";
    cout << "- Escriba -1 para conocer la suma de los digitos.\n";
    cout << "- Escriba -2 para conocer la cantidad de digitos pares.\n";
    cout << "- Escriba -3 para saber si el codigo es mayor o menor que 500.\n";
}

int pedirCantidadIntentos() {
    int cantidadIntentos = 0;

    cout << "\nCuantos intentos desea tener? ";
    cout << "Ingrese un numero entre 1 y 20: ";
    cantidadIntentos = leerEntero();

    while (cantidadIntentos < 1 || cantidadIntentos > 20) {
        cout << "Cantidad invalida. Ingrese un numero entre 1 y 20: ";
        cantidadIntentos = leerEntero();
    }

    return cantidadIntentos;
}

int pedirCodigoOComando() {
    int codigoOComando = 0;
    bool entradaValida = false;

    while (entradaValida == false) {
        cout << "\nIngrese un codigo";
        cout << " (-1 suma, -2 pares, -3 mayor o menor que 500): ";
        codigoOComando = leerEntero();

        if (codigoOComando == -1 || codigoOComando == -2 || codigoOComando == -3) {
            entradaValida = true;
        } else if (esCodigoValido(codigoOComando)) {
            entradaValida = true;
        } else if (codigoOComando < 0) {
            cout << "Ese comando no existe. Use -1, -2 o -3.\n";
        } else if (tieneTresDigitos(codigoOComando) == false) {
            cout << "Codigo invalido. Debe tener exactamente 3 digitos.\n";
        } else {
            cout << "Codigo invalido. Sus 3 digitos deben ser diferentes.\n";
        }
    }

    return codigoOComando;
}

void mostrarPistaExtra(int comando, int codigoSecreto) {
    cout << "\n=== PISTA EXTRA ===\n";

    if (comando == -1) {
        cout << "La suma de los digitos es: " << sumarDigitos(codigoSecreto) << "\n";
    } else if (comando == -2) {
        cout << "Cantidad de digitos pares: " << contarDigitosPares(codigoSecreto) << "\n";
    } else {
        if (codigoSecreto > 500) {
            cout << "El codigo secreto es mayor que 500.\n";
        } else {
            cout << "El codigo secreto es menor que 500.\n";
        }
    }
}

int elegirCodigoSecreto(int numeroPartida) {
    int selector = numeroPartida % 5;
    int codigoSecreto = 0;

    if (selector == 1) {
        codigoSecreto = 527;
    } else if (selector == 2) {
        codigoSecreto = 731;
    } else if (selector == 3) {
        codigoSecreto = 864;
    } else if (selector == 4) {
        codigoSecreto = 392;
    } else {
        codigoSecreto = 615;
    }

    return codigoSecreto;
}

void jugar(int numeroPartida) {
    int cantidadIntentos = pedirCantidadIntentos();
    int codigoSecreto = elegirCodigoSecreto(numeroPartida);
    int intentosUsados = 0;
    bool gano = false;

    cout << "\n=== INICIA LA PARTIDA ===\n";
    cout << "Adivine el codigo secreto de 3 digitos diferentes.\n";
    cout << "Las pistas basicas aparecen automaticamente despues de cada intento.\n";

    while (intentosUsados < cantidadIntentos && gano == false) {
        int codigoOComando = 0;

        cout << "\nIntentos restantes: " << cantidadIntentos - intentosUsados << "\n";
        codigoOComando = pedirCodigoOComando();

        if (codigoOComando < 0) {
            mostrarPistaExtra(codigoOComando, codigoSecreto);
        } else {
            intentosUsados++;

            if (codigoOComando == codigoSecreto) {
                gano = true;
            } else {
                cout << "\nNo es el codigo secreto.\n";
                cout << "Bien ubicados: ";
                cout << contarDigitosBienUbicados(codigoSecreto, codigoOComando) << "\n";
                cout << "Correctos en otra posicion: ";
                cout << contarDigitosMalUbicados(codigoSecreto, codigoOComando) << "\n";
            }
        }
    }

    if (gano) {
        cout << "\n=== GANASTE ===\n";
        cout << "Descubriste el codigo secreto: " << codigoSecreto << "\n";
        cout << "Intentos usados: " << intentosUsados << "\n";
    } else {
        cout << "\n=== FIN DE LA PARTIDA ===\n";
        cout << "No quedan intentos. El codigo secreto era: " << codigoSecreto << "\n";
    }
}
