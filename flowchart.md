# Flowchart de `codigo.cpp`

Este archivo explica el flujo del programa con diagramas Mermaid.

La idea principal es esta:

1. El `main` muestra el menu principal.
2. Si el jugador elige jugar, entra a `jugar`.
3. En cada turno puede probar un codigo, pedir ayuda o rendirse.
4. Si descubre el codigo secreto, pasa al desafio final.
5. Al terminar, el programa muestra resultado y puntaje.

## 1. Vista general

```mermaid
flowchart TD
    A["Inicio del programa"] --> B["main"]
    B --> C{"Menu principal"}

    C -->|1. jugar| D["jugar"]
    C -->|2. ver reglas| E["mostrarReglas"]
    C -->|3. salir| F["Mensaje final"]
    C -->|opcion invalida| C

    E --> C
    D --> C
    F --> G["Fin"]
```

## 2. Menu principal

```mermaid
flowchart TD
    A["Inicio"] --> B["opcion = 0"]
    B --> C{"opcion != 3<br/>y no hay fin de archivo?"}

    C -->|si| D["Mostrar menu principal"]
    D --> E["Leer opcion con leerEntero"]

    E --> F{"La lectura fue correcta?"}
    F -->|no| C
    F -->|si| G{"Que opcion eligio?"}

    G -->|1| H["jugar"]
    H --> C

    G -->|2| I["mostrarReglas"]
    I --> C

    G -->|3| C

    G -->|otro numero| J["Mostrar opcion invalida"]
    J --> C

    C -->|no| K["Mostrar gracias por jugar"]
    K --> L["Fin"]
```

## 3. Partida completa

```mermaid
flowchart TD
    A["Inicio de jugar"] --> B["Crear valores iniciales"]
    B --> C["codigoSecreto = 58274<br/>intentosMaximos = 10<br/>revelacionesMaximas = 2<br/>pistasMaximas = 3"]
    C --> D["Contadores en 0<br/>encontroCodigo = false<br/>gano = false<br/>rendirse = false"]
    D --> E["Mostrar nueva partida<br/>dato gratis: posicion 3 = 2"]

    E --> F{"Puede seguir el turno?<br/>intentos usados menor que 10<br/>no encontro codigo<br/>no se rindio<br/>no hay fin de archivo"}

    F -->|si| G["Mostrar estado del turno"]
    G --> H["Leer opcion del turno"]
    H --> I{"Lectura correcta?"}

    I -->|no| F
    I -->|si| J{"Opcion del turno"}

    J -->|1. probar codigo| K["Flujo de intento"]
    K --> F

    J -->|2. revelar dato exacto| L["Flujo de revelacion"]
    L --> F

    J -->|3. pedir pista suave| M["Flujo de pista"]
    M --> F

    J -->|4. rendirme| N["rendirse = true"]
    N --> F

    J -->|otro numero| O["Mostrar opcion invalida"]
    O --> F

    F -->|no| P{"encontroCodigo == true?"}
    P -->|si| Q["Desafio final"]
    P -->|no| R["Resultado final"]
    Q --> R
    R --> S["Calcular y mostrar puntaje"]
    S --> T["Fin de jugar"]
```

## 4. Probar codigo

```mermaid
flowchart TD
    A["Jugador elige probar codigo"] --> B["Leer intento con leerEntero"]
    B --> C{"Lectura correcta?"}

    C -->|no| Z["Volver al menu del turno"]
    C -->|si| D{"intentoEsValido?"}

    D -->|no| E["Mostrar: codigo invalido"]
    E --> F["No cuenta como intento"]
    F --> Z

    D -->|si| G["intentosUsados++"]
    G --> H{"intento == codigoSecreto?"}

    H -->|si| I["encontroCodigo = true"]
    I --> Z

    H -->|no| J["contarLugaresExactos"]
    J --> K["contarCorrectosEnOtroLugar"]
    K --> L["Mostrar respuesta al jugador"]
    L --> Z
```

## 5. Validar intento

```mermaid
flowchart TD
    A["intentoEsValido"] --> B{"Tiene 5 digitos?"}

    B -->|no| C["valido = false"]
    B -->|si| D{"Tiene digitos diferentes?"}

    D -->|no| C
    D -->|si| E["valido = true"]

    C --> F["Devolver valido"]
    E --> F
```

## 6. Contar respuesta del intento

```mermaid
flowchart TD
    A["Comparar intento con codigo secreto"] --> B["Recorrer posiciones 1 a 5"]

    B --> C["Obtener digito del codigo<br/>y digito del intento"]
    C --> D{"Son iguales<br/>en la misma posicion?"}

    D -->|si| E["Sumar 1 a exactos"]
    D -->|no| F["No sumar a exactos"]

    E --> G{"Quedan posiciones?"}
    F --> G

    G -->|si| B
    G -->|no| H["exactos = lugares correctos"]

    H --> I["Para otro lugar:<br/>contar digitos del intento<br/>que existen en el codigo"]
    I --> J["correctosEnOtroLugar = existentes - exactos"]
```

## 7. Ayudas de la partida

```mermaid
flowchart TD
    A{"Jugador pide ayuda"} --> B{"Tipo de ayuda"}

    B -->|revelacion exacta| C{"revelacionesUsadas"}
    C -->|0| D["Mostrar posicion 1"]
    D --> E["revelacionesUsadas++"]
    C -->|1| F["Mostrar posicion 5"]
    F --> E
    C -->|2 o mas| G["Mostrar que ya no hay revelaciones"]

    B -->|pista suave| H{"pistasUsadas"}
    H -->|0| I["Mostrar suma de digitos"]
    I --> J["pistasUsadas++"]
    H -->|1| K["Mostrar cantidad de pares e impares"]
    K --> J
    H -->|2| L["Mostrar que el codigo es mayor que 50000"]
    L --> J
    H -->|3 o mas| M["Mostrar que ya no hay pistas"]

    E --> N["Volver al turno"]
    G --> N
    J --> N
    M --> N
```

## 8. Desafio final

El desafio final solo aparece si el jugador ya encontro el codigo secreto.

```mermaid
flowchart TD
    A["encontroCodigo == true"] --> B["calcularClaveFinal"]
    B --> C["claveFinal para 58274 = 87452"]
    C --> D["erroresDesafio = 0"]
    D --> E{"erroresDesafio menor que 2<br/>y gano == false<br/>y no hay fin de archivo?"}

    E -->|si| F["Leer intentoFinal"]
    F --> G{"Lectura correcta?"}
    G -->|no| E
    G -->|si| H{"intentoFinal == claveFinal?"}

    H -->|si| I["gano = true"]
    I --> J["Salir del desafio"]

    H -->|no| K["erroresDesafio++"]
    K --> L{"Quedan oportunidades?"}
    L -->|si| M["Mostrar intenta una vez mas"]
    M --> E
    L -->|no| N["Mostrar clave final correcta"]
    N --> J

    E -->|no| J
```

## 9. Calcular clave final

La clave final se arma alternando:

1. Mayor digito par disponible.
2. Mayor digito impar disponible.
3. Siguiente par disponible.
4. Siguiente impar disponible.

Para el codigo `58274`, la clave queda `87452`.

```mermaid
flowchart TD
    A["calcularClaveFinal"] --> B["claveFinal = 0<br/>parBuscado = 8<br/>imparBuscado = 9"]

    B --> C{"parBuscado >= 0<br/>o imparBuscado >= 1?"}

    C -->|si| D["Buscar el par mas grande<br/>que exista en el codigo"]
    D --> E{"Existe par disponible?"}
    E -->|si| F["Agregar par a claveFinal<br/>bajar parBuscado en 2"]
    E -->|no| G["No agregar par"]

    F --> H["Buscar el impar mas grande<br/>que exista en el codigo"]
    G --> H

    H --> I{"Existe impar disponible?"}
    I -->|si| J["Agregar impar a claveFinal<br/>bajar imparBuscado en 2"]
    I -->|no| K["No agregar impar"]

    J --> C
    K --> C

    C -->|no| L["Devolver claveFinal"]
```

## 10. Resultado y puntaje

```mermaid
flowchart TD
    A["Termina la partida"] --> B{"gano == true?"}

    B -->|si| C["Mostrar: ganaste el juego completo"]
    B -->|no| D{"encontroCodigo == true?"}

    D -->|si| E["Mostrar: encontraste el codigo<br/>pero fallaste el desafio"]
    D -->|no| F{"rendirse == true?"}

    F -->|si| G["Mostrar: te rendiste"]
    F -->|no| H["Mostrar: se acabaron los intentos"]

    C --> I["Mostrar contadores"]
    E --> I
    G --> I
    H --> I

    I --> J["calcularPuntaje"]
    J --> K{"gano == false?"}

    K -->|si| L["puntaje = 0"]
    K -->|no| M["puntaje = 100<br/>- intentosUsados * 4<br/>- revelacionesUsadas * 12<br/>- pistasUsadas * 8<br/>- erroresDesafio * 10"]

    M --> N{"puntaje menor que 0?"}
    N -->|si| O["puntaje = 0"]
    N -->|no| P["Mantener puntaje"]

    L --> Q["Mostrar puntaje de 100"]
    O --> Q
    P --> Q
```

## 11. Relacion entre funciones

```mermaid
flowchart TD
    main["main"] --> mostrarReglas["mostrarReglas"]
    main --> jugar["jugar"]
    main --> leerEntero["leerEntero"]

    jugar --> leerEntero
    jugar --> intentoEsValido["intentoEsValido"]
    jugar --> contarLugaresExactos["contarLugaresExactos"]
    jugar --> contarCorrectosEnOtroLugar["contarCorrectosEnOtroLugar"]
    jugar --> obtenerDigitoEnPosicion["obtenerDigitoEnPosicion"]
    jugar --> sumarDigitos["sumarDigitos"]
    jugar --> contarPares["contarPares"]
    jugar --> calcularClaveFinal["calcularClaveFinal"]
    jugar --> calcularPuntaje["calcularPuntaje"]

    intentoEsValido --> tieneCincoDigitos["tieneCincoDigitos"]
    intentoEsValido --> tieneDigitosDiferentes["tieneDigitosDiferentes"]

    tieneDigitosDiferentes --> obtenerDigitoEnPosicion
    contarLugaresExactos --> obtenerDigitoEnPosicion
    contarCorrectosEnOtroLugar --> contarLugaresExactos
    contarCorrectosEnOtroLugar --> obtenerDigitoEnPosicion
    contarCorrectosEnOtroLugar --> existeDigito["existeDigito"]
    calcularClaveFinal --> existeDigito
```
