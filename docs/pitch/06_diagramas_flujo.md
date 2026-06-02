# Diagramas de flujo

## 1. Flujo principal

```mermaid
flowchart TD
    A([Inicio]) --> B[opcion = 0<br/>numeroPartida = 1]
    B --> C[Mostrar menú]
    C --> D[/Leer opción/]
    D --> E{¿opcion == 1?}
    E -- Sí --> F[Jugar partida]
    F --> G[numeroPartida = numeroPartida + 1]
    G --> H{¿opcion != 3?}
    E -- No --> I{¿opcion == 2?}
    I -- Sí --> J[Mostrar instrucciones]
    J --> H
    I -- No --> H
    H -- Sí --> C
    H -- No --> K[/Mostrar despedida/]
    K --> L([Fin])
```

## 2. Configurar e iniciar partida

```mermaid
flowchart TD
    A([Inicio de partida]) --> B[/Leer cantidad de intentos/]
    B --> C{¿Está entre 1 y 20?}
    C -- No --> B
    C -- Sí --> D[Elegir código secreto]
    D --> E[intentosUsados = 0<br/>pistasUsadas = 0<br/>ultimoIntento = 0<br/>gano = false]
    E --> F[Comenzar turnos]
```

## 3. Turno de juego

```mermaid
flowchart TD
    A{¿Quedan intentos<br/>y todavía no ganó?} -- No --> B[Mostrar resultado final]
    A -- Sí --> C[Mostrar estado]
    C --> D[/Leer código o comando 0/]
    D --> E{¿Escribió 0?}
    E -- Sí --> F[/Elegir tipo de pista/]
    F --> G[Mostrar pista si corresponde]
    G --> A
    E -- No --> H[Guardar intento<br/>Incrementar intentos usados]
    H --> I{¿Adivinó?}
    I -- Sí --> J[gano = true]
    I -- No --> K[Invitar a continuar]
    J --> A
    K --> A
```

## 4. Validar código o comando

```mermaid
flowchart TD
    A([Inicio]) --> B[/Leer número/]
    B --> C{¿numero == 0?}
    C -- Sí --> D[/Retornar comando 0/]
    C -- No --> E{¿Tiene 3 dígitos?}
    E -- No --> F[Mostrar error específico]
    E -- Sí --> G{¿Tiene dígitos repetidos?}
    G -- Sí --> F
    G -- No --> H[/Retornar código válido/]
    F --> B
    D --> I([Fin])
    H --> I
```

## 5. Recorrer dígitos

```mermaid
flowchart TD
    A([Inicio]) --> B{¿numero > 0?}
    B -- Sí --> C[digito = numero % 10]
    C --> D[numero = numero / 10]
    D --> E[Procesar dígito]
    E --> B
    B -- No --> F([Fin])
```

## 6. Solicitar pista

```mermaid
flowchart TD
    A([Inicio]) --> B[/Mostrar menú de pistas/]
    B --> C[/Leer opción entre 1 y 6/]
    C --> D{¿Qué pista eligió?}
    D -- 1 --> E[Mostrar bien ubicados<br/>si existe último intento]
    D -- 2 --> F[Mostrar mal ubicados<br/>si existe último intento]
    D -- 3 --> G[Mostrar cantidad de pares]
    D -- 4 --> H[Mostrar suma de dígitos]
    D -- 5 --> I[Mostrar comparación con 500]
    D -- 6 --> J[Regresar sin pista]
    E --> K([Fin])
    F --> K
    G --> K
    H --> K
    I --> K
    J --> K
```

## 7. Cómo explicar un diagrama

1. Identificar el dato de entrada.
2. Explicar qué variable se inicializa.
3. Leer cada pregunta como verdadero o falso.
4. Indicar qué cambia en cada vuelta.
5. Explicar cuándo termina.
