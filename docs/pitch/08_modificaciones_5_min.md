# Modificaciones presenciales de 5 minutos

## Objetivo

La tercera parte de la evaluación vale **34 puntos**. Debes practicar cambios pequeños usando un cronómetro real.

## Método de trabajo durante la evaluación

1. Escucha el cambio completo.
2. Repite el requerimiento con tus palabras.
3. Identifica la función responsable.
4. Modifica únicamente lo necesario.
5. Compila.
6. Ejecuta una prueba que demuestre el cambio.

Comando:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
```

## Nivel 1: cambios fáciles

### Modificación 1: cambiar la cantidad de intentos

**Posible pedido:**

> Quiero que la dificultad difícil tenga solamente 4 intentos.

**Dónde modificar:** `obtenerCantidadIntentos`.

```cpp
} else {
    cantidadIntentos = 4;
}
```

**Qué demostrar:** elegir dificultad difícil y comprobar que aparece `Intento 1 de 4`.

### Modificación 2: cambiar el puntaje

**Posible pedido:**

> Quiero que cada intento restante valga 75 puntos.

**Dónde modificar:** `calcularPuntaje`.

```cpp
return dificultad * 100 + intentosRestantes * 75;
```

**Qué demostrar:** ganar una partida y explicar la nueva fórmula.

### Modificación 3: cambiar un código secreto

**Posible pedido:**

> Reemplaza el código `864` por `942`.

**Dónde modificar:** `elegirCodigoSecreto`.

```cpp
} else if (selector == 2) {
    codigoSecreto = 942;
```

**Control:** usar tres dígitos diferentes.

### Modificación 4: cambiar un mensaje

**Posible pedido:**

> Muestra un mensaje de despedida cuando el usuario salga.

**Dónde modificar:** al terminar el ciclo de `main`, antes de `return 0`.

```cpp
cout << "\nGracias por jugar.\n";
```

## Nivel 2: cambios probables

### Modificación 5: mostrar intentos restantes después de fallar

**Posible pedido:**

> Después de cada intento incorrecto, muestra cuántos intentos quedan.

**Dónde modificar:** dentro del `else` de `jugar`, después de mostrar las pistas.

```cpp
cout << "Intentos restantes: " << cantidadIntentos - intentosUsados << "\n";
```

**Qué explicar:** se resta la cantidad usada de la cantidad máxima.

### Modificación 6: añadir dificultad extrema

**Posible pedido:**

> Agrega una cuarta dificultad extrema con 3 intentos.

**Cambio 1:** en `pedirDificultad`, añadir:

```cpp
cout << "4. Extrema: 3 intentos\n";
```

**Cambio 2:** aceptar el nuevo rango:

```cpp
while (dificultad < 1 || dificultad > 4) {
    cout << "Dificultad invalida. Seleccione 1, 2, 3 o 4: ";
    dificultad = leerEntero();
}
```

**Cambio 3:** en `obtenerCantidadIntentos`:

```cpp
} else if (dificultad == 3) {
    cantidadIntentos = 5;
} else {
    cantidadIntentos = 3;
}
```

### Modificación 7: rechazar códigos que contengan cero

**Posible pedido:**

> El intento ya no puede contener el dígito cero.

**Cambio 1:** añadir prototipo:

```cpp
bool contieneCero(int numero);
```

**Cambio 2:** añadir definición:

```cpp
bool contieneCero(int numero) {
    return existeDigito(numero, 0);
}
```

**Cambio 3:** actualizar `esIntentoValido`:

```cpp
return tieneTresDigitos(numero)
    && tieneDigitosRepetidos(numero) == false
    && contieneCero(numero) == false;
```

**Qué demostrar:** `102` debe rechazarse.

### Modificación 8: otorgar un bono al ganar en el primer intento

**Posible pedido:**

> Si el jugador gana en el primer intento, suma 200 puntos.

**Dónde modificar:** dentro del bloque de victoria en `jugar`.

```cpp
int puntaje = calcularPuntaje(intentosRestantes, dificultad);

if (intentosUsados == 1) {
    puntaje = puntaje + 200;
}
```

## Nivel 3: cambios que exigen entender la lógica

### Modificación 9: mostrar la suma de los dígitos del código al perder

**Posible pedido:**

> Cuando el jugador pierda, muestra también la suma de los dígitos del código secreto.

**Cambio 1:** añadir prototipo:

```cpp
int sumarDigitos(int numero);
```

**Cambio 2:** añadir definición:

```cpp
int sumarDigitos(int numero) {
    int suma = 0;

    while (numero > 0) {
        suma = suma + numero % 10;
        numero = numero / 10;
    }

    return suma;
}
```

**Cambio 3:** dentro del bloque de derrota:

```cpp
cout << "Suma de sus digitos: " << sumarDigitos(codigoSecreto) << "\n";
```

**Tema evaluado:** `% 10`, `/ 10`, acumulador y `while`.

### Modificación 10: contar cuántos intentos inválidos ingresó el jugador

**Posible pedido:**

> Muestra cuántos códigos inválidos escribió el jugador antes de ingresar uno válido.

**Versión simple:** resolver dentro de `pedirIntento`.

```cpp
int pedirIntento() {
    int intento = 0;
    int intentosInvalidos = 0;

    cout << "Ingrese un codigo de 3 digitos sin repetir: ";
    intento = leerEntero();

    while (esIntentoValido(intento) == false) {
        intentosInvalidos++;
        cout << "Codigo invalido. Ingrese 3 digitos diferentes: ";
        intento = leerEntero();
    }

    cout << "Codigos invalidos ingresados: " << intentosInvalidos << "\n";

    return intento;
}
```

### Modificación 11: mostrar si el intento contiene algún dígito par

**Posible pedido:**

> Después de fallar, indica si el intento contiene al menos un dígito par.

**Cambio 1:** añadir prototipo:

```cpp
bool contieneDigitoPar(int numero);
```

**Cambio 2:** añadir definición:

```cpp
bool contieneDigitoPar(int numero) {
    bool contienePar = false;

    while (numero > 0 && contienePar == false) {
        int digito = numero % 10;
        numero = numero / 10;

        if (digito % 2 == 0) {
            contienePar = true;
        }
    }

    return contienePar;
}
```

**Cambio 3:** usar la función dentro del `else` de `jugar`.

```cpp
if (contieneDigitoPar(intento)) {
    cout << "El intento contiene al menos un digito par.\n";
}
```

### Modificación 12: hacer que los intentos inválidos consuman oportunidades

**Posible pedido:**

> Cada código inválido también debe consumir un intento.

Este cambio es más delicado porque actualmente `pedirIntento` repite internamente hasta obtener un valor válido. Primero explica esa situación al profesor.

Una solución simple consiste en pedir una sola vez dentro de `jugar` y decidir allí si se muestran pistas:

```cpp
cout << "Ingrese un codigo de 3 digitos sin repetir: ";
intento = leerEntero();
intentosUsados++;

if (esIntentoValido(intento) == false) {
    cout << "Codigo invalido. El intento fue consumido.\n";
} else if (intento == codigoSecreto) {
    gano = true;
} else {
    // calcular y mostrar pistas
}
```

Para practicar esta variante, trabaja en una copia temporal del archivo. No la apliques permanentemente antes de la presentación.

## Ejercicios con cronómetro

Practica en este orden:

| Sesión | Cambios | Meta |
| :--- | :--- | :--- |
| 1 | 1, 2, 3 y 4 | Menos de 3 minutos cada uno. |
| 2 | 5, 6, 7 y 8 | Menos de 5 minutos cada uno. |
| 3 | 9, 10 y 11 | Menos de 7 minutos al principio; luego menos de 5. |
| 4 | Elegir uno al azar | Menos de 5 minutos incluyendo compilación y prueba. |

## Plantilla mental para crear una función nueva

1. Definir qué dato entra.
2. Definir qué resultado sale.
3. Añadir prototipo arriba de `main`.
4. Añadir definición debajo de `main`.
5. Llamar la función desde el lugar correcto.
6. Compilar.
7. Ejecutar un caso que demuestre el cambio.
