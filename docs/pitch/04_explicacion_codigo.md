# Explicación fácil de `codigo.cpp`

## 1. Cómo está organizado el archivo

El archivo tiene cuatro bloques:

| Bloque | Qué contiene |
| :--- | :--- |
| Inclusión | `#include <iostream>` permite usar `cin` y `cout`. |
| Prototipos | Anuncian qué funciones existirán. |
| `main` | Muestra el flujo principal del programa. |
| Definiciones | Contienen la lógica completa de cada función. |

## 2. Conceptos básicos

### Variable

Una variable es un espacio que guarda un valor. Ejemplo:

```cpp
int opcion = 0;
```

- `int`: el valor será un número entero.
- `opcion`: nombre de la variable.
- `= 0`: valor inicial.

### Condición

Una condición produce `true` o `false`.

```cpp
opcion == 1
```

- `=` asigna un valor.
- `==` compara dos valores.

### Función

Una función agrupa una tarea concreta.

```cpp
int calcularPuntaje(int intentosRestantes, int dificultad) {
    return dificultad * 100 + intentosRestantes * 50;
}
```

- Primer `int`: la función devuelve un entero.
- `calcularPuntaje`: nombre de la función.
- Parámetros: datos que necesita para trabajar.
- `return`: resultado que devuelve.

### Prototipo

El prototipo anuncia una función antes de escribir su lógica completa:

```cpp
int calcularPuntaje(int intentosRestantes, int dificultad);
```

Termina con `;` porque todavía no contiene instrucciones.

## 3. Flujo de `main`

```cpp
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
```

Paso a paso:

1. `opcion` guarda la decisión del usuario.
2. `numeroPartida` comienza en `1`.
3. El `do while` muestra el menú al menos una vez.
4. Si la opción es `1`, inicia una partida.
5. Si la opción es `2`, muestra instrucciones.
6. Si la opción es `3`, el ciclo termina.

### Pregunta esperable

**¿Por qué usaste `do while` y no `while`?**

Porque el menú debe mostrarse al menos una vez. En un `do while`, primero se ejecutan las instrucciones y después se revisa la condición.

## 4. Funciones para validar dígitos

### `tieneTresDigitos`

```cpp
bool tieneTresDigitos(int numero) {
    return numero >= 100 && numero <= 999;
}
```

Comprueba que el valor esté entre `100` y `999`.

- `&&` significa "y".
- Ambas condiciones deben cumplirse.

Ejemplos:

| Número | Resultado | Motivo |
| ---: | :--- | :--- |
| `55` | `false` | Tiene menos de tres dígitos. |
| `527` | `true` | Está entre `100` y `999`. |
| `1000` | `false` | Tiene más de tres dígitos. |

### `existeDigito`

```cpp
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
```

Busca un dígito dentro de un número.

Ejemplo: buscar `2` dentro de `527`.

| Paso | `numero` antes | `numero % 10` | ¿Es `2`? | `numero / 10` |
| :--- | ---: | ---: | :--- | ---: |
| 1 | `527` | `7` | No | `52` |
| 2 | `52` | `2` | Sí | `5` |

El ciclo termina porque `encontrado` cambia a `true`.

### `tieneDigitosRepetidos`

```cpp
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
```

Extrae un dígito y busca si vuelve a aparecer en la parte restante.

Ejemplo con `551`:

| Paso | Dígito extraído | Parte restante | ¿El dígito aparece otra vez? |
| :--- | ---: | ---: | :--- |
| 1 | `1` | `55` | No |
| 2 | `5` | `5` | Sí |

Resultado: tiene dígitos repetidos.

### `esIntentoValido`

```cpp
bool esIntentoValido(int numero) {
    return tieneTresDigitos(numero) && tieneDigitosRepetidos(numero) == false;
}
```

Un intento es válido cuando:

1. Tiene tres dígitos.
2. No tiene dígitos repetidos.

## 5. Funciones para calcular pistas

### `contarDigitosBienUbicados`

```cpp
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
```

Usa `for` porque siempre compara exactamente tres posiciones.

Ejemplo: código `864`, intento `468`.

| Posición revisada desde la derecha | Código | Intento | ¿Coinciden? |
| :--- | ---: | ---: | :--- |
| 1 | `4` | `8` | No |
| 2 | `6` | `6` | Sí |
| 3 | `8` | `4` | No |

Resultado: `1` dígito bien ubicado.

### `contarDigitosMalUbicados`

```cpp
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
```

Paso a paso:

1. Cuenta los dígitos que existen en cualquier posición.
2. Ya conoce cuántos estaban bien ubicados.
3. Resta los bien ubicados para dejar únicamente los mal ubicados.

Ejemplo: código `864`, intento `468`.

- Existen los tres dígitos: `4`, `6` y `8`.
- Un dígito está bien ubicado: `6`.
- Mal ubicados: `3 - 1 = 2`.

## 6. Funciones para interactuar con el usuario

### `leerEntero`

Lee un número entero. Si el usuario escribe letras, limpia el error y solicita otro valor.

```cpp
cin.clear();
cin.ignore(1000, '\n');
```

- `cin.clear()` elimina el estado de error.
- `cin.ignore(1000, '\n')` descarta la entrada incorrecta hasta el salto de línea.

### `mostrarMenu`

Muestra las opciones disponibles.

### `pedirOpcionMenu`

Solicita una opción y repite la pregunta mientras esté fuera del rango `1` a `3`.

### `mostrarInstrucciones`

Explica las reglas al jugador.

## 7. Funciones para preparar la partida

### `pedirDificultad`

Permite elegir:

| Opción | Dificultad | Intentos |
| ---: | :--- | ---: |
| `1` | Fácil | `10` |
| `2` | Normal | `7` |
| `3` | Difícil | `5` |

### `obtenerCantidadIntentos`

Convierte la opción de dificultad en una cantidad máxima de intentos.

### `elegirCodigoSecreto`

Elige uno de cinco códigos predefinidos:

```text
527, 731, 864, 392, 615
```

Usa:

```cpp
int selector = (dificultad + numeroPartida) % 5;
```

El resultado de `% 5` siempre está entre `0` y `4`. Eso permite elegir una de cinco posibilidades con condicionales, sin arrays ni generación aleatoria.

### `pedirIntento`

Solicita códigos hasta recibir uno válido.

## 8. Funciones para cerrar la partida

### `calcularPuntaje`

```cpp
return dificultad * 100 + intentosRestantes * 50;
```

El puntaje premia:

- Elegir una dificultad mayor.
- Resolver el código con más intentos restantes.

### `jugar`

Es la función que coordina una partida completa.

Variables principales:

| Variable | Uso |
| :--- | :--- |
| `dificultad` | Nivel seleccionado. |
| `cantidadIntentos` | Máximo permitido. |
| `codigoSecreto` | Número oculto. |
| `intentosUsados` | Cantidad consumida. |
| `gano` | Indica si el jugador descubrió el código. |

Condición del ciclo:

```cpp
while (intentosUsados < cantidadIntentos && gano == false)
```

La partida continúa únicamente si:

1. Todavía quedan intentos.
2. El jugador todavía no ganó.

## 9. Mapa de llamadas

```text
main
├── mostrarMenu
├── pedirOpcionMenu
│   └── leerEntero
├── mostrarInstrucciones
└── jugar
    ├── pedirDificultad
    │   └── leerEntero
    ├── obtenerCantidadIntentos
    ├── elegirCodigoSecreto
    ├── pedirIntento
    │   ├── leerEntero
    │   └── esIntentoValido
    │       ├── tieneTresDigitos
    │       └── tieneDigitosRepetidos
    │           └── existeDigito
    ├── contarDigitosBienUbicados
    ├── contarDigitosMalUbicados
    │   ├── contarDigitosBienUbicados
    │   └── existeDigito
    └── calcularPuntaje
```

## 10. Ideas que debes poder explicar sin mirar

1. El menú usa `do while` porque debe aparecer al menos una vez.
2. La partida usa `while` porque no sabemos en qué intento ganará el jugador.
3. La comparación de posiciones usa `for` porque siempre se repite tres veces.
4. `% 10` extrae el último dígito.
5. `/ 10` elimina el último dígito.
6. Los parámetros numéricos se reciben por valor, así que las copias locales se pueden modificar sin destruir las variables originales.
7. Los prototipos permiten colocar `main` antes de las definiciones.
