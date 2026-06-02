# Guion para explicar el proyecto

## Versión de 30 segundos

> Mi proyecto se llama Código Secreto. Es un juego de consola en C++ donde el jugador debe adivinar un código oculto de tres dígitos diferentes. El jugador define cuántos intentos quiere tener y puede escribir `0` durante la partida para elegir una pista. Lo desarrollé con funciones, condicionales y bucles, sin arrays ni bibliotecas adicionales.

## Versión recomendada de 2 minutos

> Mi proyecto se llama Código Secreto. El objetivo es descubrir un número oculto de tres dígitos diferentes antes de quedarse sin intentos.
>
> Primero, el programa muestra un menú con tres opciones: jugar, ver instrucciones o salir. Al iniciar una partida, el jugador elige cuántos intentos desea tener, entre uno y veinte.
>
> Durante cada turno puede ingresar un código o escribir `0`. El cero funciona como un comando para abrir el menú de pistas. Allí puede pedir información sobre su último intento o sobre el código secreto. Pedir una pista no consume intentos.
>
> Para revisar dígitos sin usar arrays, utilizo `% 10` para extraer el último dígito y `/ 10` para eliminarlo. Uso `for` cuando sé que debo comparar exactamente tres posiciones y `while` cuando la repetición depende de una condición.
>
> Todo está en un solo archivo fuente. Antes de `main` declaré prototipos y después definí cada función para que el flujo principal se pueda leer primero.

## Orden recomendado para la demo

1. Mostrar brevemente los prototipos agrupados.
2. Señalar `main`.
3. Compilar.
4. Ejecutar.
5. Elegir `7` intentos.
6. Ingresar `572`.
7. Escribir `0` y pedir las pistas `1` y `2`.
8. Ingresar `527` para ganar la primera partida.

## Guion durante la demo

> En la primera partida el código secreto es `527`. Voy a ingresar `572`. Los tres dígitos existen, pero solo el `5` está bien ubicado. Ahora escribo `0` para demostrar que el usuario puede elegir la pista que necesita. Finalmente ingreso `527` para mostrar la victoria y el puntaje.

## Frases útiles

- "Esta función tiene una responsabilidad concreta."
- "Uso `% 10` para extraer el último dígito."
- "Uso `/ 10` para eliminar el dígito ya procesado."
- "El comando `0` no se confunde con un código válido de tres dígitos."
- "Pedir una pista no consume intentos."
- "El puntaje depende de intentos usados, no de intentos elegidos."
