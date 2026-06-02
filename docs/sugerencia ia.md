# Código Secreto: alcance implementado

## 1. Concepto

Código Secreto es un juego de consola escrito en C++. El jugador debe descubrir un número oculto de tres dígitos diferentes.

La versión implementada busca ser:

- Fácil de jugar.
- Fácil de explicar desde cero.
- Compatible con los contenidos de Introducción a la Programación.
- Comprensible sin arrays, clases ni bibliotecas adicionales.

## 2. Experiencia del jugador

1. El jugador inicia una partida.
2. Define cuántos intentos quiere tener: entre `1` y `20`.
3. Ingresa códigos de tres dígitos diferentes.
4. Puede escribir `0` durante cualquier turno para pedir una pista.
5. Continúa hasta ganar o quedarse sin intentos.

## 3. Pistas disponibles

El jugador decide qué información necesita:

1. Cantidad de dígitos bien ubicados en el último intento.
2. Cantidad de dígitos correctos que están en otra posición.
3. Cantidad de dígitos pares del código secreto.
4. Suma de los dígitos del código secreto.
5. Si el código es mayor o menor que `500`.

También puede volver a la partida sin pedir una pista.

## 4. Razones de diseño

### Intentos configurables

El juego ya no impone dificultades predefinidas. El jugador decide cuántas oportunidades necesita. La recomendación visible en consola es usar `7`.

### Comando de pistas

El comando `0` es fácil de recordar y no puede confundirse con un código válido de tres dígitos.

### Puntaje independiente de la configuración

El puntaje depende de los intentos usados:

```cpp
puntaje = 1100 - intentosUsados * 100;
```

Elegir más intentos no aumenta el puntaje.

## 5. Relación con las lecciones

| Tema | Aplicación |
| :--- | :--- |
| Condicionales | Validar opciones y elegir comportamientos. |
| `while` | Repetir validaciones y búsquedas. |
| `do while` | Repetir el menú principal. |
| `for` | Comparar exactamente tres posiciones. |
| `% 10` | Extraer el último dígito. |
| `/ 10` | Eliminar el último dígito. |
| Funciones | Mantener responsabilidades pequeñas y claras. |
| Contadores | Registrar intentos y pistas. |

## 6. Alcance final

El proyecto evita agregar una segunda fase compleja. La prioridad es presentar una base funcional, clara y defendible técnicamente.

El código completo está en [`../codigo.cpp`](../codigo.cpp) y su explicación detallada está en [`../codigo.md`](../codigo.md).
