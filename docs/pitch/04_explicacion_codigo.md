# Explicación fácil de `codigo.cpp`

## 1. Idea general

El juego está dividido en funciones pequeñas. Cada función realiza una tarea concreta.

Esto hace que sea más sencillo:

- Leer el programa.
- Explicar una parte.
- Encontrar errores.
- Modificar una regla.

La explicación detallada está en [`../../codigo.md`](../../codigo.md). Este documento funciona como guía de estudio rápida.

## 2. Estructura del archivo

| Bloque | Contenido |
| :--- | :--- |
| Inclusión | `#include <iostream>` permite usar `cin` y `cout`. |
| Prototipos | Anuncian qué funciones existirán. |
| `main` | Coordina el menú principal. |
| Definiciones | Contienen la lógica completa. |

## 3. Conceptos básicos

### Variable

```cpp
int pistasUsadas = 0;
```

- `int`: número entero.
- `pistasUsadas`: nombre descriptivo.
- `= 0`: valor inicial.

### Condición

```cpp
codigoOComando == 0
```

Produce verdadero o falso.

### Función

```cpp
int sumarDigitos(int numero)
```

- Primer `int`: devuelve un entero.
- `sumarDigitos`: nombre.
- `numero`: parámetro que necesita para trabajar.

### Función `bool`

```cpp
bool esCodigoValido(int numero)
```

Devuelve únicamente `true` o `false`.

## 4. `main`

```cpp
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
```

Puntos importantes:

1. El menú debe aparecer al menos una vez.
2. Por eso se usa `do while`.
3. `numeroPartida` permite alternar códigos secretos.
4. Al elegir `3`, termina el ciclo.

## 5. Funciones de dígitos

| Función | Explicación simple |
| :--- | :--- |
| `tieneTresDigitos` | Verifica que el número esté entre `100` y `999`. |
| `existeDigito` | Recorre un número buscando un dígito. |
| `tieneDigitosRepetidos` | Extrae cada dígito y busca si aparece otra vez. |
| `esCodigoValido` | Exige tres dígitos sin repetir. |
| `contarDigitosBienUbicados` | Compara exactamente tres posiciones. |
| `contarDigitosMalUbicados` | Cuenta existentes y resta bien ubicados. |
| `contarDigitosPares` | Cuenta dígitos cuyo residuo al dividir entre `2` es cero. |
| `sumarDigitos` | Acumula la suma de los dígitos. |

## 6. Patrón principal para recorrer dígitos

```cpp
while (numero > 0) {
    int digito = numero % 10;
    numero = numero / 10;
}
```

Ejemplo:

| Número | `% 10` | `/ 10` |
| ---: | ---: | ---: |
| `527` | `7` | `52` |
| `52` | `2` | `5` |
| `5` | `5` | `0` |

## 7. Funciones de interacción

| Función | Explicación simple |
| :--- | :--- |
| `leerEntero` | Lee un entero y se recupera si el usuario escribe texto. |
| `mostrarMenuPrincipal` | Muestra las tres opciones iniciales. |
| `pedirOpcionMenuPrincipal` | Valida que la opción sea `1`, `2` o `3`. |
| `mostrarInstrucciones` | Explica cómo jugar. |
| `pedirCantidadIntentos` | Pide un número entre `1` y `20`. |
| `pedirCodigoOComando` | Acepta un código válido o el comando `0`. |
| `mostrarErrorCodigo` | Muestra el motivo concreto del rechazo. |
| `mostrarEstadoPartida` | Muestra intentos restantes y pistas utilizadas. |

## 8. Funciones de pistas

### `mostrarMenuPistas`

Muestra cinco pistas y una opción para regresar.

### `pedirTipoPista`

Acepta únicamente opciones entre `1` y `6`.

### `mostrarPista`

Recibe:

```cpp
tipoPista
codigoSecreto
ultimoIntento
```

Retorna:

```cpp
true  // mostró una pista útil
false // no mostró una pista
```

La respuesta permite incrementar `pistasUsadas` únicamente cuando corresponde.

## 9. Función `jugar`

Variables:

| Variable | Uso |
| :--- | :--- |
| `cantidadIntentos` | Límite elegido por el jugador. |
| `codigoSecreto` | Código que debe adivinar. |
| `intentosUsados` | Cantidad de códigos válidos ingresados. |
| `pistasUsadas` | Cantidad de pistas mostradas. |
| `ultimoIntento` | Último código válido para calcular pistas. |
| `gano` | Indica si la partida terminó con victoria. |

Condición:

```cpp
while (intentosUsados < cantidadIntentos && gano == false)
```

La partida continúa si:

1. Todavía quedan intentos.
2. El jugador todavía no ganó.

## 10. Decisión central del turno

```cpp
if (codigoOComando == 0) {
    // abrir pistas
} else {
    // procesar intento
}
```

El comando `0` es adecuado porque un código válido debe tener tres dígitos.

## 11. Puntaje

```cpp
int puntaje = 1100 - intentosUsados * 100;
```

El cálculo premia resolver el juego usando pocos intentos.

## 12. Mapa de llamadas

```text
main
├── mostrarMenuPrincipal
├── pedirOpcionMenuPrincipal
│   └── leerEntero
├── mostrarInstrucciones
└── jugar
    ├── pedirCantidadIntentos
    │   └── leerEntero
    ├── elegirCodigoSecreto
    ├── mostrarEstadoPartida
    ├── pedirCodigoOComando
    │   ├── leerEntero
    │   ├── esCodigoValido
    │   │   ├── tieneTresDigitos
    │   │   └── tieneDigitosRepetidos
    │   │       └── existeDigito
    │   └── mostrarErrorCodigo
    ├── pedirTipoPista
    │   ├── mostrarMenuPistas
    │   └── leerEntero
    ├── mostrarPista
    │   ├── contarDigitosBienUbicados
    │   ├── contarDigitosMalUbicados
    │   ├── contarDigitosPares
    │   └── sumarDigitos
    └── calcularPuntaje
```

## 13. Ejemplo completo

Primera partida:

```text
numeroPartida = 1
codigoSecreto = 527
cantidadIntentos = 7
```

Jugador:

```text
572
```

Después pide pistas:

```text
0
1
```

Resultado:

```text
Bien ubicados: 1
```

Luego:

```text
0
2
```

Resultado:

```text
Mal ubicados: 2
```

Finalmente:

```text
527
```

Resultado:

```text
Ganó usando 2 intentos.
Puntaje: 900.
```
