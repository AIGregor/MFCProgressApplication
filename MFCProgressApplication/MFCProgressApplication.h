
// MFCProgressApplication.h : главный файл заголовка для приложения MFCProgressApplication
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMFCProgressApplicationApp:
// О реализации данного класса см. MFCProgressApplication.cpp
//

class CMFCProgressApplicationApp : public CWinAppEx
{
public:
	CMFCProgressApplicationApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	afx_msg void OnMyFileNew();

	DECLARE_MESSAGE_MAP()
};

extern CMFCProgressApplicationApp theApp;
