# Guía para demostrar el juego

## 1. Preparar terminal

```bash
cd /home/cszv/Documents/UCB-LIA/sis111/assignments/final_project
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
./build/codigo_secreto
```

## 2. Demo recomendada

En la primera partida:

```text
numeroPartida = 1
selector = 1 % 5 = 1
codigoSecreto = 527
```

Usa:

| Paso | Entrada | Demuestra |
| :--- | :--- | :--- |
| Menú | `1` | Iniciar partida. |
| Intentos | `7` | Configuración elegida por usuario. |
| Intento | `572` | Código válido incorrecto. |
| Comando | `0` | Abrir menú de pistas. |
| Pista | `1` | Un dígito bien ubicado. |
| Comando | `0` | Abrir nuevamente. |
| Pista | `2` | Dos dígitos mal ubicados. |
| Intento | `527` | Victoria. |
| Menú | `3` | Salida y despedida. |

## 3. Guion

> Voy a elegir siete intentos. El primer código secreto es `527`. Ingreso `572`: los tres dígitos existen, pero solamente el `5` está en su posición correcta. Ahora escribo `0`, que abre el menú de pistas sin consumir intentos. Solicito primero los bien ubicados y después los mal ubicados. Finalmente ingreso `527` para demostrar la victoria.

## 4. Pruebas manuales

### Salir

```text
3
```

Debe mostrar despedida.

### Ver instrucciones

```text
2
3
```

Debe explicar el comando `0`.

### Rechazar cantidad inválida

```text
1
21
7
```

Debe volver a pedir una cantidad entre `1` y `20`.

### Rechazar código corto

```text
55
```

Debe explicar que se requieren exactamente tres dígitos.

### Rechazar repetición

```text
551
```

Debe explicar que los dígitos deben ser diferentes.

### Pedir pista antes del primer intento

```text
0
1
```

Debe explicar que primero necesita un intento para comparar posiciones. No debe incrementar `pistasUsadas`.

### Pedir pista independiente

```text
0
4
```

En la primera partida debe mostrar:

```text
Suma de los digitos del codigo secreto: 14
```

### Ganar en un intento

```text
527
```

Debe mostrar:

```text
Puntaje final: 1000
```

## 5. Pruebas automatizadas

### Victoria directa

```bash
printf '1\n1\n527\n3\n' | ./build/codigo_secreto
```

### Validaciones, pistas y victoria

```bash
printf '1\n7\n55\n551\n572\n0\n1\n0\n2\n527\n3\n' | ./build/codigo_secreto
```

### Derrota

```bash
printf '1\n2\n123\n456\n3\n' | ./build/codigo_secreto
```

## 6. Después de una modificación

1. Guardar `codigo.cpp`.
2. Compilar.
3. Leer errores con calma.
4. Corregir únicamente lo indicado.
5. Volver a compilar.
6. Ejecutar un caso que demuestre el cambio.
