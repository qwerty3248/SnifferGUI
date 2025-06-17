# SnifferGUI

## Descripción

### ¿Qué es un sniffer?

Un sniffer es una herramienta que permite capturar y analizar el tráfico de red que pasa por una interfaz de red. Se usa frecuentemente en redes para diagnóstico, monitoreo de seguridad y aprendizaje de protocolos de red.

**SnifferGUI** es una aplicación de análisis de tráfico de red (sniffer) desarrollada en **C++** con una interfaz gráfica utilizando **Qt5**. Usa la biblioteca **libpcap** para capturar paquetes en tiempo real y los muestra en una interfaz amigable.

Este proyecto tiene fines didácticos para entender cómo funcionan las herramientas de captura de paquetes y cómo integrarlas con una interfaz gráfica moderna en C++.

---

## Autor

**Jesús Losada Arauzo**  
Escuela Técnica Superior de Ingenierías Informática y de Telecomunicación  
Universidad de Granada

---

## Características

- Captura de tráfico en tiempo real desde una interfaz de red.
- Interfaz gráfica con Qt5 para mostrar los paquetes.
- Separación clara entre lógica de captura y presentación.
- Código modular y fácil de mantener.

---

## Estructura del proyecto

``` plaintext
.
├── include/ # Cabeceras del proyecto
│ ├── gui.hpp # Declaración de la GUI (clase Qt)
│ └── sniffer.hpp # Declaración del sniffer (captura con libpcap)
├── src/ # Código fuente del proyecto
│ ├── gui.cpp # Implementación de la GUI
│ ├── main.cpp # Punto de entrada de la aplicación
│ └── sniffer.cpp # Implementación del sniffer (libpcap)
├── setup.sh # Script para instalar dependencias
├── Makefile # Archivo de compilación
├── LICENSE # Licencia (si quieres añadir una)
└── README.md # Este archivo

```

---

## Requisitos

Antes de compilar necesitas tener instaladas las siguientes dependencias:

- `g++` con soporte para C++17 o superior.
- `make`
- `libpcap-dev`
- `qt5-default` y `qtbase5-dev`
- `qttools5-dev-tools` (para `moc`)
- `pkg-config`

---

## Instalación de dependencias

### Opción 1: Manual

```bash
sudo apt update
sudo apt install -y g++ make libpcap-dev qt5-default qtbase5-dev qttools5-dev-tools pkg-config

```

### Opción 2: Script

```bash
chmod +x setup.sh
./setup.sh
```
---

## Compilación

```bash
make
make clean # para limpiar los archivos generados
```
---

## Uso

Para ejecutar la aplicación, simplemente ejecuta:

```bash
sudo ./sniffer_app
```
---
