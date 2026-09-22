# Proyecto de Sistemas Operativos
## Implementación de un Shell para xv6
### Integrantes
- Ana Isabella Gómez García
### Curso
Sistemas Operativos
### Semestre
2026-2
---
# Descripción
Este proyecto
# Estructura de archivos
```text
user/
├── trace.c
├── sysinfo.c
├──
kernel/
├──
autoevaluacion/
├──AnaIsabellaGomez.md
```
## Descripción de los archivos
### sh.c
Archivo principal del shell.
### parser.c
Contiene las funciones encargadas de analizar la línea de comandos ingresada por
el usuario.
### parser.h
Definiciones y prototipos asociados al parser.### commands.c
Implementación de rutinas relacionadas con la ejecución de comandos y
tuberías.
### commands.h
Prototipos de funciones relacionadas con la ejecución.
### utils.h
Constantes y funciones auxiliares utilizadas en el proyecto.
---
# Integración con xv6
## Paso 1. Obtener xv6
```bash
git clone https://github.com/Taegrito/proyecto1SistemasOperativos
```
## Paso 2. Copiar archivos
Copiar todos los archivos entregados dentro del directorio `user/`.
## Paso 3. Modificar el Makefile
Agregar el programa al listado de aplicaciones de usuario.
## Paso 4. Compilar xv6
```bash
make qemu
```
## Paso 5. Ejecutar el shell```bash
sh
```
---
# Casos de prueba
- Ejecución simple.
- Argumentos.
- Redirección de entrada.
- Redirección de salida.
- Tuberías simples.
- Tuberías múltiples.
- Comando `exit`.
---
# Decisiones de diseño
- Separación entre análisis sintáctico y ejecución.
- Uso de procesos independientes para cada etapa de una tubería.
- Manejo explícito de descriptores de archivo durante las redirecciones.
---
# Limitaciones conocidas
- No soporta comillas.
- No soporta variables de entorno.
- No soporta ejecución en segundo plano.
---
# Declaración de uso de IA
Durante el desarrollo del proyecto se utilizaron herramientas de inteligencia
artificial generativa como apoyo para comprensión de conceptos, revisión de
código y generación de ejemplos.Los integrantes asumen plena responsabilidad académica sobre el contenido
entregado
