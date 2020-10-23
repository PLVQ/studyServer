#define WIN32_LEAN_AND_MEAN
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <WinSock2.h>
using namespace std;

// #pragma comment(lib, "ws2_32.lib")
int main()
{
	// ����socket
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);
	
	// 1.����һ��socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	// 2.bind
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(8888);
	_sin.sin_addr.S_un.S_addr = INADDR_ANY; // inet_addr("127.0.0.1");
	if (bind(_sock, (sockaddr*)&_sin, sizeof(_sin)) == SOCKET_ERROR) {
		cout << "��ʧ��!" << endl;
	}
	else {
		cout << "�󶨳ɹ�!" << endl;
	}

	// 3.listen
	if (SOCKET_ERROR == listen(_sock, 5)) {
		cout << "��ʧ��!" << endl;
	}
	else {
		cout << "�󶨳ɹ�!" << endl;
	}

	// 4.accept
	sockaddr_in clientAddr = {};
	int nAddrLen = sizeof(sockaddr_in);
	SOCKET _cSock = INVALID_SOCKET;
	while (true) {
		_cSock = accept(_sock, (sockaddr*)&clientAddr, &nAddrLen);
		if (_cSock == INVALID_SOCKET) {
			cout << "error" << endl;
		}

		cout << "new client join!" << inet_ntoa(clientAddr.sin_addr) << endl;

		// 5.send
		char msgBuff[] = "hello, i'm server.";
		send(_cSock, msgBuff, strlen(msgBuff) + 1, 0);
	}

	// 6.close socket
	closesocket(_sock);
	// ����socket
	WSACleanup();
	return 0;
}