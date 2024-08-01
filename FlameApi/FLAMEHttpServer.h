#pragma once
#include "FLAMEServer.h"
#include "HttpHandler.h"





typedef void (*HttpCallBack)(HttpHandler*);

class FLAMEHttpServer : public FLAMEServer
{
public:
	FLAMEHttpServer();

	~FLAMEHttpServer();
private:
	
	

protected:
	/// <summary>
	/// �ƼgrecvHandle, ����http�y�{
	/// </summary>
	virtual void recvHandle(ClientSession* pSession, char* pBuff, int recvCount) override;

	/// <summary>
	/// make http client session
	/// </summary>
	virtual std::shared_ptr<ClientSession> makeClientSession(SOCKET skt) override;

	/// <summary>
	/// ���U���B��cb map
	/// </summary>
	std::unordered_map<std::string, HttpCallBack> _callBackMap;
public:
	/// <summary>
	/// ���Uget cd
	/// </summary>
	void Get(std::string suburl, HttpCallBack cb);

	/// <summary>
	/// http�αҰ�server
	/// </summary>
	virtual bool start(int port) override;
};