- 응용 계층
    - 예시) 메신저 - subscrib/notifs?
- TCP
    - 접속 설정 기능
    - 정확한 데이터 전송 기능
    - 접속 종료 기능
- ?
    - 라우팅 기능
    - Store-and-Forward (IP)
    - Lan Card Driver
- ?
    - 통신 선로(미디어) 접근 기능

프로세스 간 통신 메커니즘
(1) 파이프 (pipe)
하나의 프로세스가 같은 컴퓨터에 있는 다른 프로세스와 통신하는 방법이다.
모니터에 결과화면이 나오는 것이 아니라 다른 프로세스에게 전달하는 것이다.
write, read - read, write

(2) 소켓 (socket)
프로세스를 전구라고 한다면 여기에 전기(data)를 흘려보내야 하는데
전구에 전기를 통하게 하기 위해서는 소켓에 전기(data)를 꽂아줘야 한다.

(3) 유닉스 도메인 (Unix Domain)
/tmp/echo
동일한 컴퓨터에서도 가능하고 유닉스끼리도 가능함

```
ps -ef
grep ? /etc/passwd // 검색어 경로 -> 패턴 매칭 명령어
```

화면에 바로 출력되게 하는 것이 아니라 grep이라는 프로세스에 출력하게 하는 것이다.
ps -ef와 grep sunchoi가 통신을 하는 것이다.

소켓이란?
동일 컴퓨터에서 사용할 수도 있고 원격의 컴퓨터와 통신할 수도 있다.
소켓 인터페이스를 이용하여 원격의 컴퓨터의 네트워크 정보, 호스트 정보, 프로세스 정보를 알아서 통신을 해야 한다.

현재 모든 인터넷의 응용 프로세스는 바로 소켓을 이용하여 통신을 하게 된다.

공통 통신 규약을 두어 통신을 한다.
UDP/TCP(정확한 통신) - IP(라우터가 담당) - 라우팅 테이블(최적의 경로 찾기) - IP 주소->Ethernet ? (ASRP)

---
- socket(): system call. 운영체제가 알아서 함.  

- connect(): 접속 설정 요청
- bind(): 소켓에 이름 주기
- listen(): 접속 설정 요청 대기 수
- accept(): 접속 설정이 완료되면 알림 요청

---

- send(): 데이터 전송
- receive(): 데이터 수신
- write(): 데이터 전송
- read(): 데이터 수신

---
- close()  

---
- select(): 어떤 소켓에 이벤트 도착했는지 기다림
---

TCP는 비서, 매개체와 같은 기능을 한다.
bind, listen, accept는 서버에만 있는 기능이다.

TCP 기능

- 접속 설정 요청

    - 
- 정확한 데이터 전송
- 접속 해제 요청

---

에코 클라이언트-에코 서버의 통신

tcpechoc ice.anyang.ac.kr 8888
tcpechos 8888
