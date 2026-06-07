# Resumen de última hora

## Mecánica

- Descubrir un código de cinco dígitos diferentes.
- Recibir una ayuda inicial gratis.
- Elegir entre intentar, revelar, pedir pista o rendirse.
- Completar el desafío final.
- Recibir puntaje final.

## Fórmulas

```cpp
digito = numero % 10;
numero = numero / 10;
```

```cpp
malUbicados = existentes - bienUbicados;
```

## Pistas

| Pista | Información |
| ---: | :--- |
| `1` | Suma. |
| `2` | Pares e impares. |
| `3` | Mayor o menor que `50000`. |

## Respuestas rápidas

**¿Por qué menú de turno?**

Es más claro que memorizar comandos.

**¿Por qué `for`?**

Comparo exactamente cinco posiciones.

**¿Por qué `while`?**

Repito mientras una condición sea verdadera.

**¿Por qué no arrays?**

Proceso dígitos con `% 10` y `/ 10`.

**¿Por qué puntaje?**

Permite que el jugador elija dificultad: usar más ayudas baja el resultado.

## Ejemplo

```text
Secreto: 58274
Intento: 12345
Lugares exactos: 0
Correctos en otro lugar: 3
Clave final: 87452
```
