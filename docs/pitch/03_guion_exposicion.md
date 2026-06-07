# Guion para explicar el proyecto

## Versión corta

> Mi proyecto se llama Código Secreto. El jugador debe descubrir un código oculto de cinco dígitos diferentes. Al inicio recibe una ayuda gratis, y durante la partida puede decidir si intenta, revela un dígito, pide una pista o se rinde. Las ayudas hacen el juego más fácil, pero bajan el puntaje final. Cuando descubre el código, todavía debe resolver un desafío final. Usé funciones, condicionales y ciclos, sin arrays ni bibliotecas adicionales.

## Demo recomendada

1. Elegir `10` intentos.
2. Mostrar la ayuda inicial: posición `3`, dígito `2`.
3. Elegir `1. Intentar código`.
4. Ingresar `58274`.
5. Explicar el desafío final.
6. Ingresar `87452`.
7. Mostrar el puntaje final.

## Explicación técnica breve

> Para recorrer un número uso `% 10` para extraer el último dígito y `/ 10` para eliminarlo. Uso `for` cuando comparo cinco posiciones exactas y `while` cuando repito según una condición. El puntaje se calcula restando por intentos, ayudas y errores. El desafío final se calcula buscando pares e impares de mayor a menor.
