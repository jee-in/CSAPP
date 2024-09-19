#include <arpa/inet.h>

/* Returns: value in network byte order */
unit32_t htonl(unit32_t hostlong);
unit16_T htons(unit16_6 hostshort);

/* Returns: value in host byte order */
unit32_t ntohl(unit32_t netlong);
unit16_6 ntohs(unit16_t netshort);