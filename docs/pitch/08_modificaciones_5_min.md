# Modificaciones presenciales de 5 minutos

## Método

1. Escuchar el pedido completo.
2. Repetirlo con tus palabras.
3. Identificar la función responsable.
4. Cambiar únicamente lo necesario.
5. Compilar.
6. Probar el caso mínimo.

```bash
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
```

Practica en una copia temporal y vuelve al código oficial después de cada ejercicio.

## Nivel 1

### 1. Permitir hasta 30 intentos

**Pedido:**

> Permite que el jugador elija hasta 30 intentos.

**Función:** `pedirCantidadIntentos`.

Cambiar mensajes y condición:

```cpp
while (cantidadIntentos < 1 || cantidadIntentos > 30)
```

### 2. Cambiar recomendación a 10 intentos

**Pedido:**

> Recomienda 10 intentos para principiantes.

**Función:** `pedirCantidadIntentos`.

```cpp
cout << "Recomendacion para principiantes: 10 intentos.\n";
```

### 3. Cambiar penalización del puntaje

**Pedido:**

> Resta 75 puntos por intento usado.

**Función:** `calcularPuntaje`.

Para conservar `1000` puntos al ganar en el primer intento:

```cpp
int puntaje = 1075 - intentosUsados * 75;
```

### 4. Cambiar el primer código secreto

**Pedido:**

> Cambia el primer código secreto por `942`.

**Función:** `elegirCodigoSecreto`.

```cpp
if (selector == 1) {
    codigoSecreto = 942;
}
```

## Nivel 2

### 5. Mostrar intentos usados en cada turno

**Pedido:**

> Muestra cuántos intentos ya utilizó el jugador.

**Función:** `mostrarEstadoPartida`.

```cpp
cout << "Intentos usados: " << intentosUsados << "\n";
```

### 6. Cambiar el comando de pistas a `9`

**Pedido:**

> Usa `9` en vez de `0` para abrir pistas.

**Funciones:** `pedirCodigoOComando`, `jugar`, mensajes e instrucciones.

Cambiar:

```cpp
codigoOComando != 9
codigoOComando == 9
```

Y actualizar los textos visibles.

### 7. Hacer que pedir una pista consuma un intento

**Pedido:**

> Cada pista debe consumir un intento.

**Función:** `jugar`.

Después de mostrar una pista válida:

```cpp
if (mostrarPista(tipoPista, codigoSecreto, ultimoIntento)) {
    pistasUsadas++;
    intentosUsados++;
}
```

### 8. Rechazar códigos que contienen cero

**Pedido:**

> Un código como `102` debe ser inválido.

**Cambio 1:** prototipo:

```cpp
bool contieneCero(int numero);
```

**Cambio 2:** definición:

```cpp
bool contieneCero(int numero) {
    return existeDigito(numero, 0);
}
```

**Cambio 3:** validación:

```cpp
return tieneTresDigitos(numero)
    && tieneDigitosRepetidos(numero) == false
    && contieneCero(numero) == false;
```

## Nivel 3

### 9. Añadir pista de cantidad de impares

**Pedido:**

> Añade una pista que muestre cuántos dígitos impares tiene el secreto.

**Cambio 1:** prototipo:

```cpp
int contarDigitosImpares(int numero);
```

**Cambio 2:** definición:

```cpp
int contarDigitosImpares(int numero) {
    int cantidadImpares = 0;

    while (numero > 0) {
        int digito = numero % 10;
        numero = numero / 10;

        if (digito % 2 != 0) {
            cantidadImpares++;
        }
    }

    return cantidadImpares;
}
```

**Cambio 3:** añadir opción en `mostrarMenuPistas`.

**Cambio 4:** aceptar el nuevo rango en `pedirTipoPista`.

**Cambio 5:** manejar la opción en `mostrarPista`.

### 10. Descontar puntos por cada pista

**Pedido:**

> Cada pista mostrada debe restar 25 puntos.

**Cambio 1:** prototipo:

```cpp
int calcularPuntaje(int intentosUsados, int pistasUsadas);
```

**Cambio 2:** definición:

```cpp
int calcularPuntaje(int intentosUsados, int pistasUsadas) {
    int puntaje = 1100 - intentosUsados * 100 - pistasUsadas * 25;

    if (puntaje < 0) {
        puntaje = 0;
    }

    return puntaje;
}
```

**Cambio 3:** llamada:

```cpp
calcularPuntaje(intentosUsados, pistasUsadas)
```

### 11. Contar códigos inválidos

**Pedido:**

> Muestra cuántos códigos inválidos escribió el jugador.

Una solución clara requiere:

1. Crear `int codigosInvalidos = 0`.
2. Incrementarlo cuando `esCodigoValido` sea falso.
3. Mostrarlo en el resumen.

Este cambio es más largo porque actualmente la validación está encapsulada en `pedirCodigoOComando`. Practícalo después de dominar los cambios anteriores.

## Registro

| Fecha | Modificación | Tiempo | ¿Compiló? | ¿La expliqué? |
| :--- | :--- | :--- | :--- | :--- |
| | | | | |
| | | | | |
| | | | | |
