#!/bin/bash

echo "[*] Instalando dependencias necesarias..."
sudo apt update
sudo apt install -y libpcap-dev qtbase5-dev qt5-qmake build-essential pkg-config

echo "[*] Listo. Ahora puedes compilar con:"
echo "    make"
