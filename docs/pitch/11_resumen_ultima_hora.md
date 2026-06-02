# Resumen de última hora

## Proyecto

**Código Secreto**: juego de consola para descubrir un número oculto de tres dígitos diferentes.

Pistas:

1. Dígitos correctos y bien ubicados.
2. Dígitos correctos pero mal ubicados.

## Fórmulas esenciales

```cpp
digito = numero % 10; // extraer último dígito
numero = numero / 10; // eliminar último dígito
```

```cpp
malUbicados = existentes - bienUbicados;
```

```cpp
puntaje = dificultad * 100 + intentosRestantes * 50;
```

```cpp
selector = (dificultad + numeroPartida) % 5;
```

## Ciclos

| Ciclo | Cuándo usarlo | Uso en el proyecto |
| :--- | :--- | :--- |
| `for` | Conozco la cantidad exacta. | Comparar 3 posiciones. |
| `while` | Repito según una condición. | Partida y búsqueda de dígitos. |
| `do while` | Debe ejecutarse al menos una vez. | Menú principal. |

## Operadores

| Operador | Significado |
| :--- | :--- |
| `=` | Asignar. |
| `==` | Comparar. |
| `!=` | Diferente. |
| `&&` | Ambas condiciones deben cumplirse. |
| `||` | Basta con una condición verdadera. |
| `%` | Residuo de una división. |

## Funciones clave

| Función | Qué hace |
| :--- | :--- |
| `tieneTresDigitos` | Valida el rango `100` a `999`. |
| `existeDigito` | Busca un dígito dentro de un número. |
| `tieneDigitosRepetidos` | Detecta repeticiones. |
| `esIntentoValido` | Combina validaciones. |
| `contarDigitosBienUbicados` | Compara las 3 posiciones. |
| `contarDigitosMalUbicados` | Cuenta existentes y resta bien ubicados. |
| `jugar` | Coordina una partida completa. |

## Ejemplo obligatorio

```text
Código secreto: 864
Intento:        468
```

Resultado:

```text
Bien ubicados: 1
Mal ubicados: 2
```

## Prototipo, llamada y definición

```cpp
int calcularPuntaje(int intentosRestantes, int dificultad); // prototipo
puntaje = calcularPuntaje(9, 1);                            // llamada

int calcularPuntaje(int intentosRestantes, int dificultad) { // definición
    return dificultad * 100 + intentosRestantes * 50;
}
```

## Si te piden modificar algo

1. Repetir el requerimiento.
2. Identificar la función responsable.
3. Cambiar lo mínimo.
4. Compilar.
5. Probar.

```bash
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
./build/codigo_secreto
```

## Respuestas cortas importantes

**¿Por qué no usaste arrays?**

Porque el proyecto exige lógica básica. Proceso dígitos con `% 10` y `/ 10`.

**¿Por qué no usaste números aleatorios?**

Para evitar bibliotecas adicionales. Alterno cinco códigos predefinidos.

**¿Por qué restas bien ubicados?**

Porque un dígito bien ubicado también existe. Debo restarlo para no contarlo dos veces.

**¿Por qué puedes dividir parámetros sin perder valores originales?**

Porque las funciones reciben copias por valor.

## Recordatorio final

No respondas apresuradamente. Explica primero el objetivo, luego la condición y finalmente el resultado.
