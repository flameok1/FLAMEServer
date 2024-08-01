#pragma once


#include "ClientSession.h"



class HttpClientSession : public ClientSession
{
public:
	HttpClientSession(SOCKET skt);
private:
public:
	/// <summary>
	/// http ¥Î send data
	/// </summary>
	virtual int sendData() override;
};