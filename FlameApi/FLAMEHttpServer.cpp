#include "FLAMEHttpServer.h"
#include "HttpClientSession.h"


FLAMEHttpServer::FLAMEHttpServer()
{

}


FLAMEHttpServer::~FLAMEHttpServer()
{

}

void FLAMEHttpServer::Get(std::string suburl, HttpCallBack cb)
{

	_callBackMap.insert({ GET_STR+suburl, cb });
}

void FLAMEHttpServer::recvHandle(ClientSession* pSession, char* pBuff, int recvCount)
{
	//parser
	HttpHandler handle;
	handle.parser(pBuff);

	std::string callBackSearchStr = handle.GetHttpRequest()->getRecvHtppReqUrl();

	if (_callBackMap.count(callBackSearchStr) > 0)
	{
		_callBackMap[callBackSearchStr](&handle);
	}
	else
	{
		printf("unhandle http request ******\n%s\n*****\n", pBuff);
	}

	pSession->addBuff(handle.makeResponse().c_str());
}

std::shared_ptr<ClientSession> FLAMEHttpServer::makeClientSession(SOCKET skt)
{
	return std::make_shared<HttpClientSession>(skt);
}

bool FLAMEHttpServer::start(int port)
{
	return FLAMEServer::start(port);
}