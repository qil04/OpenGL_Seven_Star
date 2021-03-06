
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "Step.h"
#include "ChildView.h"
#include "CLineDlg.h"
#include "IDD_DIALOG.h"
#include "graphics/OpenGLWnd.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_linefmx = 0.5;
	m_linefmy = 0.5;
	m_linetox = 0.2;
	m_linetoy = 0.55;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, COpenGLWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_STEPSTUFF_LINEENDTO0, &CChildView::OnStepstuffLineendto0)
	ON_COMMAND(ID_STEPSTUFF_LINEDIALOG, &CChildView::OnStepstuffLinedialog)
	ON_COMMAND(ID_STEPSTUFF_DIALOG1, &CChildView::OnStepstuffDialog1)
END_MESSAGE_MAP()


void CChildView::OnGLDraw(CDC* pDC)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	int width, height;
	GetSize(width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.5, // left
		1.5, // right
		-1.5, // bottom
		1.5, // top
		1.5, // near
		-1.5); // far

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	const float PI = 3.1415926525897;
	const float R = m_len/2/cos(25.71 * PI /360);
	const float theta = m_rotationangle;
	const float x0 = m_locx;
	const float y0 = m_locy;
	

	glColor3d(1.0, 0.0, 0.0);
	glLineWidth(10.0);
	glBegin(GL_LINE_LOOP);
	GLfloat xA = R * cos((90 + theta) * PI / 180);
	GLfloat yA = R * sin((90 + theta) * PI / 180);
	GLfloat xB = R * cos((295.71 + theta) * PI / 180);
	GLfloat yB = R * sin((295.71 + theta) * PI / 180);
	GLfloat xC = R * cos((141.43 + theta) * PI / 180);
	GLfloat yC = R * sin((141.43 + theta) * PI / 180);
	GLfloat xD = R * cos((347.14 + theta) * PI / 180);
	GLfloat yD = R * sin((347.14 + theta) * PI / 180);
	GLfloat xE = R * cos((192.86 + theta) * PI / 180);
	GLfloat yE = R * sin((192.86 + theta) * PI / 180);
	GLfloat xF = R * cos((38.57 + theta) * PI / 180);
	GLfloat yF = R * sin((38.57 + theta) * PI / 180);
	GLfloat xG = R * cos((244.29 + theta) * PI / 180);
	GLfloat yG = R * sin((244.29 + theta) * PI / 180);
	glVertex2f(xA, yA);
	glVertex2f(xB, yB);
	glVertex2f(xC, yC);
	glVertex2f(xD, yD);
	glVertex2f(xE, yE);
	glVertex2f(xF, yF);
	glVertex2f(xG, yG);
	glEnd();

	glColor3d(0.0, 0.5, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2d((-R - x0) * cos(theta * PI / 180) - ((-R - y0) * sin(theta * PI / 180)) + x0, (-R - y0) * cos(theta * PI / 180) + (-R - x0) * sin(theta * PI / 180) + y0);
	glVertex2d((R - x0) * cos(theta * PI / 180) - ((-R - y0) * sin(theta * PI / 180)) + x0, (-R - y0) * cos(theta * PI / 180) + (R - x0) * sin(theta * PI / 180) + y0);
	glVertex2d((R - x0) * cos(theta * PI / 180) - ((R - y0) * sin(theta * PI / 180)) + x0, (R - y0) * cos(theta * PI / 180) + (R - x0) * sin(theta * PI / 180) + y0);
	glVertex2d((-R - x0) * cos(theta * PI / 180) - ((R - y0) * sin(theta * PI / 180)) + x0, (R - y0) * cos(theta * PI / 180) + (-R - x0) * sin(theta * PI / 180) + y0);
	glEnd();
	
}

// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!COpenGLWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

//void CChildView::OnPaint() 
//{
	//CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
//}





void CChildView::OnStepstuffLineendto0()
{
	// TODO: Add your command handler code here
	m_rotationangle += 20;

	Invalidate();
}


void CChildView::OnStepstuffLinedialog()
{
	// TODO: Add your command handler code here
	CLineDlg dlg;

	dlg.m_fmx = m_linefmx;
	dlg.m_fmy = m_linefmy;
	dlg.mtox = m_linetox;
	dlg.mtoy = m_linetoy;
	

	if (dlg.DoModal() == IDOK)
	{
		m_linefmx = dlg.m_fmx;
		m_linefmy = dlg.m_fmy;
		m_linetox = dlg.mtox;
		m_linetoy = dlg.mtoy;

		Invalidate();
	}
}


void CChildView::OnStepstuffDialog1()
{
	// TODO: Add your command handler code here
	IDD_DIALOG dlgs1;

	dlgs1.locx = m_locx;
	dlgs1.locy = m_locy;
	dlgs1.len = m_len;
	dlgs1.rotationangle = m_rotationangle;

	if (dlgs1.DoModal() == IDOK)
	{
		m_locx = dlgs1.locx;
		m_locy = dlgs1.locy;
		m_len = dlgs1.len;
		m_rotationangle = dlgs1.rotationangle;

		Invalidate();
	}
}
