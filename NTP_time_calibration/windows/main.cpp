#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdint>
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

#define NTP_SERVER "time.windows.com"
#define NTP_PORT 123
#define NTP_PACKET_SIZE 48
#define NTP_TIMESTAMP_OFFSET 2208988800ull

typedef struct {
    uint8_t li_vn_mode;
    uint8_t stratum;
    uint8_t poll;
    uint8_t precision;
    uint32_t root_delay;
    uint32_t root_dispersion;
    uint32_t reference_identifier;
    uint32_t reference_timestamp_sec;
    uint32_t reference_timestamp_frac;
    uint32_t originate_timestamp_sec;
    uint32_t originate_timestamp_frac;
    uint32_t receive_timestamp_sec;
    uint32_t receive_timestamp_frac;
    uint32_t transmit_timestamp_sec;
    uint32_t transmit_timestamp_frac;
} ntp_packet;

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return 1;
    }

    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd == INVALID_SOCKET) {
        std::cerr << "socket failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    struct addrinfo hints, *result = NULL;
    std::memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;

    if (getaddrinfo(NTP_SERVER, NULL, &hints, &result) != 0) {
        std::cerr << "getaddrinfo failed" << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    struct sockaddr_in server_addr;
    std::memcpy(&server_addr, result->ai_addr, result->ai_addrlen);
    server_addr.sin_port = htons(NTP_PORT);

    ntp_packet packet;
    std::memset(&packet, 0, sizeof(packet));
    packet.li_vn_mode = 0x1B;
    packet.transmit_timestamp_sec = htonl(time(NULL) + NTP_TIMESTAMP_OFFSET);

    if (sendto(sockfd, (const char*)&packet, sizeof(packet), 0, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        std::cerr << "sendto failed: " << WSAGetLastError() << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    if (recv(sockfd, (char*)&packet, sizeof(packet), 0) == SOCKET_ERROR) {
        std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    closesocket(sockfd);
    WSACleanup();

    uint32_t ntp_timestamp = ntohl(packet.transmit_timestamp_sec) - NTP_TIMESTAMP_OFFSET;
    std::cout << "NTP time span: " << ntp_timestamp << std::endl;
    std::time_t local_time = ntp_timestamp;
    std::cout << "NTP timestamp: " << std::ctime(&local_time) << std::endl;

    return 0;
}
