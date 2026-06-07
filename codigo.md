# Explicación del juego Código Secreto

## 1. Objetivo

El jugador debe descubrir el código secreto `58274`. La partida tiene 10 intentos y el jugador decide si pide ayudas o intenta resolverlo solo.

## 2. Reglas

1. El código secreto tiene cinco dígitos diferentes.
2. La partida tiene 10 intentos fijos.
3. La posición `3` se muestra gratis al inicio.
4. Hay 2 revelaciones exactas opcionales.
5. Hay 3 pistas suaves opcionales.
6. Después de descubrir el código hay un desafío final.
7. El puntaje baja cuando se usan intentos o ayudas.

## 3. Organización de `codigo.cpp`

```text
1. biblioteca iostream
2. prototipos
3. main
4. funciones esenciales
5. partida principal
```

El `main` usa solo `while`, porque es más fácil de leer:

```cpp
while (opcion != 3) {
    mostrar menu
    leer opcion
}
```

## 4. Procesar dígitos

Para extraer el último dígito:

```cpp
digito = numero % 10;
```

Para eliminar el último dígito:

```cpp
numero = numero / 10;
```

Ejemplo:

| Paso | Número antes | Dígito extraído | Número después |
| :--- | ---: | ---: | ---: |
| 1 | `58274` | `4` | `5827` |
| 2 | `5827` | `7` | `582` |
| 3 | `582` | `2` | `58` |
| 4 | `58` | `8` | `5` |
| 5 | `5` | `5` | `0` |

## 5. Funciones esenciales

| Función | Responsabilidad |
| :--- | :--- |
| `mostrarReglas` | Muestra instrucciones simples. |
| `obtenerDigitoEnPosicion` | Devuelve un dígito por posición. |
| `existeDigito` | Busca un dígito dentro del número. |
| `contarLugaresExactos` | Cuenta dígitos correctos en el mismo lugar. |
| `contarCorrectosEnOtroLugar` | Cuenta dígitos correctos pero movidos. |
| `sumarDigitos` | Calcula la pista de suma. |
| `contarPares` | Calcula la pista de pares e impares. |
| `ordenarAscendente` | Prepara el número para el desafío final. |
| `calcularClaveFinal` | Intercala pares e impares de mayor a menor. |
| `calcularPuntaje` | Calcula el puntaje final. |
| `jugar` | Controla toda la partida. |

## 6. Validación del intento

No hay una función separada para validar. La validación está dentro de `jugar`, porque así se entiende mejor:

```cpp
if (intento < 10000 || intento > 99999) {
    codigoValido = false;
}
```

También se comparan los cinco dígitos entre sí para evitar repetidos.

## 7. Ejemplo de intento

Código secreto:

```text
58274
```

Intento:

```text
12345
```

Resultado:

```text
lugares exactos, 0
digitos correctos en otro lugar, 3
```

## 8. Desafío final

Ejemplo con `58274`:

```text
Pares: 8, 4, 2
Impares: 7, 5
Clave final: 87452
```

Esta parte se basa en la lección de intercalar pares e impares.

## 9. Puntaje

```text
puntaje = 100
puntaje = puntaje - intentos usados
puntaje = puntaje - revelaciones usadas
puntaje = puntaje - pistas usadas
puntaje = puntaje - errores del desafio final
```

Si el jugador no completa el juego, el puntaje es `0`.

## 10. Compilar

```bash
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
./build/codigo_secreto
```
