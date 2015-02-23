#if _DEBUG
#pragma comment(lib, "../Debug/json_vc71_libmt.lib")
#pragma comment(lib, "../Debug/JarvisServerAndSocketLibrary.lib")
#else
#pragma comment(lib, "../Release/json_vc71_libmt.lib")
#pragma comment(lib, "../Release/JarvisServerAndSocketLibrary.lib")
#endif