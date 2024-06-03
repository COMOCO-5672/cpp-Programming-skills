#include <iostream>
#include <chrono>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// NTP服务器地址（可根据需要更改）
#define NTP_SERVER "pool.ntp.org"
// NTP协议端口
#define NTP_PORT 123
// NTP协议数据包大小
#define NTP_PACKET_SIZE 48
// NTP协议时间戳偏移量（以1900年为起始）
#define NTP_TIMESTAMP_OFFSET 2208988800ull

// NTP协议数据包结构
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
    int sockfd;
    struct sockaddr_in server_addr;
    ntp_packet packet;

    // 创建 UDP 套接字
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // 设置 NTP 服务器地址和端口
    std::memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(NTP_PORT);
    if (inet_pton(AF_INET, NTP_SERVER, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        close(sockfd);
        return 1;
    }

    // 设置 NTP 协议数据包
    std::memset(&packet, 0, sizeof(packet));
    packet.li_vn_mode = 0x1B; // NTP 版本号 4、客户端模式、UDP
    packet.transmit_timestamp_sec = htonl(time(NULL) + NTP_TIMESTAMP_OFFSET);

    // 向 NTP 服务器发送数据包
    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("sendto");
        close(sockfd);
        return 1;
    }

    // 接收 NTP 服务器返回的数据包
    if (recv(sockfd, &packet, sizeof(packet), 0) < 0) {
        perror("recv");
        close(sockfd);
        return 1;
    }

    // 关闭套接字
    close(sockfd);

    // 解析 NTP 协议返回的时间戳
    uint32_t ntp_timestamp = ntohl(packet.transmit_timestamp_sec) - NTP_TIMESTAMP_OFFSET;

    // 打印校准后的本地时间
    std::time_t local_time = ntp_timestamp;
    std::cout << "NTP 校准后的本地时间: " << std::ctime(&local_time) << std::endl;

    return 0;
}
