# Banco de preguntas del profesor

## Cómo practicar

La evaluación incluye dos preguntas sobre el proyecto. Para practicar:

1. Lee únicamente la pregunta.
2. Responde en voz alta sin mirar.
3. Compara tu respuesta con la respuesta modelo.
4. Repite hasta responder con claridad en menos de un minuto.

No memorices palabra por palabra. Comprende la idea.

## Preguntas de prioridad alta

### 1. ¿Qué hace tu proyecto?

**Respuesta corta:**

Código Secreto es un juego de consola donde el jugador debe descubrir un número oculto de tres dígitos diferentes. Después de cada intento incorrecto recibe pistas sobre dígitos bien ubicados y mal ubicados.

### 2. ¿Qué temas de la materia aplicaste?

**Respuesta corta:**

Usé variables, condicionales, funciones, `while`, `do while`, `for`, operadores lógicos, `% 10`, `/ 10`, contadores y validación de entradas.

### 3. ¿Qué es un prototipo de función?

**Respuesta corta:**

Es una declaración que informa al compilador el nombre de una función, el tipo de dato que devuelve y los parámetros que recibe. Termina con punto y coma porque todavía no incluye la lógica.

**Ejemplo:**

```cpp
int calcularPuntaje(int intentosRestantes, int dificultad);
```

### 4. ¿Cuál es la diferencia entre prototipo, llamada y definición?

**Respuesta corta:**

- El prototipo anuncia que la función existirá.
- La llamada ejecuta la función.
- La definición contiene las instrucciones completas.

```cpp
int calcularPuntaje(int intentosRestantes, int dificultad); // prototipo
puntaje = calcularPuntaje(9, 1);                            // llamada

int calcularPuntaje(int intentosRestantes, int dificultad) { // definición
    return dificultad * 100 + intentosRestantes * 50;
}
```

### 5. ¿Por qué usaste `% 10`?

**Respuesta corta:**

Porque `% 10` devuelve el residuo de dividir entre diez, que corresponde al último dígito del número. Por ejemplo, `527 % 10` es `7`.

### 6. ¿Por qué usaste `/ 10`?

**Respuesta corta:**

Porque la división entera entre diez elimina el último dígito. Por ejemplo, `527 / 10` es `52`.

### 7. ¿Por qué usaste `for` para contar dígitos bien ubicados?

**Respuesta corta:**

Porque sé exactamente cuántas posiciones debo comparar: tres. El `for` es adecuado cuando la cantidad de repeticiones es conocida.

### 8. ¿Por qué usaste `while` dentro de la partida?

**Respuesta corta:**

Porque la cantidad real de intentos usados no se conoce de antemano. La partida continúa mientras queden intentos y el jugador todavía no haya ganado.

### 9. ¿Por qué usaste `do while` en `main`?

**Respuesta corta:**

Porque el menú debe mostrarse al menos una vez. El `do while` ejecuta primero y revisa la condición al final.

### 10. ¿Qué significa esta condición?

```cpp
while (intentosUsados < cantidadIntentos && gano == false)
```

**Respuesta corta:**

La partida continúa únicamente mientras todavía queden intentos y el jugador no haya descubierto el código. `&&` exige que ambas condiciones sean verdaderas.

### 11. ¿Cuál es la diferencia entre `=` y `==`?

**Respuesta corta:**

- `=` asigna un valor.
- `==` compara dos valores.

Ejemplo:

```cpp
gano = true;          // asignación
intento == codigoSecreto // comparación
```

### 12. ¿Cómo validas un intento?

**Respuesta corta:**

Compruebo que tenga exactamente tres dígitos y que no repita ninguno. La función `esIntentoValido` combina ambas condiciones.

### 13. ¿Cómo detectas dígitos repetidos sin arrays?

**Respuesta corta:**

Extraigo un dígito con `% 10`, corto el número con `/ 10` y busco si ese dígito aparece en la parte restante. Repito hasta encontrar una repetición o terminar el número.

### 14. ¿Cómo cuentas los dígitos bien ubicados?

**Respuesta corta:**

Comparo el último dígito del código secreto con el último dígito del intento. Después corto ambos números y repito exactamente tres veces.

### 15. ¿Cómo cuentas los dígitos mal ubicados?

**Respuesta corta:**

Primero cuento cuántos dígitos del intento existen en el código secreto. Luego resto los que ya estaban bien ubicados. Así quedan únicamente los correctos que están en otra posición.

### 16. ¿Por qué restas los bien ubicados?

**Respuesta corta:**

Porque un dígito bien ubicado también existe dentro del código. Si no lo resto, lo contaría incorrectamente como mal ubicado.

### 17. ¿Por qué el código secreto no es aleatorio?

**Respuesta corta:**

Para respetar el alcance de Introducción a la Programación y evitar bibliotecas adicionales. Uso cinco códigos predefinidos y los alterno con condicionales.

### 18. ¿Cómo eliges uno de los cinco códigos?

**Respuesta corta:**

Calculo:

```cpp
(dificultad + numeroPartida) % 5
```

El residuo siempre queda entre `0` y `4`, así puedo seleccionar una de cinco opciones con `if` y `else if`.

### 19. ¿Por qué no usaste arrays?

**Respuesta corta:**

Porque el proyecto sigue la restricción de trabajar con lógica básica. En lugar de guardar dígitos en un array, los proceso matemáticamente con `% 10` y `/ 10`.

### 20. ¿Cómo calculas el puntaje?

**Respuesta corta:**

Uso:

```cpp
dificultad * 100 + intentosRestantes * 50
```

La fórmula premia una dificultad mayor y resolver el código usando menos intentos.

## Preguntas de prioridad media

### 21. ¿Qué es una función `bool`?

Devuelve únicamente `true` o `false`. Es útil para representar preguntas como: "¿tiene tres dígitos?" o "¿existe este dígito?".

### 22. ¿Qué hace `return`?

Devuelve el resultado de una función al lugar desde donde fue llamada.

### 23. ¿Qué hace `numeroPartida++`?

Incrementa `numeroPartida` en uno. Es equivalente a:

```cpp
numeroPartida = numeroPartida + 1;
```

### 24. ¿Por qué inicializas variables?

Porque una variable debe comenzar con un valor conocido antes de usarla. Por ejemplo, un contador debe comenzar en cero.

### 25. ¿Qué hace `cin.clear()`?

Limpia el estado de error de `cin` cuando el usuario ingresa un dato inválido, como letras en lugar de un número.

### 26. ¿Qué hace `cin.ignore(1000, '\n')`?

Descarta la entrada incorrecta hasta encontrar el salto de línea. Así el programa puede pedir un dato nuevo.

### 27. ¿Qué diferencia hay entre `if` y `else if`?

Un `if` independiente siempre puede evaluarse. Un `else if` solo se evalúa cuando las condiciones anteriores de la misma cadena fueron falsas.

### 28. ¿Por qué recibes `codigoSecreto` e `intento` como parámetros?

Porque esas funciones necesitan comparar valores concretos. Los parámetros permiten reutilizar la misma lógica con distintos códigos e intentos.

### 29. ¿Por qué puedes dividir los parámetros sin destruir las variables originales?

Porque se reciben por valor. La función trabaja con copias locales. Modificar esas copias no cambia las variables originales usadas en la partida.

### 30. ¿Cuál es el algoritmo general para revisar un número?

Extraer un dígito con `% 10`, procesarlo, cortar el número con `/ 10` y repetir mientras todavía queden dígitos.

## Preguntas de traza manual

### 31. ¿Qué devuelve `527 % 10`?

Devuelve `7`.

### 32. ¿Qué devuelve `527 / 10` usando enteros?

Devuelve `52`.

### 33. ¿Qué ocurre con `esIntentoValido(551)`?

Devuelve `false` porque el dígito `5` está repetido.

### 34. Con código `864` e intento `468`, ¿qué pistas aparecen?

```text
Bien ubicados: 1
Mal ubicados: 2
```

El `6` está bien ubicado. El `4` y el `8` existen, pero están intercambiados.

### 35. Con código `864` e intento `123`, ¿qué pistas aparecen?

```text
Bien ubicados: 0
Mal ubicados: 0
```

### 36. En la primera partida fácil, ¿cuál es el código secreto?

```text
dificultad = 1
numeroPartida = 1
selector = (1 + 1) % 5 = 2
codigoSecreto = 864
```

## Preguntas para medir comprensión real

### 37. ¿Qué pasaría si cambias `&&` por `||` en el ciclo de la partida?

La lógica sería incorrecta. El ciclo podría continuar incluso después de ganar o cuando ya no queden intentos, porque bastaría con que una sola condición fuera verdadera.

### 38. ¿Qué pasaría si eliminas `/ 10` dentro de un ciclo de dígitos?

El número no cambiaría. El ciclo revisaría siempre el mismo último dígito y podría no terminar.

### 39. ¿Qué pasaría si no restas `bienUbicados` en `contarDigitosMalUbicados`?

Los dígitos bien ubicados también serían contados como mal ubicados. Las pistas quedarían infladas.

### 40. ¿Qué parte cambiarías para añadir una dificultad extrema?

Cambiaría:

1. El menú de `pedirDificultad`.
2. La validación para aceptar `1` a `4`.
3. `obtenerCantidadIntentos` para devolver la cantidad correspondiente a la opción `4`.

## Respuesta estructurada cuando te sorprendan

Si no sabes responder inmediatamente:

1. Repite el objetivo de la función.
2. Indica qué dato entra.
3. Explica qué condición se evalúa.
4. Describe qué variable cambia.
5. Indica qué resultado sale.

Ejemplo:

> Esta función necesita saber si un dígito existe. Recibe el número y el dígito buscado. Mientras todavía quedan dígitos y no lo encontró, extrae el último con `% 10`, corta con `/ 10` y compara. Finalmente devuelve verdadero o falso.
