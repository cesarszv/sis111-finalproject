# Pseudocódigo

## Programa principal

```text
HACER
    mostrar menú
    leer opción

    SI opción == 1
        jugar
    SINO SI opción == 2
        mostrar instrucciones
    FIN SI
MIENTRAS opción != 3
```

## Partida

```text
pedir cantidad de intentos
elegir código secreto
mostrar ayuda inicial gratis
intentosUsados = 0
revelacionesUsadas = 0
pistasPedidas = 0
gano = falso

MIENTRAS quedan intentos Y no ganó Y no se rindió
    mostrar menú de turno
    leer opción

    SI opción == intentar
        leer código
        consumir intento

        SI adivinó
            resolver desafío final
        SINO
            mostrar lugares exactos y dígitos en otro lugar
        FIN SI
    SINO SI opción == revelar
        mostrar dígito con posición
    SINO SI opción == pista
        mostrar pista indirecta
    SINO
        rendirse
    FIN SI
FIN MIENTRAS

calcular puntaje
mostrar resultado
```

## Desafío final

```text
claveFinal = intercalar pares e impares de mayor a menor
errores = 0
completo = falso

MIENTRAS errores < 2 Y no completo
    leer intento final

    SI intento final == claveFinal
        completo = verdadero
    SINO
        errores = errores + 1
    FIN SI
FIN MIENTRAS
```

## Recorrer dígitos

```text
MIENTRAS numero > 0
    digito = numero MOD 10
    numero = numero DIV 10
    procesar digito
FIN MIENTRAS
```
