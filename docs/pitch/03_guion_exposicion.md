# Guion para explicar el proyecto

## Versión corta

> Mi proyecto se llama Código Secreto. El jugador debe descubrir un número oculto de tres dígitos diferentes. Después de cada intento incorrecto recibe pistas automáticas sobre dígitos bien ubicados y dígitos correctos en otra posición. También puede pedir ayuda extra con comandos negativos. Usé funciones, condicionales y ciclos, sin arrays ni bibliotecas adicionales.

## Demo recomendada

1. Elegir `7` intentos.
2. Ingresar `572`.
3. Explicar las pistas automáticas: `1` bien ubicado y `2` mal ubicados.
4. Escribir `-1` para mostrar la suma.
5. Ingresar `527` para ganar.

## Explicación técnica breve

> Para recorrer un número uso `% 10` para extraer el último dígito y `/ 10` para eliminarlo. Uso `for` cuando comparo tres posiciones exactas y `while` cuando repito según una condición. Los comandos negativos no consumen intentos porque no son respuestas del jugador.
