#pragma once

#ifdef _WIN32
/* See http://stackoverflow.com/questions/12765743/getaddrinfo-on-win32 */
#include <winsock2.h>
#include <Ws2tcpip.h>

#pragma comment (lib, "Ws2_32.lib")
#else
/* Assume that any non-Windows platform uses POSIX-style sockets instead. */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>  /* Needed for getaddrinfo() and freeaddrinfo() */
#include <unistd.h> /* Needed for close() */
#include <fcntl.h>
#endif

#include <vector>
#include <functional>
#include <memory>
#include <string>
#include "ClientSession.h"

#define SELECT_TIMEOUT 10

typedef void (*recvCallBack)(ClientSession* pSesssion, char* pBuff, int recvCount);

/// <summary>
/// FLAMEServer ���K�A�Ⱦ�
/// </summary>
class FLAMEServer
{
public:
	FLAMEServer();
	~FLAMEServer();
private:
	/// <summary>
	/// window socket �ݭn��l��wsa
	/// </summary>
	void InitWSA();

	/// <summary>
	/// window socket �ݭn���� wsa
	/// </summary>
	void ReleaseWSA();

	/// <summary>
	/// ����socket
	/// </summary>
	void sockClose();

	/// <summary>
	/// �]�wserver socket non block
	/// </summary>
	bool SetSocketBlockingEnabled(SOCKET fd, bool blocking);

	/// <summary>
	/// ��ť��Thread
	/// </summary>
	void ListenThread();

	/// <summary>
	/// socket�M�Ѽ�
	/// </summary>
	SOCKET _socket;
	int _family;
	int _socktype;
	int _protocol;

	/// <summary>
	/// port
	/// </summary>
	int _port;

	/// <summary>
	/// �ϥ�block �Ҧ�
	/// </summary>
	bool _useBlockSocketServer;

	/// <summary>
	/// �w�g�s�u��client
	/// </summary>
	std::vector<std::shared_ptr<ClientSession>> _clientSockts;

	/// <summary>
	/// ���U��recv call back
	/// </summary>
	std::function<void(ClientSession*,char *,int)> _recvCB; //void *_recvCB(char *pBuff)

protected:
	/// <summary>
	/// ������ƫ� �B�zfunction
	/// </summary>
	virtual void recvHandle(ClientSession *pSession, char* pBuff, int recvCount);

	/// <summary>
	/// generate client session
	/// </summary>
	virtual std::shared_ptr<ClientSession> makeClientSession(SOCKET skt);
public:
	/// <summary>
	/// �Ұ� server
	/// </summary>
	virtual bool Start(int port);

	//�]�w����CB
	void setRecvCB(recvCallBack);

	/// <summary>
	/// ����server ����
	/// </summary>
	void waitShutDown();

	/// <summary>
	/// Set Family
	/// </summary>
	void setFamily(int family);

	/// <summary>
	/// �]�wsocket type
	/// </summary>
	void setSocketType(int socktype);

	/// <summary>
	/// �]�wsocket protocal
	/// </summary>
	void setProtocol(int protocol);
};