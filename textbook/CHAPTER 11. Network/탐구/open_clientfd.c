#include "csapp.h"

int open_clientfd(char *hostname, char *port) {
    int clientfd;
    struct addrinfo hints, *listp, *p;

    /* Get a list of potential server addresses */
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_NUMERICSERV;                    // 서비스 이름은 포트 번호로
    hints.ai_flags |= AI_ADDRCONFIG;                    // IPv4인 경우에만 값을 반환
    Getaddrinfo(hostname, port, &hints, &listp);

    /* Walk the list for one that we can successfully connect to */
    for (p = listp; p; p = p->ai_next) {
        /* Create a socket descriptor */
        if ((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
            continue;

        /* Connect to the server */
        if (connect(clientfd, p->ai_addr, p->ai_addrlen) != -1)
            break;
        Close(clientfd);
    }

    /* Clean up */
    Freeaddrinfo(listp);
    if (!p)3
        return -1;
    else
        return clientfd;
}