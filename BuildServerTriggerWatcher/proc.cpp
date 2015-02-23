#include "RequestHandler.h"
#include "include.h"

#if _DEBUG
#include <iostream>
#include "build.h"
#endif

int main()
{
#ifdef _DEBUG
	while (0)
	{
		std::string strFake;
		std::getline(std::cin, strFake);
		Build(strFake);
	}
#endif
	RequestHandler rqh;
	JarvisSS::JarvisServer js = JarvisSS::JarvisServer(8000, &rqh);
	js.Start();
	return 0;
}