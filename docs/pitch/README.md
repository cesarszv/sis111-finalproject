# Kit de preparación para la presentación final

## Objetivo

Este directorio contiene material para comprender, presentar y modificar el proyecto **Código Secreto**.

La evaluación anunciada para la semana del **8 y 10 de junio de 2026** tiene tres partes:

| Parte | Puntaje |
| :--- | ---: |
| Pregunta 1 sobre el proyecto | 33 |
| Pregunta 2 sobre el proyecto | 33 |
| Modificación presencial cronometrada de 5 minutos | 34 |
| **Total** | **100** |

También se debe entregar una sola hoja, sin carátula, con:

1. Nombre del estudiante.
2. Título del proyecto.
3. Descripción del proyecto.

## Versión actual del juego

El jugador:

1. Define cuántos intentos desea tener.
2. Ingresa códigos de tres dígitos diferentes.
3. Escribe `0` cuando necesita abrir el menú de pistas.
4. Elige qué tipo de pista quiere recibir.
5. Gana si descubre el código antes de agotar los intentos.

## Orden de estudio

| Orden | Archivo | Uso |
| :--- | :--- | :--- |
| 1 | [`01_hoja_entrega.md`](01_hoja_entrega.md) | Preparar la hoja obligatoria. |
| 2 | [`02_ruta_estudio.md`](02_ruta_estudio.md) | Seguir un plan diario. |
| 3 | [`03_guion_exposicion.md`](03_guion_exposicion.md) | Practicar la explicación oral. |
| 4 | [`04_explicacion_codigo.md`](04_explicacion_codigo.md) | Comprender la estructura del programa. |
| 5 | [`05_pseudocodigo.md`](05_pseudocodigo.md) | Explicar la lógica sin depender de C++. |
| 6 | [`06_diagramas_flujo.md`](06_diagramas_flujo.md) | Repasar visualmente decisiones y ciclos. |
| 7 | [`07_preguntas_profesor.md`](07_preguntas_profesor.md) | Practicar respuestas técnicas. |
| 8 | [`08_modificaciones_5_min.md`](08_modificaciones_5_min.md) | Entrenar cambios cronometrados. |
| 9 | [`09_simulacros.md`](09_simulacros.md) | Resolver evaluaciones completas. |
| 10 | [`10_pruebas_demo.md`](10_pruebas_demo.md) | Ensayar la demostración. |
| 11 | [`11_resumen_ultima_hora.md`](11_resumen_ultima_hora.md) | Repasar antes de ingresar. |
| 12 | [`12_checklist_dia_entrega.md`](12_checklist_dia_entrega.md) | Revisar materiales y entorno. |

Para imprimir directamente la hoja obligatoria:

- [`01_hoja_entrega_imprimir.html`](01_hoja_entrega_imprimir.html)

La explicación más completa del programa está en [`../../codigo.md`](../../codigo.md).

## Compilar

Desde la raíz del proyecto:

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
./build/codigo_secreto
```
