// IDD_DIALOG.cpp : implementation file
//

#include "pch.h"
#include "Step.h"
#include "IDD_DIALOG.h"
#include "afxdialogex.h"


// IDD_DIALOG dialog

IMPLEMENT_DYNAMIC(IDD_DIALOG, CDialog)

IDD_DIALOG::IDD_DIALOG(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, locx(0)
	, locy(0)
	, len(0)
	, rotationangle(0)
{

}

IDD_DIALOG::~IDD_DIALOG()
{
}

void IDD_DIALOG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LOCX, locx);
	DDX_Text(pDX, IDC_LOCY, locy);
	DDX_Text(pDX, IDC_LEN, len);
	DDX_Text(pDX, IDC_ROTATION, rotationangle);
}


BEGIN_MESSAGE_MAP(IDD_DIALOG, CDialog)
END_MESSAGE_MAP()


// IDD_DIALOG message handlers
