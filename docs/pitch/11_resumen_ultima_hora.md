# Resumen de última hora

## Mecánica

- Descubrir un código de tres dígitos diferentes.
- Recibir pistas automáticas después de fallar.
- Usar `-1`, `-2` o `-3` para ayuda extra.

## Fórmulas

```cpp
digito = numero % 10;
numero = numero / 10;
```

```cpp
malUbicados = existentes - bienUbicados;
```

## Comandos

| Comando | Pista |
| ---: | :--- |
| `-1` | Suma. |
| `-2` | Pares. |
| `-3` | Mayor o menor que `500`. |

## Respuestas rápidas

**¿Por qué negativos?**

No se confunden con códigos válidos.

**¿Por qué `for`?**

Comparo exactamente tres posiciones.

**¿Por qué `while`?**

Repito mientras una condición sea verdadera.

**¿Por qué no arrays?**

Proceso dígitos con `% 10` y `/ 10`.

## Ejemplo

```text
Secreto: 527
Intento: 572
Bien ubicados: 1
Correctos en otra posicion: 2
```
