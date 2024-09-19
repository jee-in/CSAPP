#include "csapp.h"

int main(int argc, char **argv)
{
    int clientfd;
    char *host, *port, buf[MAXLINE];
    rio_t rio;


    if (argc != 3) {
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(0);
    }
    host = argv[1];
    port = argv[2];

    clientfd = Open_clientfd(host, port);
    Rio_readinitb(&rio, clientfd);                  // 인자: RIO를 위한 사용자 정의 구조체 포인터, 파일 디스크립터(식별자)

    /* rio_readinitb 함수
     * 소켓이나 파일에서 효율적인 버퍼링된 읽기(read)를 수행하기 위해 사용되는 초기화 함수입니다. 
     * 주로 Robust I/O (RIO) 패키지에서 제공되며, 소켓 프로그래밍에서 많이 사용됩니다. 
     * rio_readinitb는 읽기 연산을 최적화하고, 네트워크나 파일 입출력 시의 성능을 향상시키기 위해 큰 데이터를 작은 청크로 나누어 버퍼에 저장한 후 이를 처리합니다.
    */

    while (Fget(buf, MAXLINE, stdin) != NULL) {
        Rio_written(clientfd, buf, strlen(buf));
        Rio_readlineb(&rio, buf, MAXLINE);
        Fputs(buf, stdout);
    }

    /*
     * fgets 함수
     * C 표준 라이브러리에서 제공되는 함수로, 파일에서 문자열을 읽어오는 기능을 합니다. 
     * 이 함수는 파일 포인터를 통해 텍스트 파일로부터 한 줄씩 데이터를 읽고, 이를 문자열로 저장합니다.

     * char *fgets(char *str, int n, FILE *stream);
     * 파라미터:
        * char *str: 데이터를 저장할 버퍼. 읽어온 문자열이 저장되는 곳입니다.
        * int n: 읽어올 최대 문자 수. 이 값은 버퍼 크기를 나타내며, 최대 n-1개의 문자가 읽히고 마지막에 널 종결 문자(\0)가 추가됩니다.
        * FILE *stream: 읽기를 수행할 파일 포인터입니다. 이 포인터는 보통 fopen 함수로 파일을 열 때 반환됩니다.
    * 반환값:
        * 읽어온 문자열을 저장한 char *str 포인터를 반환합니다.
        * 만약 파일의 끝에 도달하거나 에러가 발생하면 NULL을 반환합니다.
    * 동작 방식:
        * fgets는 파일에서 최대 n-1개의 문자를 읽고, 이를 str에 저장합니다.
        * 줄바꿈 문자를(\n) 만나면 읽기를 중단하고, 그 줄바꿈 문자도 포함하여 버퍼에 저장합니다.
        * 읽은 후, 마지막에 널 종결 문자(\0)를 자동으로 추가합니다.
        * 파일의 끝에 도달하거나 에러가 발생하면 NULL을 반환합니다.
    */

   /*
    * rio_written 함수
    * 소켓 또는 파일에 데이터를 안전하게 쓰기 위한 함수입니다. 
    * 이 함수는 Robust I/O (RIO) 패키지에서 제공되며, 
    * 네트워크 통신이나 파일 입출력 시 비정상적인 상황에서 데이터가 덜 쓰이는 문제를 방지하고, 
    * 정확한 양의 데이터를 쓸 수 있도록 도와줍니다.

    * ssize_t rio_written(int fd, void *usrbuf, size_t n);
    * 인자 설명:
        * int fd: 데이터를 쓸 파일이나 소켓의 파일 디스크립터. fd는 네트워크 소켓 또는 파일과 연결되어 있습니다.
        * void *usrbuf: 사용자 버퍼로부터 데이터를 가져와서 fd에 쓰게 됩니다. 즉, 여기에 쓰고자 하는 데이터를 저장해둡니다.
        * size_t n: 쓰고자 하는 데이터의 크기. 버퍼에서 n 바이트만큼 데이터를 fd에 씁니다.

반환값:
성공: 실제로 쓴 바이트 수를 반환합니다.
실패: 오류가 발생하면 -1을 반환합니다.
주요 특징:
안전한 쓰기: 기본적인 write 함수는 여러 이유로 지정한 바이트 수만큼 데이터를 모두 쓰지 못할 수 있습니다. 예를 들어, 네트워크 문제가 발생했거나 파일 디스크립터의 상태에 따라 부분적인 쓰기만 이루어질 수 있습니다. rio_written 함수는 write가 덜 쓴 바이트 수만큼 계속해서 쓰기를 시도하여, 모든 데이터를 완전히 쓸 때까지 반복합니다.

네트워크 통신에서 유용: 소켓 통신 시 네트워크 상태에 따라 쓰기 작업이 제대로 완료되지 않을 수 있기 때문에, rio_written을 사용하면 이러한 문제를 방지할 수 있습니다.


   */

    Close(clientfd);
    exit(0);
}