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
intentosUsados = 0
gano = falso

MIENTRAS quedan intentos Y no ganó
    leer código o comando

    SI el valor es negativo
        mostrar pista extra
    SINO
        consumir intento

        SI adivinó
            gano = verdadero
        SINO
            mostrar pistas automáticas
        FIN SI
    FIN SI
FIN MIENTRAS

mostrar victoria o derrota
```

## Recorrer dígitos

```text
MIENTRAS numero > 0
    digito = numero MOD 10
    numero = numero DIV 10
    procesar digito
FIN MIENTRAS
```
