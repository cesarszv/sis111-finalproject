# Código Secreto

Juego de consola desarrollado en C++ para el proyecto final de Introducción a la Programación.

El jugador debe descubrir un código secreto fijo de cinco dígitos diferentes. La partida tiene 10 intentos, una ayuda inicial gratis, 2 revelaciones opcionales, 3 pistas suaves, un desafío final y un puntaje.

## Cómo jugar

1. Seleccionar `1. jugar`.
2. Leer el dato gratis: posición `3` es `2`.
3. En cada turno elegir entre probar código, revelar dato, pedir pista o rendirse.
4. Si el código es correcto, resolver el desafío final.
5. Revisar el puntaje.

## Ayudas

El juego siempre muestra una ayuda gratis al inicio. Después el jugador puede pedir:

| Ayuda | Qué muestra |
| ---: | :--- |
| Revelación 1 | Dígito exacto en posición `1`. |
| Revelación 2 | Dígito exacto en posición `5`. |
| Pista 1 | Suma de los dígitos. |
| Pista 2 | Cantidad de pares e impares. |
| Pista 3 | Si el código es mayor que `50000`. |

## Desafío final

Cuando el jugador descubre el código, debe intercalar pares e impares de mayor a menor, empezando por pares.

Ejemplo con `58274`:

```text
Pares de mayor a menor: 8, 4, 2
Impares de mayor a menor: 7, 5
Clave final: 87452
```

## Puntaje

El puntaje empieza en `100`:

- Resta `4` por cada intento usado.
- Resta `12` por cada revelación usada.
- Resta `8` por cada pista usada.
- Resta `10` por cada error en el desafío final.
- Si no completa el juego, el puntaje final es `0`.

## Reglas técnicas

- Todo el programa está en `codigo.cpp`.
- Solo utiliza `<iostream>`.
- No utiliza arrays ni clases.
- Usa `while`, `for`, `if`, funciones y operaciones con dígitos.
- No usa `do while`.

## Compilar y ejecutar

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
./build/codigo_secreto
```

## Prueba rápida

```bash
printf '1\n1\n58274\n87452\n3\n' | ./build/codigo_secreto
```
