#include "HttpClientSession.h"

HttpClientSession::HttpClientSession(SOCKET skt)
	:ClientSession(skt)
{

}

int HttpClientSession::sendData()
{
	int nsend = ClientSession::sendData();

	if (nsend > 0)
	{
		_isNeedClose = true;
	}


	return nsend;
}