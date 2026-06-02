# Simulacros de evaluación

## Puntaje

| Parte | Puntaje |
| :--- | ---: |
| Pregunta 1 | 33 |
| Pregunta 2 | 33 |
| Modificación cronometrada | 34 |

Usa un cronómetro real.

## Simulacro 1: fundamentos

### Pregunta 1

¿Por qué usaste `for` para comparar posiciones y `while` para recorrer dígitos?

### Pregunta 2

Explica `% 10` y `/ 10` usando `527`.

### Modificación

Permite hasta `30` intentos.

### Respuesta esperada

- `for`: exactamente tres posiciones.
- `while`: repetir mientras queden dígitos.
- `527 % 10 = 7`.
- `527 / 10 = 52`.
- Cambiar mensajes y límite en `pedirCantidadIntentos`.

## Simulacro 2: comando

### Pregunta 1

¿Por qué `0` funciona bien como comando?

### Pregunta 2

¿Cuál es la diferencia entre un código inválido y un intento fallido?

### Modificación

Cambia el comando de pistas de `0` a `9`.

### Respuesta esperada

- `0` no se confunde con un código de tres dígitos.
- Un inválido no consume intento; un código válido incorrecto sí.
- Actualizar condición y mensajes.

## Simulacro 3: pistas

### Pregunta 1

Con secreto `527` e intento `572`, explica las pistas `1` y `2`.

### Pregunta 2

¿Por qué `mostrarPista` retorna `bool`?

### Modificación

Haz que cada pista mostrada consuma un intento.

### Respuesta esperada

- Bien ubicados: `1`.
- Mal ubicados: `2`.
- El `bool` indica si se mostró una pista útil.
- Incrementar `intentosUsados` junto con `pistasUsadas`.

## Simulacro 4: funciones

### Pregunta 1

Explica prototipo, llamada y definición.

### Pregunta 2

Explica `sumarDigitos` con `527`.

### Modificación

Muestra intentos usados en cada turno.

### Respuesta esperada

- Prototipo anuncia, llamada ejecuta y definición contiene lógica.
- `5 + 2 + 7 = 14`.
- Añadir un `cout` en `mostrarEstadoPartida`.

## Simulacro 5: puntaje

### Pregunta 1

¿Por qué el puntaje depende de intentos usados y no de intentos restantes?

### Pregunta 2

¿Cómo evitas puntajes negativos?

### Modificación

Resta `75` puntos por intento usado, manteniendo `1000` al ganar en el primer intento.

### Respuesta esperada

- El jugador configura el máximo; usar restantes sería injusto.
- Aplicar mínimo de cero.
- Fórmula: `1075 - intentosUsados * 75`.

## Simulacro 6: validación

### Pregunta 1

Explica cómo detectas repeticiones sin arrays.

### Pregunta 2

¿Qué hace `leerEntero` cuando recibe texto?

### Modificación

Rechaza códigos que contienen cero.

### Respuesta esperada

- Extraer, cortar y buscar en la parte restante.
- Limpiar estado de `cin` y descartar entrada incorrecta.
- Crear `contieneCero` y usarla en `esCodigoValido`.

## Simulacro 7: ampliación

### Pregunta 1

¿Cómo funciona `contarDigitosPares`?

### Pregunta 2

Explica la condición principal de la partida.

### Modificación

Añade una pista para contar dígitos impares.

### Respuesta esperada

- Recorrer y evaluar `digito % 2 == 0`.
- Seguir si quedan intentos y todavía no ganó.
- Reutilizar estructura con `digito % 2 != 0`.

## Registro

| Fecha | Simulacro | Pregunta 1 | Pregunta 2 | Modificación | Total | Tema a reforzar |
| :--- | :--- | ---: | ---: | ---: | ---: | :--- |
| | | | | | | |
| | | | | | | |
| | | | | | | |
