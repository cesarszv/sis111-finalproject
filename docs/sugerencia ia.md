# Código Secreto: decisiones de diseño

## Concepto

Código Secreto es un juego de deducción en consola. El jugador intenta descubrir un número de tres dígitos diferentes.

## Decisiones finales

### Pistas automáticas

Después de cada intento incorrecto se muestran las dos pistas esenciales:

- Dígitos bien ubicados.
- Dígitos correctos en otra posición.

Estas pistas son el centro del juego. El usuario no debe solicitarlas manualmente.

### Comandos directos

Si necesita más ayuda, puede escribir:

| Comando | Resultado |
| ---: | :--- |
| `-1` | Suma de dígitos. |
| `-2` | Cantidad de pares. |
| `-3` | Comparación con `500`. |

No existe un submenú de pistas. Los comandos directos reducen pasos innecesarios.

### Sin puntaje

La versión final no usa puntaje. La victoria ya se entiende con la cantidad de intentos usados. Retirar esa fórmula reduce reglas secundarias.

### Intentos configurables

El jugador elige entre `1` y `20` intentos. Esto permite ajustar la dificultad sin añadir niveles artificiales.

## Relación con las lecciones

| Tema | Aplicación |
| :--- | :--- |
| Condicionales | Validar opciones y códigos. |
| `while` | Repetir validaciones y recorrer números. |
| `do while` | Repetir menú principal. |
| `for` | Comparar tres posiciones. |
| `% 10` | Extraer último dígito. |
| `/ 10` | Eliminar último dígito. |
| Funciones | Separar responsabilidades. |

## Alcance

El proyecto prioriza una mecánica pequeña, entendible y defendible. No utiliza arrays, clases ni bibliotecas adicionales.
