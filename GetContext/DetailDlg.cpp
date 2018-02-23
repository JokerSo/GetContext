// DetailDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GetContext.h"
#include "DetailDlg.h"
#include "afxdialogex.h"

#define MAX_CREATE_CONTROL 2048

struct position{
	int x;
	int y;
} Position
	;


// CDetailDlg �Ի���

IMPLEMENT_DYNAMIC(CDetailDlg, CDialog)

CDetailDlg::CDetailDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDetailDlg::IDD, pParent)
{
}

CDetailDlg::~CDetailDlg()
{
}

void CDetailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

void CDetailDlg::init(){
	if(endAddr - startAddr <= 0)
		return;

	CEdit* edlines[MAX_CREATE_CONTROL];
	position valuePos;
	valuePos.x = 37;
	valuePos.y = 33;
	int visiable = (endAddr-startAddr)>10?10:(endAddr-startAddr);

	for(int i=startAddr; i<visiable; i++){
		CEdit* line = new CEdit();
		line->Create(WS_VISIBLE|WS_CHILD, CRect(1,1,1,1), this,i );
		CStatic* st = new CStatic();
		CString cs;
		cs.Format(_T("%d"), i);
		st->Create(cs,WS_VISIBLE|WS_CHILD,CRect(valuePos.x+i%2*300,valuePos.y+i/2*50,60,20),this,i);
		//st->ShowWindow(SW_SHOW);
		st->MoveWindow(valuePos.x+(i-startAddr)%2*300,valuePos.y+(i-startAddr)/2*50-20,60,20);
		line->MoveWindow(valuePos.x+(i-startAddr)%2*300,valuePos.y+(i-startAddr)/2*50,60,20);
		line->SetSel(2,false);
	}
	
}


BEGIN_MESSAGE_MAP(CDetailDlg, CDialog)
	ON_WM_VSCROLL()
END_MESSAGE_MAP()


// CDetailDlg ��Ϣ�������


void CDetailDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*SB_THUMBPOSITION��SB_THUMBTRACK���ܲ�����⣬ǰ�����϶������
	�ſ���갴����Ų�������Ϣ��
	���������϶�����Ĺ�����һֱ��ͣ�Ĳ�������Ϣ��ֱ����ſ���갴��Ϊֹ*/

	switch(nSBCode){
	case SB_LINEUP:
		break;
	case SB_LINEDOWN:
		break;
	case SB_PAGEUP:
		break;
	case SB_PAGEDOWN:
		break;
	case SB_THUMBPOSITION:
		break;
	case SB_THUMBTRACK:
		break;
	default:
		break;
			 
	}
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
