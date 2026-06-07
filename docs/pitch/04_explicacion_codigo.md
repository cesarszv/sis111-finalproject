# Explicación rápida de `codigo.cpp`

Explicación completa: [`../../codigo.md`](../../codigo.md).

## Bloques

| Bloque | Responsabilidad |
| :--- | :--- |
| Prototipos | Anuncian las funciones. |
| `main` | Repite el menú principal. |
| Funciones de dígitos | Validan, comparan y calculan claves. |
| Funciones de interacción | Leen datos y muestran mensajes. |
| `jugar` | Controla una partida completa. |

## Funciones principales

| Función | Qué hace |
| :--- | :--- |
| `esCodigoValido` | Exige cinco dígitos diferentes. |
| `obtenerDigitoEnPosicion` | Revela un dígito según posición. |
| `contarDigitosBienUbicados` | Compara posiciones exactas. |
| `contarDigitosMalUbicados` | Cuenta dígitos correctos en otro lugar. |
| `mostrarPistaIndirecta` | Muestra una pista simple. |
| `calcularClaveFinal` | Forma la clave del desafío final. |
| `calcularPuntaje` | Calcula el puntaje final. |
| `jugar` | Repite turnos hasta victoria, derrota o rendición. |

## Decisión central

```cpp
if (opcionTurno == 1) {
    // intentar codigo
} else if (opcionTurno == 2) {
    // revelar digito
} else if (opcionTurno == 3) {
    // pedir pista
} else {
    // rendirse
}
```

El jugador decide cuánto riesgo quiere tomar. Pedir ayuda facilita la partida, pero baja el puntaje.
