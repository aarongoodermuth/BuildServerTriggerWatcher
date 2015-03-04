#pragma once
#include "..\JarvisServerAndSocketLibrary\JarvisServerAndSocketLibrary\JarvisServerAndSocketLibrary.h"
/*#ifdef _DEBUG
#pragma comment(lib, "C:\\Users\\aviantest\\documents\\visual studio 2013\\Projects\\BuildServerTriggerWatcher\\Debug\\JarvisServerAndSocketLibrary.lib")
#else
#pragma comment(lib, "C:\\Users\\aviantest\\documents\\visual studio 2013\\Projects\\BuildServerTriggerWatcher\\Release\\JarvisServerAndSocketLibrary.lib")
#endif
*/
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

