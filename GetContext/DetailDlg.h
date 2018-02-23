#pragma once


// CDetailDlg 对话框

class CDetailDlg : public CDialog
{
	DECLARE_DYNAMIC(CDetailDlg)

public:
	CDetailDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDetailDlg();

// 对话框数据
	enum { IDD = IDD_DETAIL_DIALOG };

public:
	void init();

	//member
	unsigned int createNumber;
	unsigned int startAddr;
	unsigned int endAddr;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
