#include "Commit.h"

std::string EmailLine(std::string str)
{
	int ipos;
	while ((ipos = str.find("\n")) != std::string::npos)
	{
		str = str.replace(ipos, 1, "");
	}
	std::string strRetVal("-M \"");
	strRetVal.append(str);
	strRetVal.append("\" ");
	return strRetVal;
}

void Commit::PopulateFromJson(Json::Value jsonval)
{
	_strAuthor = jsonval["author"].asString();
	_strMsg = jsonval["message"].asString();

	for (int i = 0; i < jsonval["files"].size(); i++)
		_vectstrFiles.push_back(jsonval["files"][i]["file"].asString());
}

std::string Commit::GetString()
{
	std::string strRetVal = "";
	strRetVal.append(EmailLine("Developer:"));
	strRetVal.append(EmailLine(_strAuthor));
	strRetVal.append(EmailLine(" "));
	strRetVal.append(EmailLine("Commit Message:"));
	strRetVal.append(EmailLine(_strMsg));
	strRetVal.append(EmailLine(" "));
	strRetVal.append(EmailLine("Files Changed:"));
	for (int i = 0; i < _vectstrFiles.size(); i++)
	{
		strRetVal.append(EmailLine(_vectstrFiles[i]));
	}
	strRetVal.append(EmailLine(" "));
	return strRetVal;
}

