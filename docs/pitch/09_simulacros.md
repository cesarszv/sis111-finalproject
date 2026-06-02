# Simulacros de evaluación

## Cómo usarlos

Cada simulacro representa la estructura anunciada:

| Parte | Puntaje |
| :--- | ---: |
| Pregunta 1 | 33 |
| Pregunta 2 | 33 |
| Modificación de 5 minutos | 34 |

Usa un cronómetro. No abras las respuestas hasta terminar.

## Criterio para puntuar tus respuestas

| Nivel | Puntaje orientativo por pregunta |
| :--- | ---: |
| Explicación clara, correcta y con ejemplo | 33 |
| Idea correcta, pero incompleta | 20 |
| Respuesta memorizada sin justificar | 10 |
| No puede responder | 0 |

Para la modificación:

| Resultado | Puntaje orientativo |
| :--- | ---: |
| Modifica, compila y demuestra el cambio | 34 |
| Modifica correctamente, pero no prueba | 24 |
| Identifica dónde cambiar, pero no termina | 12 |
| No identifica la función responsable | 0 |

---

## Simulacro 1: fundamentos

### Pregunta 1

¿Por qué usaste un ciclo `for` en `contarDigitosBienUbicados` y un ciclo `while` en `existeDigito`?

### Pregunta 2

Explica con el número `527` qué hacen `% 10` y `/ 10`.

### Modificación

Cambia la dificultad difícil de 5 intentos a 4 intentos. Compila y demuestra el cambio.

### Respuesta esperada

- `for`: compara exactamente tres posiciones.
- `while`: busca hasta encontrar el dígito o terminar el número; no se conoce de antemano cuándo ocurrirá.
- `527 % 10 = 7`.
- `527 / 10 = 52`.
- Cambio en `obtenerCantidadIntentos`.

---

## Simulacro 2: validación

### Pregunta 1

Explica cómo detectas que `551` tiene dígitos repetidos sin usar arrays.

### Pregunta 2

¿Cuál es la diferencia entre `=` y `==`? Muestra un ejemplo de tu proyecto.

### Modificación

Después de cada intento incorrecto, muestra cuántos intentos quedan. Compila y demuestra el cambio.

### Respuesta esperada

- Extraer `1`, buscarlo en `55`; luego extraer `5`, buscarlo en `5`; encontrar repetición.
- `=` asigna y `==` compara.
- Mostrar `cantidadIntentos - intentosUsados` dentro del `else` de `jugar`.

---

## Simulacro 3: pistas

### Pregunta 1

Con código secreto `864` e intento `468`, explica paso a paso las dos pistas.

### Pregunta 2

¿Por qué `contarDigitosMalUbicados` resta los bien ubicados?

### Modificación

Haz que cada intento restante valga 75 puntos en vez de 50. Compila y demuestra el cambio.

### Respuesta esperada

- Bien ubicados: `1`, porque el `6` coincide en posición.
- Existentes: `3`, porque `4`, `6` y `8` aparecen en el secreto.
- Mal ubicados: `3 - 1 = 2`.
- Cambiar la fórmula de `calcularPuntaje`.

---

## Simulacro 4: estructura del programa

### Pregunta 1

Explica la diferencia entre un prototipo, una llamada y una definición de función.

### Pregunta 2

¿Por qué el menú principal usa `do while`?

### Modificación

Agrega una dificultad extrema con 3 intentos. Compila y demuestra el cambio.

### Respuesta esperada

- El prototipo anuncia, la llamada ejecuta y la definición contiene la lógica.
- El menú debe mostrarse al menos una vez.
- Modificar menú, rango válido y conversión de dificultad a intentos.

---

## Simulacro 5: comprensión de condiciones

### Pregunta 1

Explica:

```cpp
while (intentosUsados < cantidadIntentos && gano == false)
```

### Pregunta 2

¿Qué pasaría si se elimina `/ 10` dentro de `existeDigito`?

### Modificación

Muestra un mensaje de despedida al salir del programa. Compila y demuestra el cambio.

### Respuesta esperada

- La partida sigue solo si quedan intentos y todavía no ganó.
- Sin `/ 10`, el número no cambia y el ciclo puede quedar revisando siempre lo mismo.
- Añadir `cout` antes de `return 0` en `main`.

---

## Simulacro 6: función nueva

### Pregunta 1

¿Por qué puedes dividir `codigoSecreto` dentro de una función sin destruir el valor original de la partida?

### Pregunta 2

¿Por qué usaste códigos predefinidos en lugar de números aleatorios?

### Modificación

Cuando el jugador pierda, muestra la suma de los dígitos del código secreto. Compila y demuestra el cambio.

### Respuesta esperada

- Los parámetros se reciben por valor: la función trabaja con copias locales.
- El alcance evita bibliotecas adicionales y mantiene lógica básica.
- Crear `sumarDigitos` con `% 10`, `/ 10`, acumulador y `while`.

---

## Simulacro 7: sorpresa controlada

### Pregunta 1

Explica cómo se selecciona el código secreto en una partida.

### Pregunta 2

¿Qué diferencia hay entre `&&` y `||`? Usa ejemplos del proyecto.

### Modificación

Impide que el jugador ingrese códigos que contengan el dígito cero. Compila y demuestra que `102` es rechazado.

### Respuesta esperada

- `(dificultad + numeroPartida) % 5` produce un selector de `0` a `4`.
- `&&`: ambas condiciones deben cumplirse. `||`: basta con una.
- Crear `contieneCero` y usarla desde `esIntentoValido`.

---

## Simulacro 8: evaluación final

Este simulacro no incluye respuestas inmediatas. Resuélvelo y revisa los documentos después.

### Pregunta 1

Explica el mapa completo desde que el usuario elige jugar hasta que recibe una pista.

### Pregunta 2

Explica por qué el proyecto cumple la restricción de lógica pura sin arrays.

### Modificación

Después de fallar, indica si el intento contiene al menos un dígito par. Compila y demuestra el cambio.

## Registro de resultados

| Fecha | Simulacro | Pregunta 1 | Pregunta 2 | Modificación | Total | Tema a reforzar |
| :--- | :--- | ---: | ---: | ---: | ---: | :--- |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
