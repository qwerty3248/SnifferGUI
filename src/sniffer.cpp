#include "../include/sniffer.hpp"
#include <pcap.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>

using namespace std;

vector<PacketInfo> capturePackets(int maxPackets) {
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live("any", BUFSIZ, 1, 1000, errbuf);
    if (!handle) {
        cerr << "Error abriendo interfaz: " << errbuf << endl;
        return {};
    }

    vector<PacketInfo> packets;

    for (int i = 0; i < maxPackets; ++i) {
        struct pcap_pkthdr header;
        const u_char *data = pcap_next(handle, &header);
        if (!data) continue;

        const struct ip *ip_hdr = (struct ip*)(data + 14); // ethernet offset
        PacketInfo pkt;
        pkt.srcIP = inet_ntoa(ip_hdr->ip_src);
        pkt.dstIP = inet_ntoa(ip_hdr->ip_dst);
        pkt.protocol = to_string(ip_hdr->ip_p); // opcional: traducir a texto
        pkt.length = header.len;

        packets.push_back(pkt);
    }

    pcap_close(handle);
    return packets;
}
