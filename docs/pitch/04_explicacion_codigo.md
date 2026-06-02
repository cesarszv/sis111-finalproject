# Explicación rápida de `codigo.cpp`

Explicación completa: [`../../codigo.md`](../../codigo.md).

## Bloques

| Bloque | Responsabilidad |
| :--- | :--- |
| Prototipos | Anuncian las funciones. |
| `main` | Repite el menú principal. |
| Funciones de dígitos | Validan y calculan pistas. |
| Funciones de interacción | Leen datos y muestran mensajes. |
| `jugar` | Controla una partida completa. |

## Funciones principales

| Función | Qué hace |
| :--- | :--- |
| `esCodigoValido` | Exige tres dígitos diferentes. |
| `existeDigito` | Busca un dígito. |
| `contarDigitosBienUbicados` | Compara posiciones. |
| `contarDigitosMalUbicados` | Cuenta coincidencias en otra posición. |
| `sumarDigitos` | Calcula la pista `-1`. |
| `contarDigitosPares` | Calcula la pista `-2`. |
| `mostrarPistaExtra` | Responde a `-1`, `-2` o `-3`. |
| `jugar` | Repite turnos hasta victoria o derrota. |

## Decisión central

```cpp
if (codigoOComando < 0) {
    mostrarPistaExtra(codigoOComando, codigoSecreto);
} else {
    intentosUsados++;
    // comprobar respuesta y mostrar pistas automáticas
}
```

Los negativos son comandos. Los positivos válidos son intentos.
