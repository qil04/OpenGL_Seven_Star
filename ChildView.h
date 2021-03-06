
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "graphics/OpenGLWnd.h"

// CChildView window

class CChildView : public COpenGLWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnGLDraw(CDC* pDC);
// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	//afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
private:
	double m_linefmx;
	double m_linefmy;
	double m_linetox;
	double m_linetoy;

public:
	afx_msg void OnStepstuffLineendto0();
	afx_msg void OnStepstuffLinedialog();
	afx_msg void OnStepstuffDialog1();

private:
	double m_locx = 0;
	double m_locy = 0;
	double m_len = 0;
	double m_rotationangle = 0;
};

