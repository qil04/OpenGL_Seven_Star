#pragma once


// IDD_DIALOG dialog

class IDD_DIALOG : public CDialog
{
	DECLARE_DYNAMIC(IDD_DIALOG)

public:
	IDD_DIALOG(CWnd* pParent = nullptr);   // standard constructor
	virtual ~IDD_DIALOG();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double locx;
	double locy;
	double len;
	double rotationangle;
};
