# faseB — Simulador de Granja en PIC18

Proyecto embebido para microcontrolador **PIC18** desarrollado con **MPLAB X IDE**. Implementa un juego/simulador de granja en hardware real, con comunicación serie, pantalla LCD, EEPROM y temporización cooperativa sin RTOS.

---

## Capturas de pantalla

> Coloca las imágenes en una carpeta `screenshots/` dentro del proyecto y enlázalas aquí.

| Descripción | Imagen |
|---|---|
| Pantalla LCD durante el juego | *(añadir captura)* |
| Montaje del hardware | *(añadir captura)* |
| Interfaz serie / terminal | *(añadir captura)* |

Para añadir una captura:
1. Crea la carpeta `screenshots/` en la raíz del proyecto.
2. Copia tu imagen allí (p.ej. `screenshots/lcd_juego.png`).
3. Sustituye `*(añadir captura)*` por `![descripción](screenshots/lcd_juego.png)`.

---

## Hardware objetivo

| Componente | Detalle |
|---|---|
| Microcontrolador | PIC18 (oscilador HSPLL) |
| Comunicación | UART 9600 baudios (TTL) |
| Pantalla | LCD 2×16 (interfaz 4 bits, puerto D) |
| Memoria | EEPROM interna |
| Entradas | Botón selector, ADC, pin TRISC1 |
| Salidas | LEDs (heartbeat), LATC0, LATA3/A4 |

---

## Arquitectura del firmware

El sistema usa **multitarea cooperativa basada en motores**: cada módulo expone una función `motor*()` que se llama cíclicamente desde el bucle principal (`main.c`). No hay RTOS.

```
main()
 ├─ motorDataTime()      — reloj interno (día/mes/hora/min/seg)
 ├─ motorSIO()           — envío UART
 ├─ motorADC()           — lectura analógica
 ├─ motorRecieveCommand()— recepción de comandos serie
 ├─ motorParseCommand()  — decodificación y ejecución de comandos
 ├─ motorFarm()          — creación y gestión de animales
 ├─ motorSIORecieve()    — buffer de recepción TTL
 ├─ motorSIOSend()       — buffer de envío TTL
 ├─ motorGame()          — máquina de estados del juego
 ├─ motorInitialize()    — inicialización vía comando 'I'
 ├─ motorProducts()      — producción de recursos
 ├─ motorEEprom()        — escritura/lectura EEPROM
 ├─ motorButton()        — lectura del botón selector
 ├─ motorHeartBeat()     — parpadeo LED de vida
 └─ MotorLCD()           — visualización en pantalla
```

---

## Módulos principales

| Archivo | Responsabilidad |
|---|---|
| `main.c` | Punto de entrada, configuración de puertos, interrupciones y timers |
| `game.c/h` | Estado global del juego (inicio, condiciones de arranque) |
| `FARM.c/h` | Gestión de animales (creación, nombre de granja, tiempos) |
| `PRODUCTS.c/h` | Generación y consumo de productos por tipo de animal |
| `INITIALIZE.c/h` | Parsing del comando de inicialización (nombre + tiempos) |
| `DO_COMMAND.c/h` | Dispatcher de comandos serie |
| `COMMANDS.c/h` | Buffer y detección de comandos entrantes |
| `SIO2.c/h` | Driver UART (TX/RX con cola de mensajes) |
| `ADC2.c/h` | Driver ADC |
| `TIMER2.c/h` | Pool de 19 temporizadores software (tics) |
| `DATA_TIME.c/h` | Reloj en tiempo real por software |
| `EEPROM.c/h` | Persistencia de animales y su estado (despierto/dormido) |
| `LcTLCD.c/h` | Driver LCD y cola de notificaciones |
| `LED2.c/h` | Control de LEDs y heartbeat |
| `SELECT_BUTTON.c/h` | Gestión del botón de selección |
| `TTL_MANUAL_SEND/RECIEVE.c/h` | Comunicación TTL manual |

---

## Animales y productos

| Tipo | ID | Producto | Acumulación |
|---|---|---|---|
| Vaca (COW) | 0 | Llet (leche) | hasta 255 |
| Porc (PIG) | 1 | Pernil (jamón) | hasta 255 |
| Cavall (HORSE) | 2 | Pinzells (cepillos) | hasta 255 |
| Gallina (CHICKEN) | 3 | Huevos | hasta 255 |

- Máximo **24 animales** en total, con mínimo 3 de cada tipo si hay espacio.
- Los animales pueden pasar a estado **dormido** (dejan de producir).
- En modo **rebelión** ningún animal produce.

---

## Protocolo de comandos (UART)

Todos los comandos se envían como cadena de texto por el puerto serie.

| Comando | Código | Descripción |
|---|---|---|
| Inicializar | `I<nombre>$<t0>$<t1>$<t2>$<t3>\r` | Establece nombre de granja y tiempos de producción |
| Obtener animales | `A` | Devuelve lista de animales con tipo, número y estado |
| Obtener productos | `P` | Devuelve cantidades de los 4 productos |
| Consumir | `C<tipo>` | Consume recursos (0–3 según tabla) |
| Poner a dormir | `E<tipo>$<num>` | Pone a dormir un animal concreto |
| Rebelión (iniciar) | `L` | Activa rebelión (los animales no producen) |
| Rebelión (parar) | `S` | Desactiva rebelión |
| Reset | `R` | Reinicia toda la granja al estado inicial |

### Tipos en el comando `C` (consumo)

| Valor | Consume |
|---|---|
| 0 | 1 huevo (gallina) |
| 1 | 1 huevo + 1 pernil |
| 2 | 2 llets (vaca) |
| 3 | 2 pinzells (caballo) |

---

## Compilación

El proyecto usa **MPLAB X IDE** con el compilador **XC8**.

1. Abrir `faseB.X` en MPLAB X.
2. Seleccionar la configuración `default`.
3. Compilar con `Production > Build`.
4. Programar el PIC con el archivo `.hex` generado en `dist/default/production/`.

---

## Estructura del repositorio

```
faseB.X/
├── main.c
├── game.c / game.h
├── FARM.c / FARM.h
├── PRODUCTS.c / PRODUCTS.h
├── INITIALIZE.c / INITIALIZE.h
├── DO_COMMAND.c / DO_COMMAND.h
├── COMMANDS.c / COMMANDS.h
├── SIO2.c / SIO2.h
├── ADC2.c / ADC2.h
├── TIMER2.c / TIMER2.h
├── DATA_TIME.c / DATA_TIME.h
├── EEPROM.c / EEPROM.h
├── LcTLCD.c / LcTLCD.h
├── LED2.c / LED2.h
├── SELECT_BUTTON.c / SELECT_BUTTON.h
├── TTL_MANUAL_SEND.c / TTL_MANUAL_SEND.h
├── TTL_MANUAL_RECIEVE.c / TTL_MANUAL_RECIEVE.h
├── Makefile
├── nbproject/          — configuración MPLAB X
├── dist/               — binarios compilados (.hex, .elf, ...)
└── screenshots/        — (añadir capturas aquí)
```

---

## Autor

**Álvaro** — Proyecto iniciado el 16 de marzo de 2026.
