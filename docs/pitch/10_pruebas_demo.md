# Guía de demo

## Compilar

```bash
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
./build/codigo_secreto
```

## Demo recomendada

La primera partida usa `527`.

| Paso | Entrada | Resultado |
| :--- | :--- | :--- |
| Menú | `1` | Jugar. |
| Intentos | `7` | Configurar partida. |
| Código | `572` | `1` bien ubicado y `2` en otra posición. |
| Comando | `-1` | Suma de dígitos: `14`. |
| Código | `527` | Victoria. |
| Menú | `3` | Salir. |

## Pruebas automáticas

### Demo

```bash
printf '1\n7\n572\n-1\n527\n3\n' | ./build/codigo_secreto
```

### Validaciones y comandos

```bash
printf '1\n7\n55\n551\n-4\n572\n-1\n-2\n-3\n527\n3\n' | ./build/codigo_secreto
```

### Derrota

```bash
printf '1\n2\n123\n456\n3\n' | ./build/codigo_secreto
```
