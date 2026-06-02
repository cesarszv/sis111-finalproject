# Código Secreto

Juego de consola desarrollado en C++ para el proyecto final de Introducción a la Programación.

El jugador debe descubrir un código secreto de tres dígitos diferentes. Después de cada intento incorrecto recibe pistas automáticas para deducir la respuesta.

## Cómo jugar

1. Seleccionar `1. Jugar`.
2. Elegir entre `1` y `20` intentos.
3. Ingresar códigos de tres dígitos diferentes.
4. Usar las pistas automáticas después de cada intento.
5. Pedir pistas extra con comandos negativos si se necesita ayuda.

## Pistas

Después de cada intento incorrecto aparecen automáticamente:

- Cantidad de dígitos correctos y bien ubicados.
- Cantidad de dígitos correctos que están en otra posición.

También existen tres comandos opcionales:

| Comando | Pista extra |
| ---: | :--- |
| `-1` | Suma de los dígitos del código secreto. |
| `-2` | Cantidad de dígitos pares. |
| `-3` | Indica si el código es mayor o menor que `500`. |

Las pistas extra no consumen intentos.

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

La primera partida utiliza el código secreto `527`:

```bash
printf '1\n7\n572\n-1\n527\n3\n' | ./build/codigo_secreto
```

## Documentación

- [`codigo.md`](codigo.md): explicación técnica desde cero.
- [`docs/pitch/README.md`](docs/pitch/README.md): material para preparar la presentación.
