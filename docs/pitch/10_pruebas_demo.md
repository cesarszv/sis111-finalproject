# Guía para demostrar el juego

## 1. Preparar la terminal

Desde la carpeta del proyecto:

```bash
cd /home/cszv/Documents/UCB-LIA/sis111/assignments/final_project
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
./build/codigo_secreto
```

Si la compilación no muestra errores ni advertencias, inicia la demo.

## 2. Demo recomendada

En la primera partida con dificultad fácil:

```text
numeroPartida = 1
dificultad = 1
selector = (1 + 1) % 5 = 2
codigoSecreto = 864
```

Usa esta secuencia:

| Paso | Entrada | Qué demuestra |
| :--- | :--- | :--- |
| Menú | `1` | Iniciar partida. |
| Dificultad | `1` | Elegir fácil: 10 intentos. |
| Intento 1 | `468` | Mostrar pistas: 1 bien ubicado y 2 mal ubicados. |
| Intento 2 | `864` | Mostrar victoria y puntaje. |
| Menú | `3` | Salir. |

## 3. Guion mientras ejecutas

> Voy a iniciar una partida en dificultad fácil. Primero ingresaré un código válido, pero incorrecto: `468`. El secreto de esta demo es `864`. Los tres dígitos existen, pero solamente el `6` está en la posición correcta. Por eso el programa debe mostrar un bien ubicado y dos mal ubicados. Después ingresaré `864` para demostrar el flujo de victoria y el puntaje.

## 4. Pruebas que debes ejecutar antes de presentar

### Prueba A: salir directamente

Entrada:

```text
3
```

Resultado esperado: el programa termina sin errores.

### Prueba B: ver instrucciones

Entrada:

```text
2
3
```

Resultado esperado: muestra instrucciones y vuelve al menú.

### Prueba C: opción inválida

Entrada:

```text
4
3
```

Resultado esperado: rechaza `4` y solicita `1`, `2` o `3`.

### Prueba D: texto en vez de número

Entrada:

```text
hola
3
```

Resultado esperado: informa que la entrada es inválida y vuelve a pedir un entero.

### Prueba E: intento con pocos dígitos

Durante una partida:

```text
55
```

Resultado esperado: rechaza el código.

### Prueba F: intento repetido

Durante una partida:

```text
551
```

Resultado esperado: rechaza el código porque tiene dígitos repetidos.

### Prueba G: pistas

Primera partida fácil:

```text
468
```

Resultado esperado:

```text
Digitos correctos y bien ubicados: 1
Digitos correctos pero mal ubicados: 2
```

### Prueba H: victoria

Primera partida fácil:

```text
864
```

Resultado esperado:

```text
Descubriste el codigo secreto.
Puntaje final: 550
```

## 5. Tabla para otras primeras partidas

| Dificultad | Valor | Primera partida: selector | Código secreto |
| :--- | ---: | ---: | ---: |
| Fácil | `1` | `(1 + 1) % 5 = 2` | `864` |
| Normal | `2` | `(2 + 1) % 5 = 3` | `392` |
| Difícil | `3` | `(3 + 1) % 5 = 4` | `615` |

## 6. Prueba automatizada rápida

Para verificar una victoria en la primera partida fácil:

```bash
printf '1\n1\n864\n3\n' | ./build/codigo_secreto
```

Para verificar validaciones y pistas:

```bash
printf '1\n1\n55\n551\n468\n864\n3\n' | ./build/codigo_secreto
```

## 7. Después de una modificación presencial

Siempre sigue este orden:

1. Guardar `codigo.cpp`.
2. Compilar.
3. Leer cualquier error con calma.
4. Corregir únicamente el error indicado.
5. Volver a compilar.
6. Ejecutar el caso mínimo que demuestra el cambio.
