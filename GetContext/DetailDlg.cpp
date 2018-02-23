// DetailDlg.cpp : 实现文件
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


// CDetailDlg 对话框

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


// CDetailDlg 消息处理程序


void CDetailDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*SB_THUMBPOSITION和SB_THUMBTRACK可能不好理解，前者是拖动滑块后，
	放开鼠标按键后才产生的消息。
	后者是在拖动滑块的过程中一直不停的产生的消息，直到你放开鼠标按键为止*/

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
