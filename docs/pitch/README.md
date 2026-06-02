# Kit de preparación para la presentación

## Evaluación

| Parte | Puntaje |
| :--- | ---: |
| Pregunta 1 sobre el proyecto | 33 |
| Pregunta 2 sobre el proyecto | 33 |
| Modificación presencial de 5 minutos | 34 |
| **Total** | **100** |

También se debe entregar una sola hoja, sin carátula.

## Mecánica actual

1. El jugador elige cuántos intentos tendrá.
2. Ingresa códigos de tres dígitos diferentes.
3. Después de cada error recibe pistas automáticas.
4. Puede pedir ayuda extra con `-1`, `-2` o `-3`.
5. Gana al descubrir el código.

## Orden de estudio

| Orden | Archivo | Uso |
| :--- | :--- | :--- |
| 1 | [`01_hoja_entrega.md`](01_hoja_entrega.md) | Preparar la hoja obligatoria. |
| 2 | [`03_guion_exposicion.md`](03_guion_exposicion.md) | Ensayar la explicación oral. |
| 3 | [`04_explicacion_codigo.md`](04_explicacion_codigo.md) | Comprender el programa. |
| 4 | [`05_pseudocodigo.md`](05_pseudocodigo.md) | Repasar lógica sin sintaxis. |
| 5 | [`06_diagramas_flujo.md`](06_diagramas_flujo.md) | Visualizar el flujo. |
| 6 | [`07_preguntas_profesor.md`](07_preguntas_profesor.md) | Practicar respuestas. |
| 7 | [`08_modificaciones_5_min.md`](08_modificaciones_5_min.md) | Entrenar cambios. |
| 8 | [`09_simulacros.md`](09_simulacros.md) | Evaluarte. |
| 9 | [`10_pruebas_demo.md`](10_pruebas_demo.md) | Preparar la demo. |
| 10 | [`11_resumen_ultima_hora.md`](11_resumen_ultima_hora.md) | Repasar antes de ingresar. |

Explicación completa: [`../../codigo.md`](../../codigo.md).

## Compilar

```bash
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
./build/codigo_secreto
```
