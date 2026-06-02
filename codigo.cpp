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
void mostrarInstrucciones();
int pedirCantidadIntentos();
int pedirCodigoOComando();
void mostrarErrorCodigo(int codigo);
void mostrarEstadoPartida(int intentosUsados, int cantidadIntentos, int pistasUsadas);

// Funciones para controlar las pistas y la partida.
int elegirCodigoSecreto(int numeroPartida);
void mostrarMenuPistas();
int pedirTipoPista();
bool mostrarPista(int tipoPista, int codigoSecreto, int ultimoIntento);
int calcularPuntaje(int intentosUsados);
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
            mostrarInstrucciones();
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

void mostrarInstrucciones() {
    cout << "\n=== COMO JUGAR ===\n";
    cout << "Descubra el codigo secreto de 3 digitos diferentes.\n";
    cout << "Antes de empezar, usted decide cuantos intentos desea tener.\n";
    cout << "Durante la partida puede:\n";
    cout << "- Escribir un codigo de 3 digitos para intentar adivinar.\n";
    cout << "- Escribir 0 para abrir el menu de pistas.\n";
    cout << "Pedir una pista no consume un intento.\n";
    cout << "El puntaje depende de cuantos intentos uso para ganar.\n";
}

int pedirCantidadIntentos() {
    int cantidadIntentos = 0;

    cout << "\n=== CONFIGURAR PARTIDA ===\n";
    cout << "Cuantos intentos desea tener? Ingrese un numero entre 1 y 20.\n";
    cout << "Recomendacion para una partida equilibrada: 7 intentos.\n";
    cout << "Cantidad de intentos: ";
    cantidadIntentos = leerEntero();

    while (cantidadIntentos < 1 || cantidadIntentos > 20) {
        cout << "Cantidad invalida. Ingrese un numero entre 1 y 20: ";
        cantidadIntentos = leerEntero();
    }

    return cantidadIntentos;
}

int pedirCodigoOComando() {
    int codigoOComando = 0;

    cout << "Ingrese un codigo de 3 digitos o escriba 0 para pedir una pista: ";
    codigoOComando = leerEntero();

    while (codigoOComando != 0 && esCodigoValido(codigoOComando) == false) {
        mostrarErrorCodigo(codigoOComando);
        cout << "Ingrese otro codigo o escriba 0 para pedir una pista: ";
        codigoOComando = leerEntero();
    }

    return codigoOComando;
}

void mostrarErrorCodigo(int codigo) {
    if (tieneTresDigitos(codigo) == false) {
        cout << "Codigo invalido: debe tener exactamente 3 digitos.\n";
    } else {
        cout << "Codigo invalido: sus 3 digitos deben ser diferentes.\n";
    }
}

void mostrarEstadoPartida(int intentosUsados, int cantidadIntentos, int pistasUsadas) {
    cout << "\n---------------------------------\n";
    cout << "Intentos restantes: " << cantidadIntentos - intentosUsados << "\n";
    cout << "Pistas solicitadas: " << pistasUsadas << "\n";
    cout << "Recuerde: escriba 0 para pedir una pista.\n";
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

void mostrarMenuPistas() {
    cout << "\n=== MENU DE PISTAS ===\n";
    cout << "1. Cuantos digitos estan bien ubicados en mi ultimo intento?\n";
    cout << "2. Cuantos digitos correctos estan en otra posicion?\n";
    cout << "3. Cuantos digitos pares tiene el codigo secreto?\n";
    cout << "4. Cuanto suman los digitos del codigo secreto?\n";
    cout << "5. El codigo secreto es mayor o menor que 500?\n";
    cout << "6. Volver a la partida sin pedir una pista\n";
}

int pedirTipoPista() {
    int tipoPista = 0;

    mostrarMenuPistas();
    cout << "Seleccione una pista: ";
    tipoPista = leerEntero();

    while (tipoPista < 1 || tipoPista > 6) {
        cout << "Opcion invalida. Seleccione una opcion entre 1 y 6: ";
        tipoPista = leerEntero();
    }

    return tipoPista;
}

bool mostrarPista(int tipoPista, int codigoSecreto, int ultimoIntento) {
    bool pistaMostrada = true;

    cout << "\n=== PISTA ===\n";

    if (tipoPista == 1) {
        if (ultimoIntento == 0) {
            cout << "Primero ingrese al menos un codigo para comparar posiciones.\n";
            pistaMostrada = false;
        } else {
            cout << "Digitos correctos y bien ubicados en su ultimo intento: ";
            cout << contarDigitosBienUbicados(codigoSecreto, ultimoIntento) << "\n";
        }
    } else if (tipoPista == 2) {
        if (ultimoIntento == 0) {
            cout << "Primero ingrese al menos un codigo para comparar posiciones.\n";
            pistaMostrada = false;
        } else {
            cout << "Digitos correctos pero ubicados en otra posicion: ";
            cout << contarDigitosMalUbicados(codigoSecreto, ultimoIntento) << "\n";
        }
    } else if (tipoPista == 3) {
        cout << "Cantidad de digitos pares del codigo secreto: ";
        cout << contarDigitosPares(codigoSecreto) << "\n";
    } else if (tipoPista == 4) {
        cout << "Suma de los digitos del codigo secreto: ";
        cout << sumarDigitos(codigoSecreto) << "\n";
    } else if (tipoPista == 5) {
        if (codigoSecreto > 500) {
            cout << "El codigo secreto es mayor que 500.\n";
        } else {
            cout << "El codigo secreto es menor que 500.\n";
        }
    } else {
        cout << "Regresando a la partida sin mostrar una pista.\n";
        pistaMostrada = false;
    }

    return pistaMostrada;
}

int calcularPuntaje(int intentosUsados) {
    int puntaje = 1100 - intentosUsados * 100;

    if (puntaje < 0) {
        puntaje = 0;
    }

    return puntaje;
}

void jugar(int numeroPartida) {
    int cantidadIntentos = pedirCantidadIntentos();
    int codigoSecreto = elegirCodigoSecreto(numeroPartida);
    int intentosUsados = 0;
    int pistasUsadas = 0;
    int ultimoIntento = 0;
    bool gano = false;

    cout << "\n=== INICIA LA PARTIDA ===\n";
    cout << "Encuentre el codigo secreto de 3 digitos diferentes.\n";
    cout << "Puede escribir 0 en cualquier turno para pedir una pista.\n";

    while (intentosUsados < cantidadIntentos && gano == false) {
        int codigoOComando = 0;

        mostrarEstadoPartida(intentosUsados, cantidadIntentos, pistasUsadas);
        codigoOComando = pedirCodigoOComando();

        if (codigoOComando == 0) {
            int tipoPista = pedirTipoPista();

            if (mostrarPista(tipoPista, codigoSecreto, ultimoIntento)) {
                pistasUsadas++;
            }
        } else {
            ultimoIntento = codigoOComando;
            intentosUsados++;

            if (ultimoIntento == codigoSecreto) {
                gano = true;
            } else {
                cout << "\nEse no es el codigo secreto.\n";
                cout << "Puede intentar otra vez o escribir 0 para pedir una pista.\n";
            }
        }
    }

    if (gano) {
        cout << "\n=== GANASTE ===\n";
        cout << "Descubriste el codigo secreto: " << codigoSecreto << "\n";
        cout << "Intentos usados: " << intentosUsados << "\n";
        cout << "Pistas solicitadas: " << pistasUsadas << "\n";
        cout << "Puntaje final: " << calcularPuntaje(intentosUsados) << "\n";
    } else {
        cout << "\n=== FIN DE LA PARTIDA ===\n";
        cout << "No quedan intentos. El codigo secreto era: " << codigoSecreto << "\n";
        cout << "Pistas solicitadas: " << pistasUsadas << "\n";
    }
}
