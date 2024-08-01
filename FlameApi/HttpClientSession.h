#pragma once


#include "ClientSession.h"



class HttpClientSession : public ClientSession
{
public:
	HttpClientSession(SOCKET skt);
private:
public:
	/// <summary>
	/// http �� send data
	/// </summary>
	virtual int sendData() override;
};