#include "stdafx.h"
#include "MainFrame.h"
namespace DuiLib
{

CMainFrame::CMainFrame()
{
}


CMainFrame::~CMainFrame()
{
}
CDuiString CMainFrame::GetSkinFile()
{
	return _T("xml\\MainFrame.xml");
 }
LPCTSTR CMainFrame::GetWindowClassName(void)const
{
	return _T("Fly");
}
void CMainFrame::InitWindow()
{

}
void CMainFrame::Notify(TNotifyUI& msg)
{
	CDuiString strName = msg.pSender->GetName();
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		if (strName == _T("min"))
		{
			SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
		}
		else if (strName == _T("close"))
		{
			Close(IDCANCEL);
			::PostQuitMessage(0);
		}
	}
}
void CMainFrame::OnFinalMessage(HWND hWnd)
{
	delete this;
}
}

