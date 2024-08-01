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
	/// 複寫recvHandle, 執行http流程
	/// </summary>
	virtual void recvHandle(ClientSession* pSession, char* pBuff, int recvCount) override;

	/// <summary>
	/// make http client session
	/// </summary>
	virtual std::shared_ptr<ClientSession> makeClientSession(SOCKET skt) override;

	/// <summary>
	/// 註冊的處裡cb map
	/// </summary>
	std::unordered_map<std::string, HttpCallBack> _callBackMap;
public:
	/// <summary>
	/// 註冊get cd
	/// </summary>
	void Get(std::string suburl, HttpCallBack cb);

	/// <summary>
	/// http用啟動server
	/// </summary>
	virtual bool start(int port) override;
};