# Diagramas de flujo

## 1. Simbología usada

| Forma | Uso |
| :--- | :--- |
| Óvalo | Inicio o fin. |
| Paralelogramo | Entrada o salida de datos. |
| Rectángulo | Proceso o asignación. |
| Rombo | Pregunta con resultado verdadero o falso. |

## 2. Flujo general del juego

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
    H -- No --> K([Fin])
```

## 3. Flujo de una partida

```mermaid
flowchart TD
    A([Inicio de partida]) --> B[/Elegir dificultad/]
    B --> C[Definir intentos máximos]
    C --> D[Elegir código secreto]
    D --> E[intentosUsados = 0<br/>gano = false]
    E --> F{¿Quedan intentos<br/>y todavía no ganó?}
    F -- Sí --> G[/Pedir intento válido/]
    G --> H[intentosUsados = intentosUsados + 1]
    H --> I{¿intento == codigoSecreto?}
    I -- Sí --> J[gano = true]
    J --> F
    I -- No --> K[Calcular pistas]
    K --> L[/Mostrar pistas/]
    L --> F
    F -- No --> M{¿gano == true?}
    M -- Sí --> N[Calcular puntaje]
    N --> O[/Mostrar victoria y puntaje/]
    M -- No --> P[/Mostrar derrota y código secreto/]
    O --> Q([Fin de partida])
    P --> Q
```

## 4. Validar un intento

```mermaid
flowchart TD
    A([Inicio]) --> B[/Recibir número/]
    B --> C{¿Tiene tres dígitos?}
    C -- No --> D[Intento inválido]
    C -- Sí --> E{¿Tiene dígitos repetidos?}
    E -- Sí --> D
    E -- No --> F[Intento válido]
    D --> G([Fin])
    F --> G
```

## 5. Buscar un dígito dentro de un número

```mermaid
flowchart TD
    A([Inicio]) --> B[encontrado = false]
    B --> C{¿numero > 0<br/>y encontrado == false?}
    C -- Sí --> D[digito = numero % 10]
    D --> E[numero = numero / 10]
    E --> F{¿digito == digitoBuscado?}
    F -- Sí --> G[encontrado = true]
    F -- No --> C
    G --> C
    C -- No --> H[/Retornar encontrado/]
    H --> I([Fin])
```

## 6. Detectar dígitos repetidos

```mermaid
flowchart TD
    A([Inicio]) --> B[tieneRepetidos = false]
    B --> C{¿numero > 0<br/>y tieneRepetidos == false?}
    C -- Sí --> D[digito = numero % 10]
    D --> E[numero = numero / 10]
    E --> F{¿digito existe<br/>en la parte restante?}
    F -- Sí --> G[tieneRepetidos = true]
    F -- No --> C
    G --> C
    C -- No --> H[/Retornar tieneRepetidos/]
    H --> I([Fin])
```

## 7. Contar dígitos bien ubicados

```mermaid
flowchart TD
    A([Inicio]) --> B[bienUbicados = 0]
    B --> C{¿Se revisaron<br/>las 3 posiciones?}
    C -- No --> D[Extraer último dígito<br/>del secreto y del intento]
    D --> E{¿Los dígitos son iguales?}
    E -- Sí --> F[bienUbicados = bienUbicados + 1]
    E -- No --> G[Continuar]
    F --> H[Eliminar último dígito<br/>de ambos números]
    G --> H
    H --> C
    C -- Sí --> I[/Retornar bienUbicados/]
    I --> J([Fin])
```

## 8. Contar dígitos mal ubicados

```mermaid
flowchart TD
    A([Inicio]) --> B[existentes = 0]
    B --> C[Calcular bienUbicados]
    C --> D{¿Se revisaron<br/>las 3 posiciones?}
    D -- No --> E[Extraer un dígito<br/>del intento]
    E --> F{¿El dígito existe<br/>en el código secreto?}
    F -- Sí --> G[existentes = existentes + 1]
    F -- No --> H[Continuar]
    G --> I[Eliminar último dígito<br/>del intento]
    H --> I
    I --> D
    D -- Sí --> J[malUbicados = existentes - bienUbicados]
    J --> K[/Retornar malUbicados/]
    K --> L([Fin])
```

## 9. Cómo explicar los diagramas

No describas únicamente las flechas. Usa esta estructura:

1. Qué dato entra.
2. Qué variable se inicializa.
3. Qué pregunta controla el ciclo.
4. Qué cambia dentro del ciclo.
5. Cuándo termina.
6. Qué resultado retorna o muestra.
