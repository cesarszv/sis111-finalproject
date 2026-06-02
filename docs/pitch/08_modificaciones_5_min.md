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

### Permitir hasta `30` intentos

Modificar `pedirCantidadIntentos`:

```cpp
while (cantidadIntentos < 1 || cantidadIntentos > 30)
```

### Cambiar el primer secreto

Modificar `elegirCodigoSecreto`:

```cpp
codigoSecreto = 942;
```

### Cambiar el límite de comparación

Para preguntar si el secreto es mayor o menor que `600`, modificar textos y condición:

```cpp
codigoSecreto > 600
```

## Nivel medio

### Hacer que una pista extra consuma intento

En `jugar`:

```cpp
if (codigoOComando < 0) {
    mostrarPistaExtra(codigoOComando, codigoSecreto);
    intentosUsados++;
}
```

### Rechazar códigos que contienen cero

Añadir:

```cpp
bool contieneCero(int numero) {
    return existeDigito(numero, 0);
}
```

Y usarla desde `esCodigoValido`.

### Añadir mensaje con intentos usados

Dentro del ciclo de `jugar`:

```cpp
cout << "Intentos usados: " << intentosUsados << "\n";
```

## Nivel avanzado

### Añadir pista `-4`: cantidad de impares

Crear:

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

Después:

1. Añadir prototipo.
2. Aceptar `-4` en `pedirCodigoOComando`.
3. Mostrar la nueva pista en `mostrarPistaExtra`.
4. Actualizar textos visibles.

## Registro

| Modificación | Tiempo | ¿Compiló? | ¿Pude explicarla? |
| :--- | :--- | :--- | :--- |
| | | | |
| | | | |
| | | | |
