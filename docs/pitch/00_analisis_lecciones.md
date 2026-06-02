# Análisis del enfoque del profesor

## Alcance del análisis

Este documento se basa en las lecciones disponibles en:

```text
/home/cszv/Documents/UCB-LIA/sis111/lessons
```

No intenta adivinar preguntas exactas. Resume patrones visibles para orientar la preparación.

## 1. Primero comprender el problema

En las clases iniciales se define un algoritmo como una secuencia finita, ordenada, coherente y concreta. La idea se repite en las prácticas: antes de resolver un ejercicio, se debe comprender exactamente qué pide.

### Aplicación al proyecto

Antes de hablar de código, explica:

```text
El jugador ingresa un intento.
El programa valida el intento.
Si es incorrecto, compara sus tres dígitos con el código secreto.
Después muestra pistas.
```

## 2. Explicar visualmente el flujo

Las primeras lecciones dan importancia a diagramas conectados, de arriba hacia abajo, con inicio, fin, entradas, procesos y preguntas binarias.

### Aplicación al proyecto

Debes reconocer:

- Inicio y fin.
- Entrada del menú.
- Entrada de dificultad.
- Entrada de intento.
- Pregunta: ¿el intento es válido?
- Pregunta: ¿descubrió el código?
- Pregunta: ¿quedan intentos?

Los diagramas preparados están en [`06_diagramas_flujo.md`](06_diagramas_flujo.md).

## 3. Elegir el ciclo por una razón

Las lecciones distinguen:

- `for`: cuando se conoce exactamente la cantidad de repeticiones.
- `while`: cuando se repite según una condición y no se conoce exactamente cuántas iteraciones serán necesarias.

### Aplicación al proyecto

| Ciclo | Uso | Justificación |
| :--- | :--- | :--- |
| `do while` | Menú principal | Debe mostrarse al menos una vez. |
| `while` | Partida | No se sabe en qué intento ganará el jugador. |
| `while` | Buscar dígitos | No se sabe cuándo aparecerá el dígito buscado. |
| `for` | Comparar posiciones | Siempre se revisan exactamente tres posiciones. |

## 4. Dominar operadores simples

Las lecciones recalcan errores frecuentes:

- Confundir asignación `=` con comparación `==`.
- Confundir `&&` con `||`.
- No inicializar variables.

### Aplicación al proyecto

Debes poder explicar:

```cpp
while (intentosUsados < cantidadIntentos && gano == false)
```

La partida continúa solo si ambas condiciones son verdaderas.

## 5. Procesar números matemáticamente

Las clases de abril trabajan repetidamente con:

```cpp
digito = numero % 10;
numero = numero / 10;
```

También enseñan que la lógica debe comprenderse antes de traducirse a código.

### Aplicación al proyecto

Este es el centro técnico de Código Secreto:

- Extraer dígitos.
- Buscar un dígito.
- Detectar repeticiones.
- Comparar posiciones.
- Contar coincidencias.

## 6. Adaptar condiciones

En la lección sobre intercalación, el profesor muestra variantes donde la estructura se mantiene y cambia una condición: pares, impares, primos, no primos o Fibonacci.

### Aplicación a la evaluación

La modificación presencial probablemente medirá si puedes cambiar una regla pequeña sin reescribir todo el programa.

Por eso debes practicar:

- Cambiar intentos.
- Añadir una dificultad.
- Modificar el puntaje.
- Añadir una validación.
- Crear una función sencilla de dígitos.
- Mostrar información adicional.

## 7. Nivel de explicación recomendado

Para cada función usa siempre esta secuencia:

1. Objetivo.
2. Datos de entrada.
3. Variables iniciales.
4. Condición del ciclo.
5. Cambios dentro del ciclo.
6. Resultado.
7. Ejemplo corto.

## 8. Conclusión para estudiar

La mejor preparación no es memorizar `codigo.cpp`. Es dominar estas frases:

```text
Extraigo un dígito.
Proceso ese dígito.
Elimino el dígito ya revisado.
Repito mientras sea necesario.
```

Y también:

```text
Uso for cuando conozco la cantidad exacta.
Uso while cuando dependo de una condición.
Uso do while cuando necesito ejecutar al menos una vez.
```
