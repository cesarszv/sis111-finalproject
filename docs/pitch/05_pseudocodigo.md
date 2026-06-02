# Pseudocódigo del proyecto

## 1. Qué es pseudocódigo

El pseudocódigo describe la lógica con palabras y estructuras simples. No depende exactamente de la sintaxis de C++.

Sirve para demostrar que entiendes el algoritmo antes de programarlo.

## 2. Programa principal

```text
INICIO
    opcion = 0
    numeroPartida = 1

    HACER
        mostrar menú
        leer opcion

        SI opcion == 1 ENTONCES
            jugar una partida usando numeroPartida
            numeroPartida = numeroPartida + 1
        SINO SI opcion == 2 ENTONCES
            mostrar instrucciones
        FIN SI
    MIENTRAS opcion != 3
FIN
```

## 3. Validar un intento

```text
FUNCIÓN esIntentoValido(numero)
    SI numero está entre 100 y 999
       Y numero no tiene dígitos repetidos ENTONCES
        RETORNAR verdadero
    SINO
        RETORNAR falso
    FIN SI
FIN FUNCIÓN
```

## 4. Verificar si un dígito existe

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

## 5. Detectar dígitos repetidos

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

## 6. Contar dígitos bien ubicados

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

## 7. Contar dígitos mal ubicados

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

## 8. Jugar una partida

```text
PROCEDIMIENTO jugar(numeroPartida)
    dificultad = pedir dificultad
    cantidadIntentos = obtener cantidad de intentos según dificultad
    codigoSecreto = elegir código secreto
    intentosUsados = 0
    gano = falso

    MIENTRAS intentosUsados < cantidadIntentos Y gano == falso
        intento = pedir un intento válido
        intentosUsados = intentosUsados + 1

        SI intento == codigoSecreto ENTONCES
            gano = verdadero
        SINO
            bienUbicados = contar dígitos bien ubicados
            malUbicados = contar dígitos mal ubicados
            mostrar ambas pistas
        FIN SI
    FIN MIENTRAS

    SI gano == verdadero ENTONCES
        intentosRestantes = cantidadIntentos - intentosUsados
        puntaje = calcular puntaje
        mostrar victoria y puntaje
    SINO
        mostrar derrota y código secreto
    FIN SI
FIN PROCEDIMIENTO
```

## 9. Traza manual completa

Primera partida en dificultad fácil:

```text
dificultad = 1
numeroPartida = 1
selector = (1 + 1) MOD 5
selector = 2
codigoSecreto = 864
```

Intento del jugador:

```text
intento = 468
```

Comparación:

| Revisión | Dígito secreto | Dígito intento | Bien ubicado | Existe en secreto |
| :--- | ---: | ---: | :--- | :--- |
| Unidades | `4` | `8` | No | Sí |
| Decenas | `6` | `6` | Sí | Sí |
| Centenas | `8` | `4` | No | Sí |

Resultado:

```text
bienUbicados = 1
existentes = 3
malUbicados = existentes - bienUbicados
malUbicados = 3 - 1
malUbicados = 2
```
