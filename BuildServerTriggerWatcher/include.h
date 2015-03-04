#if _DEBUG
#pragma comment(lib, "../jsoncpp/build/vs71/debug/lib_json/json_vc71_libmtd.lib")
#pragma comment(lib, "../Debug/JarvisServerAndSocketLibrary.lib")
#else
#pragma comment(lib, "../jsoncpp/build/vs71/release/lib_json/json_vc71_libmt.lib")
#pragma comment(lib, "../Release/JarvisServerAndSocketLibrary.lib")
#endif
