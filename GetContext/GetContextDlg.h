#include "DetailDlg.h"

#pragma once



// CGetContextDlg �Ի���

class CGetContextDlg : public CDialog
{
	DECLARE_DYNAMIC(CGetContextDlg)

public:
	CGetContextDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CGetContextDlg();

// �Ի�������
	enum { IDD = IDD_GETCONTEXT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	
public:
	DWORD m_dwIp;
	CString m_sPort;
	CString m_sStartAddr;
	CString m_sEndAddr;
	CString m_sLog;
	afx_msg void onConnectClicked();

private:
	CDetailDlg *dtDlg;
};
