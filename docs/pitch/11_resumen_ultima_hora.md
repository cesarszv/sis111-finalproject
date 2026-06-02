# Resumen de última hora

## Proyecto

Código Secreto es un juego de consola para descubrir un número oculto de tres dígitos diferentes.

El jugador elige cuántos intentos tendrá y escribe `0` cuando quiere pedir una pista.

## Fórmulas

```cpp
digito = numero % 10; // extraer último dígito
numero = numero / 10; // eliminar último dígito
```

```cpp
malUbicados = existentes - bienUbicados;
```

```cpp
puntaje = 1100 - intentosUsados * 100;
```

```cpp
selector = numeroPartida % 5;
```

## Ciclos

| Ciclo | Uso |
| :--- | :--- |
| `for` | Comparar exactamente tres posiciones. |
| `while` | Repetir según condición. |
| `do while` | Mostrar menú al menos una vez. |

## Operadores

| Operador | Significado |
| :--- | :--- |
| `=` | Asignar. |
| `==` | Comparar. |
| `!=` | Diferente. |
| `&&` | Ambas condiciones. |
| `||` | Al menos una condición. |
| `%` | Residuo. |

## Funciones esenciales

| Función | Qué hace |
| :--- | :--- |
| `esCodigoValido` | Exige tres dígitos diferentes. |
| `existeDigito` | Busca un dígito. |
| `contarDigitosBienUbicados` | Compara posiciones. |
| `contarDigitosMalUbicados` | Resta coincidencias bien ubicadas. |
| `contarDigitosPares` | Cuenta pares. |
| `sumarDigitos` | Suma dígitos. |
| `mostrarPista` | Ejecuta el tipo de pista elegido. |
| `jugar` | Coordina una partida. |

## Comando

```text
0 = abrir menú de pistas
```

No consume intentos.

## Ejemplo

```text
Secreto: 527
Intento: 572
```

```text
Bien ubicados: 1
Mal ubicados: 2
Pares del secreto: 1
Suma: 14
Mayor que 500: sí
```

## Respuestas rápidas

**¿Por qué `0`?**

No se confunde con un código válido de tres dígitos.

**¿Por qué puntaje según usados?**

El jugador configura el máximo. Premiar restantes sería injusto.

**¿Por qué `mostrarPista` devuelve `bool`?**

Para contar solamente pistas realmente mostradas.

**¿Por qué no arrays?**

Proceso números matemáticamente con `% 10` y `/ 10`.

## Compilar

```bash
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
./build/codigo_secreto
```
