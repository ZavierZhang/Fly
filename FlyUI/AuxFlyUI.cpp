#include "stdafx.h"
#include "AuxFlyUI.h"
#include "MainFrame.h"

bool Aux::UI::ShowLogin(LPCTSTR cmd)
{
	return true;
}
bool Aux::UI::ShowMainWnd(LPCTSTR cmd)
{
	DuiLib::CMainFrame* pMain = new DuiLib::CMainFrame;
	pMain->Create(NULL, _T("Fly"), UI_WNDSTYLE_DIALOG, 0L, 0, 0, 544, 394);
	pMain->CenterWindow();
	pMain->ShowModal();
	::ShowWindow(pMain->GetHWND(), SW_SHOW);
	return true;
}