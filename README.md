# Código Secreto

Juego de consola desarrollado en C++ para el proyecto final de Introducción a la Programación.

El jugador debe descubrir un código secreto de tres dígitos diferentes. El proyecto utiliza lógica básica: variables, condicionales, ciclos, funciones y operaciones matemáticas sobre números enteros.

## Cómo se juega

1. Seleccionar `1. Jugar`.
2. Elegir cuántos intentos tendrá la partida: entre `1` y `20`.
3. Escribir un código de tres dígitos diferentes.
4. Escribir `0` durante cualquier turno para abrir el menú de pistas.
5. Continuar hasta descubrir el código o agotar los intentos.

Pedir una pista no consume intentos.

## Tipos de pista

| Opción | Pista |
| ---: | :--- |
| `1` | Cantidad de dígitos bien ubicados en el último intento. |
| `2` | Cantidad de dígitos correctos, pero ubicados en otra posición. |
| `3` | Cantidad de dígitos pares del código secreto. |
| `4` | Suma de los dígitos del código secreto. |
| `5` | Indica si el código secreto es mayor o menor que `500`. |
| `6` | Volver a la partida sin pedir una pista. |

Las pistas `1` y `2` necesitan que el jugador haya realizado al menos un intento.

## Reglas técnicas

- Todo el programa está dentro de `codigo.cpp`.
- Solo se utiliza la biblioteca `<iostream>`.
- No se utilizan arrays, clases ni bibliotecas adicionales.
- Los dígitos se procesan con `% 10` y `/ 10`.
- Los prototipos están declarados antes de `main`.
- Las definiciones de las funciones están después de `main`.

## Puntaje

El puntaje depende de la cantidad de intentos usados:

```cpp
puntaje = 1100 - intentosUsados * 100;
```

| Intentos usados | Puntaje |
| ---: | ---: |
| `1` | `1000` |
| `2` | `900` |
| `3` | `800` |

Si el cálculo llega a ser negativo, el puntaje final se mantiene en `0`.

## Compilar y ejecutar

Desde la carpeta del proyecto:

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
./build/codigo_secreto
```

## Prueba automatizada rápida

La primera partida utiliza el código secreto `527`. Esta secuencia solicita una pista, falla una vez y luego gana:

```bash
printf '1\n7\n572\n0\n1\n527\n3\n' | ./build/codigo_secreto
```

## Documentación

- [`codigo.md`](codigo.md): explicación completa y diagrama principal.
- [`docs/sugerencia ia.md`](docs/sugerencia%20ia.md): alcance implementado y decisiones de diseño.
- [`docs/pitch/README.md`](docs/pitch/README.md): kit de preparación para la presentación.
