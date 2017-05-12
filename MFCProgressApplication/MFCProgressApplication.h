
// MFCProgressApplication.h : ������� ���� ��������� ��� ���������� MFCProgressApplication
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CMFCProgressApplicationApp:
// � ���������� ������� ������ ��. MFCProgressApplication.cpp
//

class CMFCProgressApplicationApp : public CWinAppEx
{
public:
	CMFCProgressApplicationApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
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
