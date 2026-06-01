# Código Secreto

Juego de consola para el proyecto final de Introducción a la Programación. El jugador debe descubrir un código oculto de 3 dígitos sin repetir.

Después de cada intento, el programa indica:

- Cuántos dígitos están en la posición correcta.
- Cuántos dígitos existen, pero están en otra posición.
- Si el jugador ganó o perdió.
- El puntaje final según la dificultad y los intentos restantes.

## Reglas respetadas

Esta primera versión usa únicamente:

- Variables numéricas y booleanas.
- Condicionales `if`.
- Ciclos `while` y `for`.
- Funciones.
- Extracción de dígitos con `% 10`.
- Eliminación de dígitos con `/ 10`.
- La biblioteca `<iostream>` para entrada y salida.

No usa arrays, clases ni bibliotecas adicionales. Los códigos predefinidos se alternan mediante condicionales para mantener la lógica dentro del contenido avanzado en clase.

## Estructura

| Archivo | Responsabilidad |
| :--- | :--- |
| `main.cpp` | Inicia el programa y controla el menú principal. |
| `main.md` | Explica a profundidad el flujo de `main.cpp`. |
| `juego.h` | Declara las funciones relacionadas con la partida. |
| `juego.cpp` | Implementa el menú, las dificultades, el puntaje y el ciclo del juego. |
| `juego.md` | Explica el header, las funciones y el flujo completo de una partida. |
| `logica_digitos.h` | Declara las operaciones reutilizables con dígitos. |
| `logica_digitos.cpp` | Implementa validaciones y conteos con `% 10` y `/ 10`. |
| `logica_digitos.md` | Explica la lógica numérica paso a paso y sus diagramas. |
| `docs/arquitectura.md` | Explica la lógica, la modularidad y el plan de ampliación. |
| `docs/despliegue_gratis.md` | Investiga cómo publicar una demo gratuita en internet. |

## Compilar

Desde esta carpeta:

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp juego.cpp logica_digitos.cpp -o build/codigo_secreto
```

## Ejecutar

```bash
./build/codigo_secreto
```

## Dificultades

- Fácil: 10 intentos.
- Normal: 7 intentos.
- Difícil: 5 intentos.

La base funcional está lista. La segunda fase propuesta, basada en intercalación de dígitos, debe añadirse después de comprobar que este flujo mínimo funciona correctamente.

## Publicar una demo gratis

La investigación actualizada y las alternativas se encuentran en [`docs/despliegue_gratis.md`](docs/despliegue_gratis.md).

Para la versión actual de consola, la recomendación es conservar GitHub como fuente oficial y crear una copia ejecutable multifichero en JDoodle. GitHub Pages con un embed de JDoodle queda como mejora opcional para una presentación pública.
