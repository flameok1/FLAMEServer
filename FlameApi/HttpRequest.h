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
	/// �ѪR�@���map��
	/// </summary>
	void parserOneLineToMap(std::string&);

	/// <summary>
	/// http req attribute map
	/// </summary>
	std::unordered_map<std::string, std::vector<std::string>> _attrMap;
public:
	/// <summary>
	/// �ѪRBuff
	/// </summary>
	void parser(char* pBuff);

	/// <summary>
	/// ���ohttp req get��post+url
	/// </summary>
	std::string getRecvHtppReqUrl();
};