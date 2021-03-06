// CLineDlg.cpp : implementation file
//

#include "pch.h"
#include "Step.h"
#include "CLineDlg.h"
#include "afxdialogex.h"


// CLineDlg dialog

IMPLEMENT_DYNAMIC(CLineDlg, CDialog)

CLineDlg::CLineDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_LINEDLG, pParent)
	, m_fmx(0)
	, m_fmy(0)
	, mtox(0)
	, mtoy(0)
{

}

CLineDlg::~CLineDlg()
{
}

void CLineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FMX, m_fmx);
	DDX_Text(pDX, IDC_FMY, m_fmy);
	DDX_Text(pDX, IDC_TOX, mtox);
	DDX_Text(pDX, IDC_TOY, mtoy);
}


BEGIN_MESSAGE_MAP(CLineDlg, CDialog)
END_MESSAGE_MAP()


// CLineDlg message handlers
