# Pseudocódigo del proyecto

## 1. Programa principal

```text
INICIO
    opcion = 0
    numeroPartida = 1

    HACER
        mostrar menú principal
        leer opción válida

        SI opcion == 1 ENTONCES
            jugar(numeroPartida)
            numeroPartida = numeroPartida + 1
        SINO SI opcion == 2 ENTONCES
            mostrar instrucciones
        FIN SI
    MIENTRAS opcion != 3

    mostrar despedida
FIN
```

## 2. Validar un código

```text
FUNCIÓN esCodigoValido(numero)
    RETORNAR tieneTresDigitos(numero)
             Y NO tieneDigitosRepetidos(numero)
FIN FUNCIÓN
```

## 3. Buscar un dígito

```text
FUNCIÓN existeDigito(numero, digitoBuscado)
    encontrado = falso

    MIENTRAS numero > 0 Y encontrado == falso
        digito = numero MOD 10
        numero = numero DIV 10

        SI digito == digitoBuscado ENTONCES
            encontrado = verdadero
        FIN SI
    FIN MIENTRAS

    RETORNAR encontrado
FIN FUNCIÓN
```

## 4. Detectar dígitos repetidos

```text
FUNCIÓN tieneDigitosRepetidos(numero)
    tieneRepetidos = falso

    MIENTRAS numero > 0 Y tieneRepetidos == falso
        digito = numero MOD 10
        numero = numero DIV 10

        SI existeDigito(numero, digito) ENTONCES
            tieneRepetidos = verdadero
        FIN SI
    FIN MIENTRAS

    RETORNAR tieneRepetidos
FIN FUNCIÓN
```

## 5. Contar dígitos bien ubicados

```text
FUNCIÓN contarDigitosBienUbicados(codigoSecreto, intento)
    bienUbicados = 0

    PARA posicion = 1 HASTA 3
        digitoSecreto = codigoSecreto MOD 10
        digitoIntento = intento MOD 10

        SI digitoSecreto == digitoIntento ENTONCES
            bienUbicados = bienUbicados + 1
        FIN SI

        codigoSecreto = codigoSecreto DIV 10
        intento = intento DIV 10
    FIN PARA

    RETORNAR bienUbicados
FIN FUNCIÓN
```

## 6. Contar dígitos mal ubicados

```text
FUNCIÓN contarDigitosMalUbicados(codigoSecreto, intento)
    existentes = 0
    bienUbicados = contarDigitosBienUbicados(codigoSecreto, intento)

    PARA posicion = 1 HASTA 3
        digito = intento MOD 10

        SI existeDigito(codigoSecreto, digito) ENTONCES
            existentes = existentes + 1
        FIN SI

        intento = intento DIV 10
    FIN PARA

    RETORNAR existentes - bienUbicados
FIN FUNCIÓN
```

## 7. Contar pares

```text
FUNCIÓN contarDigitosPares(numero)
    cantidadPares = 0

    MIENTRAS numero > 0
        digito = numero MOD 10
        numero = numero DIV 10

        SI digito MOD 2 == 0 ENTONCES
            cantidadPares = cantidadPares + 1
        FIN SI
    FIN MIENTRAS

    RETORNAR cantidadPares
FIN FUNCIÓN
```

## 8. Sumar dígitos

```text
FUNCIÓN sumarDigitos(numero)
    suma = 0

    MIENTRAS numero > 0
        digito = numero MOD 10
        numero = numero DIV 10
        suma = suma + digito
    FIN MIENTRAS

    RETORNAR suma
FIN FUNCIÓN
```

## 9. Mostrar pista

```text
FUNCIÓN mostrarPista(tipoPista, codigoSecreto, ultimoIntento)
    pistaMostrada = verdadero

    SI tipoPista == 1 ENTONCES
        mostrar bien ubicados del último intento
    SINO SI tipoPista == 2 ENTONCES
        mostrar mal ubicados del último intento
    SINO SI tipoPista == 3 ENTONCES
        mostrar cantidad de pares del código secreto
    SINO SI tipoPista == 4 ENTONCES
        mostrar suma de dígitos del código secreto
    SINO SI tipoPista == 5 ENTONCES
        mostrar si el código es mayor o menor que 500
    SINO
        regresar sin mostrar pista
        pistaMostrada = falso
    FIN SI

    RETORNAR pistaMostrada
FIN FUNCIÓN
```

Las opciones `1` y `2` verifican primero que exista un intento previo.

## 10. Jugar

```text
PROCEDIMIENTO jugar(numeroPartida)
    cantidadIntentos = pedir cantidad
    codigoSecreto = elegir código
    intentosUsados = 0
    pistasUsadas = 0
    ultimoIntento = 0
    gano = falso

    MIENTRAS intentosUsados < cantidadIntentos Y gano == falso
        mostrar estado
        codigoOComando = pedir código o comando

        SI codigoOComando == 0 ENTONCES
            tipoPista = pedir tipo

            SI mostrarPista(...) == verdadero ENTONCES
                pistasUsadas = pistasUsadas + 1
            FIN SI
        SINO
            ultimoIntento = codigoOComando
            intentosUsados = intentosUsados + 1

            SI ultimoIntento == codigoSecreto ENTONCES
                gano = verdadero
            SINO
                mostrar mensaje para continuar
            FIN SI
        FIN SI
    FIN MIENTRAS

    mostrar resultado final
FIN PROCEDIMIENTO
```
