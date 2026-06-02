# Análisis del enfoque del profesor

## Alcance

Este documento se basa en las lecciones disponibles en:

```text
/home/cszv/Documents/UCB-LIA/sis111/lessons
```

No intenta adivinar preguntas exactas. Resume patrones visibles para orientar la preparación.

## 1. Primero comprender el problema

Las lecciones definen un algoritmo como una secuencia finita, ordenada, coherente y concreta. Antes de programar, debes explicar el proceso con palabras simples.

En este proyecto:

```text
El jugador elige sus intentos.
Ingresa un código o escribe 0.
Si escribe 0, elige una pista.
Si escribe un código, el programa valida y compara.
El juego termina cuando gana o agota sus intentos.
```

## 2. Explicar visualmente el flujo

Las clases dan importancia a diagramas conectados de arriba hacia abajo, con inicio, fin, entradas, procesos y preguntas binarias.

Debes reconocer:

- Entrada del menú principal.
- Entrada de cantidad de intentos.
- Entrada de código o comando `0`.
- Pregunta: ¿escribió el comando?
- Pregunta: ¿el código es válido?
- Pregunta: ¿adivinó?
- Pregunta: ¿quedan intentos?

## 3. Elegir el ciclo por una razón

| Ciclo | Uso | Justificación |
| :--- | :--- | :--- |
| `do while` | Menú principal | Debe mostrarse al menos una vez. |
| `while` | Partida | No se sabe en qué intento ganará el jugador. |
| `while` | Validaciones | Se repiten mientras el dato sea inválido. |
| `while` | Recorrer dígitos | Se repite mientras todavía queden dígitos. |
| `for` | Comparar posiciones | Siempre se revisan exactamente tres posiciones. |

## 4. Dominar operadores simples

Debes diferenciar:

| Operador | Significado |
| :--- | :--- |
| `=` | Asignar un valor. |
| `==` | Comparar valores. |
| `!=` | Comprobar que dos valores son diferentes. |
| `&&` | Exigir que ambas condiciones sean verdaderas. |
| `||` | Aceptar que al menos una condición sea verdadera. |
| `%` | Obtener el residuo. |

## 5. Procesar números matemáticamente

Las clases de abril trabajan repetidamente con:

```cpp
digito = numero % 10;
numero = numero / 10;
```

Este patrón se usa en Código Secreto para:

- Detectar repeticiones.
- Comparar posiciones.
- Contar dígitos pares.
- Sumar dígitos.

## 6. Adaptar condiciones

El profesor muestra variantes donde la estructura se mantiene y cambia una condición. La modificación presencial probablemente medirá esa capacidad.

Practica:

- Cambiar el límite máximo de intentos.
- Añadir un tipo de pista.
- Cambiar el puntaje.
- Rechazar códigos con cero.
- Contar dígitos impares.
- Hacer que pedir pistas reduzca el puntaje.

## 7. Forma recomendada de explicar una función

1. Objetivo.
2. Parámetros de entrada.
3. Variables iniciales.
4. Condición del ciclo.
5. Cambios dentro del ciclo.
6. Resultado retornado o mostrado.
7. Ejemplo corto.

## 8. Frases esenciales

```text
Extraigo un dígito.
Proceso ese dígito.
Elimino el dígito revisado.
Repito mientras queden dígitos.
```

```text
Uso for cuando conozco la cantidad exacta.
Uso while cuando dependo de una condición.
Uso do while cuando necesito ejecutar al menos una vez.
```
