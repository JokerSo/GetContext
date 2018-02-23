#include "DetailDlg.h"

#pragma once



// CGetContextDlg 对话框

class CGetContextDlg : public CDialog
{
	DECLARE_DYNAMIC(CGetContextDlg)

public:
	CGetContextDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGetContextDlg();

// 对话框数据
	enum { IDD = IDD_GETCONTEXT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
