#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <Windows.h>
#include <WinSock2.h>
using namespace std;

// #pragma comment(lib, "ws2_32.lib")
int main()
{
	// ∆Ù∂Øsocket
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);
	
	// «Â¿Ìsocket
	WSACleanup();
	return 0;
}