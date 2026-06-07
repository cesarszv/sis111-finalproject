# Preguntas probables

## Concepto

### ¿Qué hace tu proyecto?

El jugador debe descubrir un código secreto de cinco dígitos diferentes. Puede pedir ayudas durante la partida, pero esas ayudas bajan su puntaje final.

### ¿Por qué el juego es de deducción?

Porque cada intento entrega información que ayuda a mejorar el siguiente.

### ¿Qué mejoró en la experiencia del usuario?

Antes todo dependía de comandos. Ahora el jugador ve un menú simple: intentar, revelar, pedir pista o rendirse.

### ¿Por qué el usuario elige la cantidad de intentos?

Porque así decide la dificultad. Elegir más intentos ayuda, pero también baja el puntaje potencial.

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

Porque el menú principal debe mostrarse al menos una vez.

### ¿Por qué usaste `while`?

Porque algunas repeticiones dependen de una condición: seguir jugando, validar entradas o recorrer dígitos.

### ¿Por qué usaste `for`?

Porque al comparar posiciones siempre se repite exactamente cinco veces.

## Dígitos

### ¿Qué hace `% 10`?

Extrae el último dígito:

```text
58274 % 10 = 4
```

### ¿Qué hace `/ 10`?

Elimina el último dígito usando división entera:

```text
58274 / 10 = 5827
```

### ¿Cómo detectas repeticiones sin arrays?

Extraigo un dígito, corto el número y busco si ese dígito aparece en la parte restante.

### ¿Cómo cuentas lugares exactos?

Comparo el último dígito del secreto con el último del intento y repito cinco veces.

### ¿Cómo cuentas dígitos correctos en otro lugar?

Cuento cuántos dígitos existen en el secreto y resto los que ya estaban en la posición exacta.

## UX

### ¿Por qué das una ayuda inicial gratis?

Porque el código tiene cinco dígitos. Un dato inicial hace que el juego arranque con una pista clara.

### ¿Por qué las revelaciones bajan puntaje?

Porque muestran un dígito exacto con posición. Son ayudas fuertes.

### ¿Por qué las pistas son indirectas?

Porque ayudan a pensar sin regalar el código.

### ¿Qué pistas existen?

Suma de dígitos, cantidad de pares e impares, y si el código es mayor o menor que `50000`.

### ¿Qué es el desafío final?

Es una segunda parte que aparece después de descubrir el código. El jugador debe intercalar pares e impares de mayor a menor.

### Con `58274`, ¿cuál es la clave final?

```text
Pares: 8, 4, 2
Impares: 7, 5
Clave final: 87452
```

## Puntaje

### ¿Cómo se calcula el puntaje?

Empieza en `100` y descuenta por intentos elegidos de más, intentos usados, revelaciones, pistas y errores en el desafío final.

### ¿Por qué el puntaje puede ser `0`?

Porque si el jugador no completa el código y el desafío final, la partida no se considera ganada.

## Traza manual

### Con secreto `58274` e intento `12345`, ¿qué aparece?

```text
Acertaste 0 lugares exactos.
Tienes 3 digitos correctos en otro lugar.
```

### ¿Cuánto suman los dígitos de `58274`?

```text
5 + 8 + 2 + 7 + 4 = 26
```

### ¿Cuántos pares tiene `58274`?

Tres: `8`, `2` y `4`.

### ¿Es válido `11234`?

No. El `1` se repite.

## Preguntas sorpresa

### ¿Qué ocurriría si eliminas `/ 10`?

El número no cambia. El ciclo revisaría siempre el mismo dígito y podría no terminar.

### ¿Qué cambiarías para permitir 25 intentos?

Cambiaría el límite en `pedirCantidadIntentos`.

### ¿Qué cambiarías para que una pista reste más puntaje?

Cambiaría la resta correspondiente dentro de `calcularPuntaje`.
