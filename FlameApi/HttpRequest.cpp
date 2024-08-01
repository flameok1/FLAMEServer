#include "HttpRequest.h"



void HttpRequest::parser(char* pBuff)
{
	std::string buffStr = pBuff;

	if (buffStr.find(GET_STR, 0) == 0)
	{
		//Get
	}
	else if (buffStr.find(POST_STR, 0) == 0)
	{

	}

	size_t startPos = 0;
	size_t pos = 0;
	while (true)
	{
		pos = buffStr.find('\n', startPos);
		if (pos == std::string::npos)
		{
			if (startPos == buffStr.length())
				break;

			pos = buffStr.length();
		}
		std::string oneLine = buffStr.substr(startPos, pos - startPos);
		while (oneLine.length() > 0 && oneLine.back() == '\r')
		{
			oneLine.pop_back();
		}
		parserOneLineToMap(oneLine);
		if (pos == buffStr.length())
		{
			break;
		}
		startPos = pos + 1;
	}
}

void HttpRequest::parserOneLineToMap(std::string& oneline)
{
	if (oneline.length() == 0)
		return;

	size_t startPos = 0;
	size_t pos = oneline.find(' ', startPos);
	std::string titleStr = oneline.substr(startPos, pos - startPos);
	_attrMap.insert({ titleStr , std::vector<std::string >() });
	startPos = pos + 1;
	while (true)
	{
		pos = oneline.find(' ', startPos);
		if (pos == std::string::npos)
		{
			if (startPos == oneline.length())
				break;

			pos = oneline.length();
		}
		std::string newArrtStr = oneline.substr(startPos, pos - startPos);
		_attrMap[titleStr].push_back(newArrtStr);
		if (pos == oneline.length())
		{
			break;
		}
		startPos = pos + 1;
	}
}

std::string HttpRequest::getRecvHtppReqUrl()
{
	if (_attrMap.count(GET_STR) > 0)
	{
		return GET_STR + _attrMap[GET_STR][0];
	}
	else if (_attrMap.count(POST_STR) > 0)
	{
		return POST_STR + _attrMap[GET_STR][0];
	}

	return "";
}

