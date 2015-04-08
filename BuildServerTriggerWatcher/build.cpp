#include <assert.h>
#include "Commit.h"
//#include "C:\jsoncpp\include\json\json.h"
#include "..\jsoncpp\include\json\json.h"
#include <iostream>
#include "build.h"

#define DANIEL_IS_DONE 1
#define SEARCH_KEY "payload="

struct mpStrUnescapedStrEscaped
{
	std::string chUnescaped;
	std::string strescaped;
};

const int cmpchstr = 19;
mpStrUnescapedStrEscaped mpstrstr[cmpchstr] =
{
	{ "^", "%5E" },
	{ "&", "%26" },
	{ "`", "%60" },
	{ "{", "%7B" },
	{ "}", "%7D" },
	{ "|", "%7C" },
	{ "]", "%5D" },
	{ "[", "%5B" },
	{ "\"", "%22" },
	{ "<", "%3C" },
	{ ">", "%3E" },
	{ "\\", "%5C" },
	{ ",", "%2C" },
	{ ":", "%3A" },
	{ "@", "%40" },
	{ "/", "%2F" },
	{ "'", "%27" },
	{ " ", "%20" },
	{ " ", "+" }
};

std::string StrUnescapeHTTP(std::string str)
{

	for (int i = 0; i < cmpchstr; i++)
	{
		int iposCur = str.find(mpstrstr[i].strescaped);
		if (iposCur != std::string::npos)
		{
			str = str.replace(iposCur, mpstrstr[i].strescaped.length(), mpstrstr[i].chUnescaped);
			--i;
		}
	}
	return str;
}

std::string SzCommandLineArg(std::string& strPostData)
{
	//strip away the http header (aka just ge the json obj in string format)
	int iposSearch = strPostData.find(SEARCH_KEY);
	if (iposSearch == std::string::npos)
		return "";
	iposSearch += std::string(SEARCH_KEY).length();
	strPostData = strPostData.substr(iposSearch, strPostData.length() - iposSearch);
	iposSearch = strPostData.find(" ");
	if (iposSearch == std::string::npos)
		iposSearch = strPostData.length();
	strPostData = strPostData.substr(0, iposSearch);
	std::string strjsonCleanMessage = StrUnescapeHTTP(strPostData);
#if _DEBUG 
	std::cout << std::endl << std::endl << std::endl << strjsonCleanMessage;
#endif

	// convert string from above to json object
	Json::Value jsonobj;
	Json::Reader jsonreader;
	if (!jsonreader.parse(strjsonCleanMessage, jsonobj))
		assert(false);

	std::vector<Commit> _vectcommit;
	for (unsigned int i = 0; i < jsonobj["commits"].size(); i++)
	{
		_vectcommit.push_back(Commit());
		_vectcommit[i].PopulateFromJson(jsonobj["commits"][i]);
	}

	std::string strRetVal = "";
	for (unsigned int i = 0; i < jsonobj["commits"].size(); i++)
	{
		strRetVal.append(_vectcommit[i].GetString());
	}

	return strRetVal;
}

std::string SzCommand(std::string& strPostData)
{
	if (strPostData.find("AvianWeb") != std::string::npos)
		return "start C:\\avianweb.bat ";
	else
		return "start C:\\build.bat ";
}

void Build(std::string strIn)
{
#if 0
	std::string strT("echo '");
	strT.append(strIn).append("' > c:\test_data.txt");
	std::cout << strT;
	system(strT.c_str());
#endif
	std::string szToSystem(SzCommand(strIn));
	szToSystem.append(SzCommandLineArg(std::string(strIn)));
	szToSystem.append(" > C:\\buildlog.txt");
#ifdef _DEBUG
	std::cout << szToSystem;
	return;
#endif
	system(szToSystem.c_str());
}