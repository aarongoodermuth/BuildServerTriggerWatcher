#pragma once
#include <string>
#include <vector>
#include "..\jsoncpp\include\json\json.h"



class Commit
{
public:
	void PopulateFromJson(Json::Value jsonval);
	std::string GetString();
private:
	std::string _strAuthor;
	std::string _strMsg;
	std::vector<std::string> _vectstrFiles;
};