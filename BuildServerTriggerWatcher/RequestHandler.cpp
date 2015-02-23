#include "RequestHandler.h"
#ifdef _DEBUG
#include <iostream>
#endif
#include "build.h"

RequestHandler::RequestHandler()
{
}


RequestHandler::~RequestHandler()
{
}

void RequestHandler::HandleData(JarvisSS::JarvisServer::DataHandlerParams* pdhp)
{
	std::string strRaw(std::string((char*)pdhp->pbBuf));
#ifdef _DEBUG
	std::cout << strRaw;
	std::string strT("echo " + strRaw);
	strT.append(" > c:\\POST_message.txt");
	system(strT.c_str());
#endif

	// if we should, kick off the build
	if (FOriginRepoFromSzHTTPHeader(std::string(strRaw)))
	{
		std::string strResponse = std::string("HTTP/1.0 200 OK\nContent-Type: text/html; charset=utf-8\nContent-Length: 0\nConnection : close \n\n");
		pdhp->pjsock->FSend(strResponse.c_str(), strResponse.length());
		Build(strRaw);	
	}
	else
	{
		system(std::string("echo ").append(strRaw).append(" >> C:\\buildrequestfail.txt").c_str());
	}
}

bool RequestHandler::FOriginRepoFromSzHTTPHeader(const std::string& strrequest)
{
	std::string strrequestLower = strrequest;

	// lowercase everything
	for (unsigned int i = 0; i < strrequest.length(); i++)
	{
		strrequestLower[i] = tolower(strrequestLower[i]);
	}
	
	// this is the best algorithm I have at the moment. No POST embedded verification. Makes me sad. This will have to do for now.
	return strrequestLower.find("projectavian") != std::string::npos;
}
