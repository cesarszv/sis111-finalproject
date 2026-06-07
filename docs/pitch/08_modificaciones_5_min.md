# Modificaciones presenciales de 5 minutos

## Método

1. Repetir el pedido con tus palabras.
2. Identificar la función responsable.
3. Cambiar lo mínimo.
4. Compilar.
5. Probar.

```bash
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
```

## Nivel fácil

### Permitir hasta `25` intentos

Modificar `pedirCantidadIntentos`:

```cpp
while (cantidadIntentos < 5 || cantidadIntentos > 25)
```

También actualizar el texto visible.

### Cambiar el primer secreto

Modificar `elegirCodigoSecreto`:

```cpp
codigoSecreto = 58274;
```

El nuevo código debe tener cinco dígitos diferentes.

### Cambiar el límite de comparación

Para preguntar si el secreto es mayor o menor que `60000`, modificar textos y condición:

```cpp
codigoSecreto > 60000
```

## Nivel medio

### Hacer que una pista reste más puntaje

Modificar `calcularPuntaje`:

```cpp
puntaje = puntaje - (pistasPedidas * 10);
```

### Rechazar códigos que contienen cero

Añadir:

```cpp
bool contieneCero(int numero) {
    return existeDigito(numero, 0);
}
```

Y usarla desde `esCodigoValido`.

### Cambiar la ayuda inicial

Modificar `revelarDigito` cuando `numeroRevelacion == 0`:

```cpp
int posicion = 2;
```

## Nivel avanzado

### Añadir una cuarta pista

Crear una nueva condición en `mostrarPistaIndirecta` para mostrar el primer dígito aproximado por rango.

Después:

1. Cambiar el límite de pistas de `3` a `4`.
2. Actualizar `mostrarMenuTurno`.
3. Actualizar el cálculo de puntaje.
4. Probar una partida usando la nueva pista.

## Registro

| Modificación | Tiempo | ¿Compiló? | ¿Pude explicarla? |
| :--- | :--- | :--- | :--- |
| | | | |
| | | | |
| | | | |
