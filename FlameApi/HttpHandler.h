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
	/// �ѪR�ʥ]���
	/// </summary>
	void parser(char* pBuff);

	/// <summary>
	/// �s�W�^�Ǧr��
	/// </summary>
	void AddStr(std::string);

	/// <summary>
	/// ���oHttpRequest
	/// </summary>
	HttpRequest* GetHttpRequest();

	/// <summary>
	/// make http response send str
	/// </summary>
	std::string& makeResponse();
};