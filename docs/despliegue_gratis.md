# Investigación: publicar Código Secreto gratis en internet

## 1. Objetivo

Investigar cómo compartir el proyecto `Código Secreto` en internet sin pagar y sin mezclar la versión académica de C++ con tecnologías que todavía no se avanzaron en clase.

Investigación verificada el **1 de junio de 2026** con documentación oficial.

## 2. Punto de partida técnico

El programa actual es una aplicación de consola:

```text
Usuario escribe en terminal -> programa C++ procesa -> terminal muestra respuesta
```

No es todavía una página web:

```text
Navegador -> HTML, CSS, JavaScript o WebAssembly -> interfaz visual
```

Por eso existen tres objetivos distintos:

| Objetivo | Solución adecuada |
| :--- | :--- |
| Compartir el código fuente | Repositorio de GitHub |
| Permitir que alguien lo ejecute en internet sin instalar C++ | JDoodle |
| Tener una página pública con presentación y ejecución integrada | GitHub Pages con un embed de JDoodle |

## 3. Recomendación principal

Para la entrega académica, la opción más práctica es:

1. Subir el proyecto a GitHub.
2. Crear una copia ejecutable en un proyecto multifichero de JDoodle.
3. Generar un enlace compartible de JDoodle.
4. Añadir ese enlace al `README.md`.
5. Como mejora opcional, crear una página estática en GitHub Pages e insertar el embed básico de JDoodle.

Esta ruta conserva el proyecto original en C++ y evita convertirlo prematuramente en una aplicación web.

## 4. Opción A: GitHub

### Qué resuelve

GitHub permite publicar:

- Código fuente.
- Documentación Markdown.
- Diagramas Mermaid incluidos en los archivos `.md`.
- Historial de cambios.
- Instrucciones de compilación.

### Qué no resuelve

Un repositorio de GitHub no ejecuta automáticamente el juego de consola para el visitante.

### Cuándo usarlo

Debe ser la fuente oficial del proyecto. El enlace de GitHub sirve para que el docente revise:

- Organización modular.
- Headers y sources.
- Explicaciones por archivo.
- Instrucciones para compilar.

## 5. Opción B: JDoodle

### Por qué encaja con este proyecto

La documentación oficial del IDE de JDoodle indica soporte para:

- Más de 110 lenguajes.
- Proyectos multifichero.
- Entrada estándar.
- Modo interactivo.
- Enlaces compartibles.
- Embeds básicos.

La página oficial de lenguajes indica soporte para C++ 17.

Esto permite copiar:

```text
main.cpp
juego.h
juego.cpp
logica_digitos.h
logica_digitos.cpp
```

y ejecutar el juego desde internet sin modificar su lógica.

### Límite gratuito relevante

La documentación oficial del plan Free indica:

- Hasta `100` ejecuciones diarias.
- Guardado de proyectos.
- Embeds básicos ilimitados.

Estos límites son suficientes para una demostración académica pequeña. Deben verificarse nuevamente si el proyecto se usa meses después, porque los planes pueden cambiar.

### Pasos recomendados

1. Crear una cuenta gratuita en [JDoodle](https://www.jdoodle.com/).
2. Crear un proyecto C++.
3. Seleccionar C++ 17.
4. Activar el modo multifichero.
5. Copiar los cinco archivos de código.
6. Ejecutar una partida de prueba.
7. Usar la opción de compartir el proyecto.
8. Añadir el enlace compartible al `README.md`.

### Resultado

El docente podrá abrir un enlace, ejecutar el programa e interactuar con la consola desde el navegador.

### Limitación

JDoodle ofrece un entorno de ejecución compartido. No convierte el juego en una página web con diseño propio.

## 6. Opción C: GitHub Pages con embed de JDoodle

### Qué es GitHub Pages

La documentación oficial define GitHub Pages como un servicio de hosting para sitios estáticos. Toma archivos HTML, CSS y JavaScript desde un repositorio y publica una página web.

GitHub Pages está disponible en repositorios públicos con GitHub Free.

### Limitación importante

GitHub Pages no ejecuta directamente un binario C++ de terminal. Solo publica archivos estáticos.

### Cómo combinarlo con JDoodle

La documentación oficial de JDoodle indica que el embed básico:

- Es gratuito.
- No requiere API.
- Permite integrar un editor y compilador ejecutable.
- Se puede insertar con pocas líneas de HTML.

La idea sería:

```text
GitHub Pages
    -> muestra descripción del proyecto
    -> muestra instrucciones
    -> integra el ejecutor de JDoodle
```

### Cuándo conviene

Usar esta opción únicamente después de terminar la entrega mínima. Añade presentación, pero no mejora la lógica evaluada por el profesor.

## 7. Opción D: Emscripten y WebAssembly

### Qué permite

Emscripten compila C y C++ a WebAssembly y genera archivos que pueden ejecutarse en navegadores modernos.

Un resultado típico incluye:

```text
codigo_secreto.html
codigo_secreto.js
codigo_secreto.wasm
```

Estos archivos estáticos podrían publicarse con GitHub Pages.

### Ventaja

El navegador ejecutaría una versión compilada del código C++.

### Por qué no es la primera opción

El programa actual depende de una conversación síncrona por consola:

```cpp
cin >> numero;
```

Una interfaz web necesita controlar entradas y salidas dentro del navegador. La documentación de Emscripten explica que el navegador trabaja con eventos asíncronos y ofrece Asyncify para transformar código síncrono cuando se necesita esperar operaciones asíncronas.

Inferencia técnica: publicar una versión cómoda para usuarios requerirá adaptar la interacción, probar la entrada y posiblemente añadir HTML o JavaScript. Eso amplía el alcance más allá de la entrega introductoria.

### Cuándo conviene

Usar Emscripten como fase futura si el objetivo cambia de “entregar el juego de consola” a “crear una versión web nativa”.

## 8. Opción E: Replit

### Qué permite

La documentación oficial de Replit describe:

- Importación de repositorios desde GitHub.
- Publicación de aplicaciones.
- Un plan Starter gratuito con una aplicación publicada.

La página del plan Starter indica que el enlace publicado gratuito deja de funcionar automáticamente después de 30 días.

### Limitación para este proyecto

La publicación de una aplicación no transforma automáticamente un programa de consola en una interfaz web.

Inferencia técnica: Replit resulta útil para guardar, ejecutar y compartir el entorno de desarrollo; para una URL pública con experiencia web propia todavía sería necesario añadir una capa web.

### Cuándo conviene

Usarlo como alternativa a JDoodle si se desea trabajar dentro de un entorno de desarrollo en línea o si posteriormente se agrega una interfaz web.

## 9. Comparación

| Opción | Gratis | Ejecuta el C++ actual | URL compartible | Requiere cambiar la lógica | Recomendación |
| :--- | :--- | :--- | :--- | :--- | :--- |
| GitHub | Sí | No | Sí | No | Fuente oficial |
| JDoodle | Sí, con límites | Sí | Sí | No | Mejor demo inmediata |
| GitHub Pages + JDoodle | Sí | Sí, mediante embed | Sí | No | Mejor presentación opcional |
| Emscripten + GitHub Pages | Sí | Sí, tras adaptación | Sí | Sí | Fase futura |
| Replit | Sí, con condiciones | Sirve para ejecutar; publicar una web requiere adaptación | Sí | Posiblemente | Alternativa |

## 10. Ruta de trabajo recomendada

### Entrega mínima

1. Terminar la lógica local.
2. Conservar los módulos `.h` y `.cpp`.
3. Subir el repositorio a GitHub.
4. Crear el proyecto multifichero en JDoodle.
5. Añadir el enlace ejecutable al README.

### Presentación adicional

1. Crear una página HTML pequeña.
2. Publicarla con GitHub Pages.
3. Integrar el embed básico de JDoodle.
4. Enlazar el repositorio original.

### Fase futura

1. Estudiar Emscripten.
2. Diseñar una entrada web para reemplazar la conversación de terminal.
3. Compilar a WebAssembly.
4. Publicar los archivos generados con GitHub Pages.

## 11. Fuentes oficiales

- [GitHub Docs: What is GitHub Pages?](https://docs.github.com/en/pages/getting-started-with-github-pages/what-is-github-pages)
- [GitHub Docs: Configuring a publishing source for your GitHub Pages site](https://docs.github.com/en/pages/getting-started-with-github-pages/configuring-a-publishing-source-for-your-github-pages-site)
- [JDoodle Docs: IDE quick start](https://www.jdoodle.com/docs/ide/ide-quick-start/getting-started/)
- [JDoodle Docs: Multi-file execution](https://www.jdoodle.com/docs/ide/ide-quick-start/multi-file-execution/)
- [JDoodle Docs: Save and share projects](https://www.jdoodle.com/docs/ide/save-share-projects)
- [JDoodle Docs: Languages and versions](https://www.jdoodle.com/docs/ide/languages-versions)
- [JDoodle Docs: Plans and billing](https://www.jdoodle.com/docs/getting-started/plans-billing/getting-started)
- [JDoodle Docs: Basic Embeds](https://www.jdoodle.com/docs/embed-ides/basic-embeds)
- [Emscripten Docs: Tutorial](https://emscripten.org/docs/getting_started/Tutorial.html)
- [Emscripten Docs: Asyncify](https://emscripten.org/docs/porting/asyncify.html)
- [Replit Docs: Import from a provider](https://docs.replit.com/build/import-from-providers)
- [Replit Docs: Publishing](https://docs.replit.com/learn/projects-and-artifacts/replit-deployments)
- [Replit Docs: Starter Plan](https://docs.replit.com/billing/plans/starter-plan)
