#include "csapp.h"

/* IP socket address structure */
struct sockaddr_in {
    uint16_t        sin_family;     /* Protocol family (always AF_INET) */
    uint16_t        sin_port;       /* Port number in network byte order */
    struct in_addr  sin_addr;       /* IP address in network byte order */
    unsigned char   sin_zero[8]     /* Pad to sizeof(struct sockaddr) */
};

/* Generic socket address structure (for connect, bind, and accept) */
struct sockaddr {
    uint16_t        sa_family;      /* Protocol family */
    char            sa_data[14];    /* Address data */
};
