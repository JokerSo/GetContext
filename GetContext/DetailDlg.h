#pragma once


// CDetailDlg �Ի���

class CDetailDlg : public CDialog
{
	DECLARE_DYNAMIC(CDetailDlg)

public:
	CDetailDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDetailDlg();

// �Ի�������
	enum { IDD = IDD_DETAIL_DIALOG };

public:
	void init();

	//member
	unsigned int createNumber;
	unsigned int startAddr;
	unsigned int endAddr;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
