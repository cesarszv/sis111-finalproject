# Kit de preparación para la presentación final

## Objetivo

Este directorio contiene el material necesario para preparar la entrega del proyecto **Código Secreto** desde cero.

La evaluación anunciada para la semana del **8 y 10 de junio de 2026** tiene tres partes:

| Parte | Puntaje |
| :--- | ---: |
| Pregunta 1 sobre el proyecto | 33 |
| Pregunta 2 sobre el proyecto | 33 |
| Modificación presencial cronometrada de 5 minutos | 34 |
| **Total** | **100** |

También se debe llevar una sola hoja, sin carátula, con:

1. Nombre del estudiante.
2. Título del proyecto.
3. Descripción del proyecto.

## Cómo usar este kit

No intentes memorizar todos los documentos al mismo tiempo. Estudia en este orden:

| Orden | Archivo | Uso |
| :--- | :--- | :--- |
| 1 | [`01_hoja_entrega.md`](01_hoja_entrega.md) | Preparar la hoja obligatoria. |
| 2 | [`02_ruta_estudio.md`](02_ruta_estudio.md) | Seguir un plan diario hasta la presentación. |
| 3 | [`03_guion_exposicion.md`](03_guion_exposicion.md) | Practicar una explicación oral clara. |
| 4 | [`04_explicacion_codigo.md`](04_explicacion_codigo.md) | Comprender el programa función por función. |
| 5 | [`05_pseudocodigo.md`](05_pseudocodigo.md) | Explicar la lógica sin depender de C++. |
| 6 | [`06_diagramas_flujo.md`](06_diagramas_flujo.md) | Repasar visualmente las decisiones y bucles. |
| 7 | [`07_preguntas_profesor.md`](07_preguntas_profesor.md) | Practicar respuestas técnicas. |
| 8 | [`08_modificaciones_5_min.md`](08_modificaciones_5_min.md) | Entrenar cambios pequeños bajo tiempo. |
| 9 | [`09_simulacros.md`](09_simulacros.md) | Repetir evaluaciones completas de 100 puntos. |
| 10 | [`10_pruebas_demo.md`](10_pruebas_demo.md) | Ensayar la demostración del juego. |
| 11 | [`11_resumen_ultima_hora.md`](11_resumen_ultima_hora.md) | Repasar justo antes de ingresar. |

Para imprimir directamente la hoja obligatoria también está disponible:

- [`01_hoja_entrega_imprimir.html`](01_hoja_entrega_imprimir.html)

## Qué espera probablemente el profesor

Este análisis se basa en las lecciones disponibles en `sis111/lessons`.

El profesor insiste en:

- Entender primero el problema y después programar.
- Explicar la lógica paso a paso.
- Inicializar las variables.
- Diferenciar asignación `=` de comparación `==`.
- Elegir correctamente entre `while` y `for`.
- Usar `% 10` para extraer un dígito y `/ 10` para eliminarlo.
- Adaptar condiciones sin memorizar mecánicamente el código.

Por eso, la preparación se enfoca en comprensión, trazas manuales y cambios pequeños practicados con cronómetro.

## Comandos importantes

Desde la raíz del proyecto:

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
./build/codigo_secreto
```

Después de cualquier modificación presencial, compila antes de ejecutar.
