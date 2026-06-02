# Banco de preguntas del profesor

## Cómo practicar

1. Leer únicamente la pregunta.
2. Responder en voz alta sin mirar.
3. Comparar con la respuesta modelo.
4. Repetir hasta responder con claridad en menos de un minuto.

## Preguntas principales

### 1. ¿Qué hace tu proyecto?

Código Secreto es un juego de consola. El jugador define cuántos intentos tendrá y debe descubrir un código oculto de tres dígitos diferentes. Durante la partida puede escribir `0` para pedir una pista.

### 2. ¿Qué temas aplicaste?

Variables, condicionales, ciclos `while`, `do while` y `for`, funciones, valores `bool`, operadores lógicos, contadores, `% 10`, `/ 10` y validación de entradas.

### 3. ¿Por qué todo está en un solo archivo?

Porque el profesor solicitó una entrega en un único `.cpp`. Mantengo el orden usando funciones pequeñas y prototipos antes de `main`.

### 4. ¿Qué es un prototipo?

Es una declaración que informa qué función existirá, qué tipo devuelve y qué parámetros recibe.

```cpp
int sumarDigitos(int numero);
```

### 5. ¿Cuál es la diferencia entre prototipo, llamada y definición?

```cpp
int sumarDigitos(int numero); // prototipo
sumarDigitos(codigoSecreto);  // llamada

int sumarDigitos(int numero) { // definición
    // lógica
}
```

- Prototipo: anuncia.
- Llamada: ejecuta.
- Definición: contiene la lógica.

### 6. ¿Por qué usaste `do while`?

Porque el menú principal debe mostrarse al menos una vez. El `do while` ejecuta primero y evalúa la condición al final.

### 7. ¿Por qué usaste `while` en la partida?

Porque no sabemos exactamente cuántos turnos serán necesarios. La partida continúa mientras queden intentos y el jugador no haya ganado.

### 8. ¿Por qué usaste `for` al comparar posiciones?

Porque siempre se comparan exactamente tres posiciones.

### 9. ¿Qué significa `% 10`?

Obtiene el residuo de dividir entre `10`, que corresponde al último dígito:

```text
527 % 10 = 7
```

### 10. ¿Qué significa `/ 10`?

La división entera elimina el último dígito:

```text
527 / 10 = 52
```

### 11. ¿Cuál es la diferencia entre `=` y `==`?

- `=` asigna.
- `==` compara.

```cpp
gano = true;
codigoOComando == 0
```

### 12. ¿Qué significa `&&`?

Significa "y". Ambas condiciones deben ser verdaderas.

```cpp
intentosUsados < cantidadIntentos && gano == false
```

### 13. ¿Qué significa `||`?

Significa "o". Basta con que una condición sea verdadera.

```cpp
cantidadIntentos < 1 || cantidadIntentos > 20
```

### 14. ¿Cómo validas un código?

La función `esCodigoValido` comprueba que tenga exactamente tres dígitos y que no repita ninguno.

### 15. ¿Cómo detectas repeticiones sin arrays?

Extraigo un dígito, corto el número y busco si ese dígito aparece en la parte restante.

### 16. ¿Cómo cuentas dígitos bien ubicados?

Comparo el último dígito del secreto con el último del intento, corto ambos números y repito tres veces.

### 17. ¿Cómo cuentas dígitos mal ubicados?

Primero cuento cuántos dígitos existen dentro del secreto. Después resto los que ya estaban bien ubicados.

### 18. ¿Por qué restas los bien ubicados?

Porque un dígito bien ubicado también existe. Sin restarlo, se contaría dos veces.

### 19. ¿Cómo cuenta pares la función `contarDigitosPares`?

Recorre cada dígito y pregunta:

```cpp
digito % 2 == 0
```

Si el residuo es cero, incrementa el contador.

### 20. ¿Cómo funciona `sumarDigitos`?

Recorre dígitos y acumula:

```cpp
suma = suma + digito;
```

### 21. ¿Por qué el usuario elige la cantidad de intentos?

Para que la experiencia sea ajustable. Un jugador nuevo puede pedir más oportunidades y otro puede elegir un reto corto.

### 22. ¿Por qué limitas la cantidad entre `1` y `20`?

Para rechazar valores inválidos como cero o negativos y evitar partidas excesivamente largas.

### 23. ¿Por qué el comando es `0`?

Porque es fácil de recordar y no puede confundirse con un código válido de tres dígitos.

### 24. ¿Pedir pistas consume intentos?

No. Solo ingresar un código válido incrementa `intentosUsados`.

### 25. ¿Qué pistas necesitan un intento previo?

Las pistas `1` y `2`, porque comparan el código secreto con `ultimoIntento`.

### 26. ¿Qué hace `ultimoIntento`?

Guarda el código válido más reciente para calcular pistas sobre posiciones.

### 27. ¿Por qué `mostrarPista` retorna `bool`?

Retorna `true` si realmente mostró una pista y `false` si no mostró información útil. Así el contador `pistasUsadas` solo aumenta cuando corresponde.

### 28. ¿Qué ocurre si pido la pista 1 antes de intentar?

El programa explica que primero se necesita un código para comparar posiciones y no incrementa `pistasUsadas`.

### 29. ¿Cómo eliges códigos secretos sin números aleatorios?

Uso:

```cpp
selector = numeroPartida % 5;
```

El residuo permite alternar cinco códigos predefinidos.

### 30. ¿Por qué no usaste una biblioteca para números aleatorios?

Para mantener la solución dentro del alcance de lógica básica y evitar bibliotecas adicionales.

### 31. ¿Cómo calculas el puntaje?

```cpp
puntaje = 1100 - intentosUsados * 100;
```

El puntaje disminuye con cada intento usado.

### 32. ¿Por qué no usas los intentos restantes en el puntaje?

Porque el jugador define cuántos intentos tendrá. Si premiara los restantes, elegir un límite alto aumentaría artificialmente el puntaje.

### 33. ¿Cómo evitas puntajes negativos?

```cpp
if (puntaje < 0) {
    puntaje = 0;
}
```

### 34. ¿Qué hace `leerEntero` si escribo texto?

Limpia el error de `cin`, descarta la entrada incorrecta y solicita otro entero.

### 35. ¿Qué diferencia hay entre código inválido e intento fallido?

- Código inválido: no cumple tres dígitos diferentes y no consume intento.
- Intento fallido: es válido, pero no coincide con el secreto y sí consume intento.

### 36. ¿Por qué puedes dividir parámetros sin destruir valores originales?

Porque se reciben por valor. Cada función trabaja con copias locales.

## Preguntas de traza

### 37. ¿Qué devuelve `527 % 10`?

`7`.

### 38. ¿Qué devuelve `527 / 10`?

`52`.

### 39. ¿Es válido `551`?

No. Repite el dígito `5`.

### 40. Con secreto `527` e intento `572`, ¿qué pistas aparecen?

```text
Bien ubicados: 1
Mal ubicados: 2
```

### 41. ¿Cuántos pares tiene `527`?

Uno: el dígito `2`.

### 42. ¿Cuánto suman los dígitos de `527`?

```text
5 + 2 + 7 = 14
```

### 43. ¿Cuál es el secreto de la primera partida?

```text
numeroPartida = 1
selector = 1 % 5 = 1
codigoSecreto = 527
```

### 44. Si ganas en dos intentos, ¿cuál es el puntaje?

```text
1100 - 2 * 100 = 900
```

## Preguntas para medir comprensión

### 45. ¿Qué ocurriría si eliminas `/ 10` dentro de un ciclo de dígitos?

El número no cambiaría. El ciclo revisaría siempre el mismo último dígito y podría no terminar.

### 46. ¿Qué ocurriría si las pistas consumieran intentos?

Habría que incrementar `intentosUsados` dentro del bloque donde `codigoOComando == 0`.

### 47. ¿Qué cambiarías para aceptar hasta 30 intentos?

Modificaría el mensaje y la condición de `pedirCantidadIntentos`:

```cpp
cantidadIntentos > 30
```

### 48. ¿Qué cambiarías para contar impares?

Usaría el mismo recorrido que `contarDigitosPares`, pero cambiaría la condición:

```cpp
digito % 2 != 0
```

## Estructura para responder una sorpresa

1. Objetivo de la función.
2. Datos que recibe.
3. Condición.
4. Variables que cambian.
5. Resultado.
6. Ejemplo.
