#pragma once
#include "..\JarvisServerAndSocketLibrary\JarvisServerAndSocketLibrary\JarvisServerAndSocketLibrary.h"

class RequestHandler :
	public JarvisSS::IDataHandler
{
public:
	RequestHandler();
	~RequestHandler();

	void HandleData(JarvisSS::JarvisServer::DataHandlerParams* pdhp);

private:
	bool FOriginRepoFromSzHTTPHeader(const std::string& strrequest);
	std::string SzCommandLineArg(std::string& strPostData);
	std::string SzCommand(std::string& strPostData);
	static std::string StrUnescapeHTTP(std::string strUnescaped);
};

