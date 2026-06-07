# Guía de demo

## Compilar

```bash
g++ -std=c++17 -Wall -Wextra -pedantic codigo.cpp -o build/codigo_secreto
./build/codigo_secreto
```

## Demo recomendada

La primera partida usa `58274`.

| Paso | Entrada | Resultado |
| :--- | :--- | :--- |
| Menú | `1` | Jugar. |
| Intentos | `10` | Configurar partida. |
| Ayuda inicial | automática | Posición `3`: `2`. |
| Acción | `1` | Intentar código. |
| Código | `58274` | Activa el desafío final. |
| Clave final | `87452` | Victoria y puntaje. |
| Menú | `3` | Salir. |

## Pruebas automáticas

### Victoria limpia

```bash
printf '1\n10\n1\n58274\n87452\n3\n' | ./build/codigo_secreto
```

### Ayuda, pista e intento incorrecto

```bash
printf '1\n10\n2\n3\n1\n12345\n1\n58274\n87452\n3\n' | ./build/codigo_secreto
```

### Fallo en el desafío final

```bash
printf '1\n10\n1\n58274\n11111\n22222\n3\n' | ./build/codigo_secreto
```

### Validaciones

```bash
printf '1\n10\n1\n123\n11234\n58274\n87452\n3\n' | ./build/codigo_secreto
```
