#pragma once

#include <string>
#include <unordered_map>

#define GET_STR "GET"
#define POST_STR "POST"

class HttpRequest
{
public:
private:
	/// <summary>
	/// 解析一行到map中
	/// </summary>
	void parserOneLineToMap(std::string&);

	/// <summary>
	/// http req attribute map
	/// </summary>
	std::unordered_map<std::string, std::vector<std::string>> _attrMap;
public:
	/// <summary>
	/// 解析Buff
	/// </summary>
	void parser(char* pBuff);

	/// <summary>
	/// 取得http req get或post+url
	/// </summary>
	std::string getRecvHtppReqUrl();
};