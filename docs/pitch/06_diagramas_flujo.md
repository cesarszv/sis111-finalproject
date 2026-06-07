# Diagramas de flujo

## Partida

```mermaid
flowchart TD
    A([Inicio]) --> B[/Elegir intentos/]
    B --> C[Elegir código secreto]
    C --> D[Mostrar ayuda inicial]
    D --> E{¿Quedan intentos<br/>y sigue jugando?}
    E -- No --> M[Mostrar resultado y puntaje]
    E -- Sí --> F[/Elegir acción/]
    F --> G{¿Acción?}
    G -- Intentar --> H[/Leer código/]
    H --> I{¿Adivinó?}
    I -- Sí --> J[Desafío final]
    I -- No --> K[Mostrar respuesta simple]
    G -- Revelar --> L[Mostrar dígito y posición]
    G -- Pista --> N[Mostrar pista indirecta]
    G -- Rendirse --> M
    J --> M
    K --> E
    L --> E
    N --> E
    M --> O([Fin])
```

## Recorrer dígitos

```mermaid
flowchart TD
    A([Inicio]) --> B{¿numero > 0?}
    B -- Sí --> C[digito = numero % 10]
    C --> D[numero = numero / 10]
    D --> E[Procesar dígito]
    E --> B
    B -- No --> F([Fin])
```
