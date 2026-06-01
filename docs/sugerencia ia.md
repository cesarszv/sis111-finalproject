# Código Secreto

## 1. Concepto del juego

**Código Secreto** es un juego de consola. El jugador debe descubrir un número oculto de 3 dígitos en un máximo de 7 intentos.

Después de cada intento, el programa indica:

- Cuántos dígitos están en la posición correcta.
- Cuántos dígitos existen, pero están en otra posición.
- Si el jugador ganó o perdió.
- El puntaje final según los intentos restantes.

Ejemplo:

```text
=== CODIGO SECRETO ===
Intento 1 de 7: 527
Digitos correctos y bien ubicados: 1
Digitos correctos pero mal ubicados: 1
```

## 2. Alcance recomendado

Para terminar el proyecto en poco tiempo:

1. Usa códigos de 3 dígitos sin dígitos repetidos.
2. Alterna entre 5 códigos predefinidos mediante condicionales.
3. Añade tres dificultades:
   - Fácil: 10 intentos.
   - Normal: 7 intentos.
   - Difícil: 5 intentos.
4. Muestra instrucciones, puntaje y opción para volver a jugar.

La base evita arrays y bibliotecas adicionales. Si el profesor permite agregar una biblioteca para generar valores aleatorios, esa mejora puede incorporarse después de terminar la versión funcional.

## 3. Por qué conviene

El juego utiliza exactamente lo que aparece en las lecciones y los prácticos:

- Condicionales `if`.
- Ciclos `while` y `for`.
- Funciones.
- Extracción de dígitos con `% 10`.
- Eliminación de dígitos con `/ 10`.
- Contadores y validación de entrada.

Además, parece más elaborado de lo que realmente es. No necesitas gráficos, clases ni librerías complejas.

## 4. Segunda fase: Clave reordenada

La mejor funcionalidad adicional está en la clase del 28 de abril: agregar una **segunda fase de desbloqueo** basada en intercalación de dígitos.

Adivinar el código no abre inmediatamente la bóveda. Después, el jugador debe ingresar una clave transformada siguiendo una regla seleccionada por el programa.

Ejemplo:

```text
Codigo descubierto: 7316425
Regla: intercalar pares e impares de mayor a menor

Pares:   6, 4, 2
Impares: 7, 5, 3, 1

Clave final: 6745231
```

El jugador debe calcular e ingresar `6745231`. Solo tiene dos oportunidades.

### Reglas posibles

- Intercalar pares e impares de mayor a menor.
- Intercalar primos y no primos de mayor a menor.
- Intercalar pares ascendentes e impares descendentes.
- Separar el código en grupos de `ND = 2` dígitos.

Esto está directamente basado en [SIS111 2026-04-28.md](/home/cszv/Documents/UCB-LIA/sis111/lessons/SIS111%202026-04-28.md:221) y la segmentación `ND` de [SIS111 2026-04-22.md](/home/cszv/Documents/UCB-LIA/sis111/lessons/SIS111%202026-04-22.md:311).

Esta mejora eleva la dificultad lógica del programa: requiere ordenar, crear copias del número, clasificar dígitos y reconstruir una nueva clave. No se limita a hacer más difícil la partida.

## 5. Organización inicial del código

El juego podría dividirse en funciones como:

```cpp
mostrarMenu();
elegirCodigoSecreto();
contarDigitosBienUbicados();
contarDigitosExistentes();
calcularPuntaje();
jugar();
```

## 6. Explicación para el docente

> Además de las pistas, agregaré una segunda fase. Cuando el jugador descubra el código, deberá transformarlo según una regla seleccionada por el programa: por ejemplo, intercalar pares e impares ordenados, o primos y no primos. Tendrá intentos limitados para ingresar la clave final. Así aplicaré ordenamiento, intercalación, segmentación y reconstrucción de números.

## 7. Ideas alternativas

- Batalla matemática por turnos: responder operaciones para atacar a un enemigo.
- Adivina el número con pistas: mayor, menor, par, impar o primo.
- Carrera de dados en consola: dos jugadores avanzan hasta llegar a la meta.

La mejor relación entre presentación y tiempo es **Código Secreto**. Permite demostrar manipulación de números, que es el tema más trabajado en las lecciones, sin ampliar demasiado el proyecto.
