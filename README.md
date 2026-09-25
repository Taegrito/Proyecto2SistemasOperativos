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
Este proyecto realizado en xv6-riscv, es un programa interactivo que permite hacer llamadas trace y sysinfo, a través de una división estructural entre el modo kernel y el modo usuario
# Estructura de archivos
```text
user/
├── trace.c
├── sysinfo.c
├── user.h
├── usys.pl
├── utils.h
kernel/
├── defs.h
├── proc.c
├── proc.h
├── syscall.c
├── syscall.h
├── sysproc.c
autoevaluacion/
├──AnaIsabellaGomez.md
```
## Descripción de la solución
Para este proyecto se utilizan archivos modificados de la carpeta, en los que se incluirán las llamadas al trace y al sysinfo, para que el cóodigo pueda correr con normalidad.
### trace.c
Programa de espacio de usuario para probar el comando trace.
### sysinfo.c
Programa de espacio de usuario para probar el comando sysinfo.
### user.h
Es la cabecera que incluye los prototipos de las llamadas al sistema y funciones de biblioteca disponibles para los programas de usuario
* **Modificaciones:** se añadieron los prototipos de la llamada
```
int trace(int);
int sysinfo(struct sysinfo *);
```
### usys.pl
Genera dinámicamente el código ensamblador.
* **Modificaciones:** se añadieron las entradas de los comandos.
```
entry("trace");
entry("sysinfo");
```
### utils.h

### defs.h
Contiene los prototipos de las funciones globales del kernel.
* **Modificaciones:**
Se agregaron las funciones del kernel para que puedan ser invocadas en distintos archivos.
```
sys_trace
sys_sysinfo
```
### proc.c
Cuenta con la implementación de las funciones del kernel.
* **Modificaciones:** se añadieron el campo p->trace_mask=0 para evitar basura y np->trace_mask=p->trace_mask para que el proceso hijo herede el mapeo del proceso padre.
### proc.h 
Define la estructura de control de procesos.
* **Modificaciones:** se agregó int trace_mask
```
int trace_mask;
```
Define la estructura de los procesos
* **Modificaciones:** Se agregregó el campo int trace_mask;
```
 int trace_mask;
```
### syscall.h
Define los números identificadores de cada una de las llamadas al sistema.
* **Modificaciones:** se agregan las nuevas constantes de syscall
```
#define SYS_trace  23
#define SYS_sysinfo 24
```
### syscall.c
Trabaja como un desparchador de llamadas al sistema, mapeando lo recibido desde el usuario hasta su función correspondiente en el kernel.
* **Modificaciones:** se declararon las funciones y entradas correspondientes al trace y sysinfo; además de modificarse la función de sys_call para que concordara con lo impreso en la terminal, utilizando "printk"
```
extern uint64 sys_trace(void);
extern uint64 sys_sysinfo(void);

 [SYS_trace]   sys_trace,
 [SYS_sysinfo] sys_sysinfo,

void
syscall(void)
{
  int num;
  struct proc *p = myproc();

  num = p->trapframe->a7;

  if(num > 0 && num < NELEM(syscalls) && syscalls[num]) {
    p->trapframe->a0 = syscalls[num]();

    if (p->trace_mask == num || num == SYS_kill) {
      printk("PID: %d\n", p->pid);
      printk("SYSCALL: %d\n", num);
      printk("RETURN: %d\n", (int)p->trapframe->a0);
      printk("s0: 0x%p\n", (void*)p->trapframe->s0);
      printk("s1: 0x%p\n", (void*)p->trapframe->s1);
      printk("a0: 0x%p\n", (void*)p->trapframe->a0);
      printk("a1: 0x%p\n", (void*)p->trapframe->a1);
    }
  } else {
    printk("%d %s: unknown sys call %d\n",
            p->pid, p->name, num);
    p->trapframe->a0 = -1;
  }
}
```
### sysproc.c
Contiene la implementación de las funciones del kernel que están asociadas a las métircas del sistema.
* **Modificaciones:** 
se implementó sys_trace() y sys_info()
```
uint64
sys_trace(void)
{
  int mask;
  argint(0, &mask);
  
  myproc()->trace_mask = mask;
  
  return 0;
}

uint64
sys_sysinfo(void)
{
  return 0;
}
```
# Integración con xv6
## Paso 1. Obtener xv6
```bash
git clone https://github.com/Taegrito/Proyecto2SistemasOperativos.git
```
## Paso 2. Copiar archivos
Copiar todos los archivos entregados dentro del directorio `user/ y kernel/`.
## Paso 3. Compilar xv6
```bash
make clean
make qemu
```
## Paso 4. Ejecutar las llamadas
```
trace sys_kill
sysinfo
```
---
# Vídeo explicativo
En el siguiente vídeo se encuentra ua explicación del funcionamiento del código
```bash
https://youtu.be/GWPUPiRvHiE
```

--- 
# Declaración de uso de IA
Durante el desarrollo del proyecto se utilizaron herramientas de inteligencia
artificial generativa como apoyo para comprensión de conceptos, revisión de
código y generación de ejemplos.Los integrantes asumen plena responsabilidad académica sobre el contenido
entregado
