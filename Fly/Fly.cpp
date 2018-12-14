// Fly.cpp : WinMain µÄÊµÏÖ


#include "stdafx.h"
#include "resource.h"
#include "Fly_i.h"
#include "xdlldata.h"


using namespace ATL;


class CFlyModule : public ATL::CAtlExeModuleT< CFlyModule >
{
public :
	DECLARE_LIBID(LIBID_FlyLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_FLY, "{FD9B9497-50C2-48C5-AA5E-B56D88CA3AE9}")
	};

CFlyModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	::OleInitialize(NULL);
	::CoInitialize(NULL);
	

	::CoUninitialize();
	return _AtlModule.WinMain(nShowCmd);
}

