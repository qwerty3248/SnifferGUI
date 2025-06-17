#pragma once // en vez del #ifndef, #define, #endif
#include <string>
#include <vector>

struct PacketInfo {
    std::string srcIP; // dirección IP de origen
    std::string dstIP; // dirección IP de destino
    std::string protocol; // protocolo 
    int length; // tamaño del paquete
};

std::vector<PacketInfo> capturePackets(int maxPackets = 10);
