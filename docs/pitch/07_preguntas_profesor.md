# Preguntas probables

## Concepto

### ¿Qué hace tu proyecto?

El jugador debe descubrir un código secreto de tres dígitos diferentes. Después de cada intento incorrecto recibe pistas automáticas. También puede pedir ayudas extra con comandos negativos.

### ¿Por qué el juego es de deducción?

Porque cada intento entrega información que ayuda a mejorar el siguiente.

### ¿Por qué el usuario elige la cantidad de intentos?

Para ajustar la dificultad sin añadir niveles artificiales.

## Estructura

### ¿Qué es un prototipo?

Anuncia el tipo de retorno, nombre y parámetros de una función:

```cpp
int sumarDigitos(int numero);
```

### ¿Cuál es la diferencia entre prototipo, llamada y definición?

- Prototipo: anuncia.
- Llamada: ejecuta.
- Definición: contiene la lógica.

### ¿Por qué todo está en un `.cpp`?

Porque es la forma de entrega solicitada. Las funciones mantienen el orden interno.

## Ciclos

### ¿Por qué usaste `do while`?

Porque el menú debe mostrarse al menos una vez.

### ¿Por qué usaste `while`?

Porque algunas repeticiones dependen de una condición: seguir jugando o seguir recorriendo dígitos.

### ¿Por qué usaste `for`?

Porque al comparar posiciones siempre se repite exactamente tres veces.

## Dígitos

### ¿Qué hace `% 10`?

Extrae el último dígito:

```text
527 % 10 = 7
```

### ¿Qué hace `/ 10`?

Elimina el último dígito usando división entera:

```text
527 / 10 = 52
```

### ¿Cómo detectas repeticiones sin arrays?

Extraigo un dígito, corto el número y busco si ese dígito aparece en la parte restante.

### ¿Cómo cuentas bien ubicados?

Comparo el último dígito del secreto con el último del intento y repito tres veces.

### ¿Cómo cuentas mal ubicados?

Cuento cuántos dígitos existen en el secreto y resto los que ya estaban bien ubicados.

## UX

### ¿Por qué las pistas básicas son automáticas?

Porque son el centro del juego. El jugador necesita esa información después de fallar.

### ¿Por qué usas comandos negativos?

Porque no pueden confundirse con códigos válidos de tres dígitos.

### ¿Qué hace `-1`?

Muestra la suma de los dígitos.

### ¿Qué hace `-2`?

Muestra cuántos dígitos pares existen.

### ¿Qué hace `-3`?

Indica si el código es mayor o menor que `500`.

### ¿Los comandos consumen intentos?

No. Solo una respuesta válida consume intento.

## Traza manual

### Con secreto `527` e intento `572`, ¿qué aparece?

```text
Bien ubicados: 1
Correctos en otra posicion: 2
```

### ¿Cuánto suman los dígitos de `527`?

```text
5 + 2 + 7 = 14
```

### ¿Cuántos pares tiene `527`?

Uno: el `2`.

### ¿Es válido `551`?

No. El `5` se repite.

## Preguntas sorpresa

### ¿Qué ocurriría si eliminas `/ 10`?

El número no cambia. El ciclo revisaría siempre el mismo dígito y podría no terminar.

### ¿Qué cambiarías para añadir una pista de impares?

Reutilizaría el recorrido de `contarDigitosPares`, pero preguntaría:

```cpp
digito % 2 != 0
```

### ¿Qué cambiarías para aceptar hasta `30` intentos?

Cambiaría el límite en `pedirCantidadIntentos`.
