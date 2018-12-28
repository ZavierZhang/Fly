#pragma once
#include "UIlib.h"
namespace DuiLib
{
	class CMainFrame : public WindowImplBase
	{
	public:
		CMainFrame();
		~CMainFrame();
		virtual CDuiString GetSkinFile();
		virtual LPCTSTR GetWindowClassName(void)const;


		void InitWindow();
		void Notify(TNotifyUI& msg);
		void OnFinalMessage(HWND hWnd);
	};
}


