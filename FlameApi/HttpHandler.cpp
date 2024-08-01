#include "HttpHandler.h"
#include <stdexcept>
#include <memory>

HttpHandler::HttpHandler()
	:_sendStr("")
{

}

HttpHandler::~HttpHandler()
{

}

void HttpHandler::parser(char* pBuff)
{
	httpReq.parser(pBuff);
}

void HttpHandler::AddStr(std::string sendStr)
{
	_sendStr += sendStr;
}

HttpRequest* HttpHandler::GetHttpRequest()
{
	return &httpReq;
}

std::string& HttpHandler::makeSendStr()
{
	int len = (int)_sendStr.length();

	int size_s = std::snprintf(nullptr, 0, "HTTP/1.1 200 OK\r\nContent-Type: text/html;charset=UTF-8\r\nContent-Length: %d\r\n\r\n%s", len, _sendStr.c_str());

	if (size_s <= 0)
	{ 
		throw std::runtime_error("Error during formatting."); 
	}

	std::unique_ptr<char[]> buf(new char[size_s + 1]);
	std::snprintf(buf.get(), size_s + 1, "HTTP/1.1 200 OK\r\nContent-Type: text/html;charset=UTF-8\r\nContent-Length: %d\r\n\r\n%s", len, _sendStr.c_str());

	_sendStr = std::string(buf.get(), buf.get() + size_s);
	return _sendStr;
}