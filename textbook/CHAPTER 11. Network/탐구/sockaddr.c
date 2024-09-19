#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main() {
    struct sockaddr_in addr_in;
    struct sockaddr addr;

    // IPv4 주소와 포트 번호 설정
    addr_in.sin_family = AF_INET;
    addr_in.sin_port = htons(8080);              // 포트 번호를 네트워크 바이트 순서로 변환
    addr_in.sin_addr.s_addr = inet_addr("192.168.1.1"); // IP 주소를 네트워크 바이트 순서로 변환

    // sockaddr 구조체에 sockaddr_in의 데이터를 복사
    memcpy(&addr, &addr_in, sizeof(addr_in));

    // sockaddr 구조체의 sa_data에 대한 정보를 출력
    printf("sa_data[0] = %02x\n", (unsigned char)addr.sa_data[0]);
    printf("sa_data[1] = %02x\n", (unsigned char)addr.sa_data[1]);
    printf("sa_data[2] = %02x\n", (unsigned char)addr.sa_data[2]);
    printf("sa_data[3] = %02x\n", (unsigned char)addr.sa_data[3]);
    printf("sa_data[4] = %02x\n", (unsigned char)addr.sa_data[4]);
    printf("sa_data[5] = %02x\n", (unsigned char)addr.sa_data[5]);
    printf("sa_data[6] = %02x\n", (unsigned char)addr.sa_data[6]);
    printf("sa_data[7] = %02x\n", (unsigned char)addr.sa_data[7]);
    printf("sa_data[8] = %02x\n", (unsigned char)addr.sa_data[8]);
    printf("sa_data[9] = %02x\n", (unsigned char)addr.sa_data[9]);
    printf("sa_data[10] = %02x\n", (unsigned char)addr.sa_data[10]);
    printf("sa_data[11] = %02x\n", (unsigned char)addr.sa_data[11]);
    printf("sa_data[12] = %02x\n", (unsigned char)addr.sa_data[12]);
    printf("sa_data[13] = %02x\n", (unsigned char)addr.sa_data[13]);

    return 0;
}
