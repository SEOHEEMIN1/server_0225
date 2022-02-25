#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{

	WSAData wsaData;

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET Serversocket;

	Serversocket = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN Serveraddr;

	memset(&Serveraddr, 0, sizeof(Serveraddr));

	Serveraddr.sin_family = AF_INET;
	Serveraddr.sin_port = htons(50000);
	Serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

	bind(Serversocket, (SOCKADDR*)&Serveraddr, sizeof(Serveraddr));

	listen(Serversocket, 0);

	SOCKADDR_IN Clientaddr;
	int ClientaddrSize = sizeof(Clientaddr);
	SOCKET ClientSocket = 0;
	ClientSocket = accept(Serversocket, (SOCKADDR*)&Clientaddr, &ClientaddrSize);

	char Message[] = "Hello World";
	send(ClientSocket, Message, strlen(Message) + 1, 0);

	closesocket(ClientSocket);
	closesocket(Serversocket);

	WSACleanup();

}