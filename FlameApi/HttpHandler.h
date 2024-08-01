#pragma once
#include "HttpRequest.h"

class HttpHandler
{
public:
	HttpHandler();
	~HttpHandler();
private:
	/// <summary>
	/// send buff
	/// </summary>
	std::string _sendStr;

	/// <summary>
	/// http req struct
	/// </summary>
	HttpRequest httpReq;
public:
	
	/// <summary>
	/// 解析封包資料
	/// </summary>
	void parser(char* pBuff);

	/// <summary>
	/// 新增回傳字串
	/// </summary>
	void AddStr(std::string);

	/// <summary>
	/// 取得HttpRequest
	/// </summary>
	HttpRequest* GetHttpRequest();

	/// <summary>
	/// make http response send str
	/// </summary>
	std::string& makeResponse();
};