# Guion para explicar el proyecto

## Versión corta de 30 segundos

> Mi proyecto se llama Código Secreto. Es un juego de consola en C++ donde el jugador debe adivinar un código oculto de tres dígitos diferentes. Después de cada intento incorrecto, el programa muestra cuántos dígitos están bien ubicados y cuántos existen, pero están en otra posición. Incluí tres dificultades, validación de entradas y un puntaje. Lo desarrollé con funciones, condicionales y bucles, sin arrays ni bibliotecas adicionales.

## Versión recomendada de 2 minutos

> Mi proyecto se llama Código Secreto. El objetivo es descubrir un número oculto de tres dígitos diferentes antes de quedarse sin intentos.
>
> Primero, el programa muestra un menú con tres opciones: jugar, ver instrucciones o salir. Si el usuario elige jugar, selecciona una dificultad. La dificultad define si tiene diez, siete o cinco intentos.
>
> Durante la partida, el jugador ingresa un código. El programa valida que tenga tres dígitos y que no repita ninguno. Si el intento no coincide con el código secreto, se muestran dos pistas: dígitos correctos y bien ubicados, y dígitos correctos pero mal ubicados.
>
> Para revisar los dígitos sin usar arrays, aproveché operaciones matemáticas vistas en clase. Con `% 10` extraigo el último dígito y con `/ 10` elimino ese dígito para continuar con el siguiente. Usé un ciclo `for` porque sé que debo comparar exactamente tres posiciones.
>
> Organicé todo en un solo archivo fuente, como pidió el profesor. Antes de `main` declaré los prototipos y después de `main` definí cada función. Esto permite leer primero el flujo principal y luego revisar los detalles.

## Versión completa de 4 minutos

### 1. Problema

> Quería crear un juego pequeño que aplicara los temas vistos en Introducción a la Programación. Elegí un juego de deducción porque permite usar condicionales, bucles, funciones y manipulación de dígitos.

### 2. Flujo principal

> El programa comienza en `main`. Uso un ciclo `do while` porque el menú debe mostrarse al menos una vez. El ciclo se repite mientras la opción sea diferente de `3`, que corresponde a salir.

### 3. Partida

> Cuando el usuario elige jugar, llamo a la función `jugar`. Esa función pide la dificultad, obtiene la cantidad máxima de intentos, selecciona un código secreto predefinido y repite los intentos mientras todavía queden oportunidades y el jugador no haya ganado.

### 4. Validación

> Antes de comparar un intento, verifico que tenga exactamente tres dígitos y que no repita ninguno. Esto evita resultados ambiguos al calcular pistas.

### 5. Pistas

> Para calcular los dígitos bien ubicados, comparo las tres posiciones. Para calcular los mal ubicados, cuento cuántos dígitos del intento existen dentro del código secreto y resto los que ya estaban bien ubicados.

### 6. Herramientas usadas

> No usé arrays, clases ni bibliotecas adicionales. La lógica se basa en `if`, `while`, `do while`, `for`, `% 10`, `/ 10` y funciones.

### 7. Cierre

> El resultado es un juego funcional, fácil de probar y alineado con los contenidos vistos en clase.

## Orden recomendado para una demo

1. Mostrar brevemente la lista de prototipos.
2. Señalar `main`.
3. Compilar.
4. Ejecutar el juego.
5. Elegir dificultad fácil.
6. Ingresar `468` para mostrar pistas.
7. Ingresar `864` para ganar la primera partida fácil.
8. Mostrar el puntaje.

## Frases útiles si necesitas pensar

- "Primero voy a explicar qué condición controla este ciclo."
- "Esta variable guarda una copia para no perder el valor original."
- "Uso `% 10` porque necesito obtener el último dígito."
- "Uso `/ 10` porque después de revisar ese dígito debo eliminarlo."
- "Elegí `for` porque la cantidad de repeticiones es exactamente tres."
- "Elegí `while` porque la cantidad de repeticiones depende de una condición."

## Frases que debes evitar

- "Lo hice así porque funcionó."
- "No sé, lo generó la computadora."
- "Memoricé esta parte."
- "Creo que hace eso."

Si no recuerdas un detalle, vuelve al problema:

> Necesito revisar tres dígitos. Extraigo uno, lo proceso, lo elimino y repito.
