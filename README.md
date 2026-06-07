# Código Secreto

Juego de consola desarrollado en C++ para el proyecto final de Introducción a la Programación.

El jugador debe descubrir un código secreto de cinco dígitos diferentes. El juego da una ayuda inicial gratis, permite pedir algunas ayudas opcionales y calcula un puntaje final según qué tan eficiente fue la partida.

## Cómo jugar

1. Seleccionar `1. Jugar`.
2. Elegir entre `5` y `20` intentos.
3. Recibir gratis un dígito con su posición.
4. En cada turno elegir entre intentar, revelar un dígito, pedir una pista o rendirse.
5. Al descubrir el código, completar el desafío final.

## Ayudas

La primera revelación es gratis. Después, el jugador puede pedir hasta `2` revelaciones extra. Cada revelación muestra un dígito exacto y su posición.

También puede pedir hasta `3` pistas indirectas:

| Pista | Qué muestra |
| ---: | :--- |
| `1` | Suma de todos los dígitos. |
| `2` | Cantidad de pares e impares. |
| `3` | Si el código completo es mayor o menor que `50000`. |

## Desafío final

Cuando el jugador descubre el código secreto, debe transformarlo intercalando pares e impares de mayor a menor, empezando por pares.

Ejemplo con `58274`:

```text
Pares de mayor a menor: 8, 4, 2
Impares de mayor a menor: 7, 5
Clave final: 87452
```

El jugador tiene `2` oportunidades para ingresar la clave final.

## Puntaje

El puntaje empieza en `100`:

- Resta `2` por cada intento elegido por encima de `5`.
- Resta `3` por cada intento usado.
- Resta `10` por cada revelación extra.
- Resta `7` por cada pista pedida.
- Resta `8` por cada error en el desafío final.
- Si no completa el juego, el puntaje final es `0`.

## Reglas técnicas

- Todo el programa está en `codigo.cpp`.
- Solo utiliza `<iostream>`.
- No utiliza arrays ni clases.
- Los dígitos se procesan con `% 10` y `/ 10`.
- Los prototipos están antes de `main`.
- Las definiciones están después de `main`.

## Compilar y ejecutar

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
./build/codigo_secreto
```

## Prueba rápida

La primera partida utiliza el código secreto `58274`:

```bash
printf '1\n10\n1\n58274\n87452\n3\n' | ./build/codigo_secreto
```

## Documentación

- [`codigo.md`](codigo.md): explicación técnica desde cero.
- [`docs/pitch/README.md`](docs/pitch/README.md): material para preparar la presentación.
