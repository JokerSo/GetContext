// GetContextDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GetContext.h"
#include "GetContextDlg.h"
#include "afxdialogex.h"	


// CGetContextDlg 对话框

IMPLEMENT_DYNAMIC(CGetContextDlg, CDialog)

CGetContextDlg::CGetContextDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetContextDlg::IDD, pParent)
	, m_dwIp(0)
	, m_sPort(_T(""))
	, m_sStartAddr(_T(""))
	, m_sEndAddr(_T(""))
	, m_sLog(_T(""))
{
	dtDlg = NULL;

}

CGetContextDlg::~CGetContextDlg()
{
	if(NULL != dtDlg){
		delete dtDlg;
		dtDlg = NULL;
	}
}

void CGetContextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_IPAddress(pDX, IDC_IP, m_dwIp);
	DDX_Text(pDX, IDC_ED_PORT, m_sPort);
	DDX_Text(pDX, IDC_ED_StartAddr, m_sStartAddr);
	DDX_Text(pDX, IDC_ED_EndAddr, m_sEndAddr);
	DDX_Text(pDX, IDC_ED_LOG, m_sLog);
}


BEGIN_MESSAGE_MAP(CGetContextDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_CON, &CGetContextDlg::onConnectClicked)
END_MESSAGE_MAP()


// CGetContextDlg 消息处理程序


void CGetContextDlg::onConnectClicked()
{
	// TODO: 在此添加控件通知处理程序代码
	//test=====
	m_sStartAddr = "0";
	m_sEndAddr = "20";
	UpdateData(false);
	//test=====
	UpdateData();//bind the data to variable
	if((_wtoi(m_sEndAddr) - _wtoi(m_sStartAddr))<=0)
		return ;
	if(NULL == dtDlg){
		dtDlg = new CDetailDlg();
		dtDlg->Create(IDD_DETAIL_DIALOG, this);
	}
	
	dtDlg->endAddr = _wtoi(m_sEndAddr);
	dtDlg->startAddr =_wtoi(m_sStartAddr);
	
	dtDlg->init();
	dtDlg->ShowWindow(SW_SHOW);
	

	
}
