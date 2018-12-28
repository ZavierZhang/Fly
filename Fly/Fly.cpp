// Fly.cpp : WinMain 的实现
 
#include "stdafx.h"
#include "resource.h"
#include "Fly_i.h"
#include "xdlldata.h"

#include "UIlib.h"
#include "AuxFlyUI.h"
#include <atlstr.h>

using namespace ATL;


class CFlyModule : public ATL::CAtlExeModuleT< CFlyModule >
{
public :
	DECLARE_LIBID(LIBID_FlyLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_FLY, "{FD9B9497-50C2-48C5-AA5E-B56D88CA3AE9}")
	};

CFlyModule _AtlModule;

// 获取安装目录
CString GetInstallFolder(CString s_strExePath)
{
	ATLASSERT(!s_strExePath.IsEmpty());

	int ix = s_strExePath.ReverseFind(_T('\\'));
	if (ix != -1)
	{
		return s_strExePath.Mid(0, ix);
	}

	ATLASSERT(FALSE);
	return _T("");
}
CString StdFilePath(CString strPath)
{
	// '/'替换为'\'
	strPath.Replace(_T('/'), _T('\\'));

	// 替换 'A\B\.\'的 ‘\B\’
	strPath.Replace(_T("\\.\\"), _T("\\"));

	// 去掉多余的'\'
	strPath.Replace(_T("\\\\"), _T("\\"));

	// 去掉 'A\B\..\'的 ‘\B\..’
	for (;;)
	{
		int iPos = strPath.Find(_T("\\..\\"));
		if (0 > iPos)
		{
			break;
		}

		//死循环?
		CString strSub = strPath.Left(iPos);
		int iPrev = strSub.ReverseFind(_T('\\'));
		if (iPrev < 0)
		{
			break;
		}

		strPath.Delete(iPrev, iPos - iPrev + _tcslen(_T("\\..")));
	}

	return strPath;
}

CString GetInstallPath(CString strExePath)
{
	strExePath=strExePath.Left(strExePath.GetLength() - 1);
	int ix = strExePath.ReverseFind(_T('\\'));
	if (ix != -1)
	{
		return strExePath.Mid(0, ix);
	}

	ATLASSERT(FALSE);
	return _T("");
}
//
extern "C" int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, 
								LPTSTR lpCmdLine, int nShowCmd)
{
	//_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);

	//::OleInitialize(NULL);
	::CoInitialize(NULL);
	
	DuiLib::CPaintManagerUI::SetInstance(hInstance);
	DuiLib::CDuiString strResourcePath = DuiLib::CPaintManagerUI::GetInstancePath();
	CString strPath=StdFilePath(strResourcePath.GetData());
	DuiLib::CDuiString strRes=GetInstallPath(strPath);
	DuiLib::CPaintManagerUI::SetResourceType(DuiLib::UILIB_FILE);
	strRes += _T("\\resources");
	DuiLib::CPaintManagerUI::SetResourcePath(strRes);

	Aux::UI::ShowMainWnd(NULL);
	DuiLib::CPaintManagerUI::MessageLoop();

	::CoUninitialize();
	//_CrtDumpMemoryLeaks();
	return 0;
}

