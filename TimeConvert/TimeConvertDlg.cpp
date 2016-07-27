
// TimeConvertDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TimeConvert.h"
#include "TimeConvertDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTimeConvertDlg �Ի���



CTimeConvertDlg::CTimeConvertDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTimeConvertDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTimeConvertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_TIMESTAMP, m_timestamp);
	DDX_Control(pDX, IDC_EDIT_DATETIME, m_datetime);
	DDX_Control(pDX, IDC_BUTTON, m_btn);
	DDX_Control(pDX, IDC_STATIC_TIMESTAMP_MILLSEC, m_staTimeMillSec);
	DDX_Control(pDX, IDC_STATIC_TIMESTAMP_SEC, m_staTimeSec);
	DDX_Control(pDX, IDC_STATIC_YEAR, m_staYear);
	DDX_Control(pDX, IDC_STATIC_MONTH, m_staMonth);
	DDX_Control(pDX, IDC_STATIC_DAY, m_staDay);
	DDX_Control(pDX, IDC_STATIC_HOUR, m_staHour);
	DDX_Control(pDX, IDC_STATIC_MINUTE, m_staMinute);
	DDX_Control(pDX, IDC_STATIC_SEC, m_staSec);
	DDX_Control(pDX, IDC_STATIC_MILL_SEC, m_staMillSec);
	DDX_Control(pDX, IDC_EDIT_TIMESTAMP_SEC, m_edtTimeSec);
	DDX_Control(pDX, IDC_EDIT_TIMESTAMP_MILL, m_edtTimeMillSec);
	DDX_Control(pDX, IDC_EDIT_YEAR, m_edtYear);
	DDX_Control(pDX, IDC_EDIT_MONTH, m_edtMonth);
	DDX_Control(pDX, IDC_EDIT_DAY, m_edtDay);
	DDX_Control(pDX, IDC_EDIT_HOUR, m_edtHour);
	DDX_Control(pDX, IDC_EDIT_MINUTE, m_edtMinute);
	DDX_Control(pDX, IDC_EDIT_SEC, m_edtSec);
	DDX_Control(pDX, IDC_EDIT_MILL_SEC, m_edtMillSec);
	DDX_Control(pDX, IDC_STATIC_DATETIME, m_staDatetime);
	DDX_Control(pDX, IDC_BUTTON2, m_btn2);
}

BEGIN_MESSAGE_MAP(CTimeConvertDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_TIMESTAMP, &CTimeConvertDlg::OnEnChangeEditTimestamp)
	ON_EN_CHANGE(IDC_EDIT_TIMESTAMP_SEC, &CTimeConvertDlg::OnEnChangeEditTimestampSec)
	ON_EN_CHANGE(IDC_EDIT_TIMESTAMP_MILL, &CTimeConvertDlg::OnEnChangeEditTimestampSec)
	ON_EN_CHANGE(IDC_EDIT_YEAR, &CTimeConvertDlg::OnEnChangeEditDatetime)
	ON_EN_CHANGE(IDC_EDIT_MONTH, &CTimeConvertDlg::OnEnChangeEditDatetime)
	ON_EN_CHANGE(IDC_EDIT_DAY, &CTimeConvertDlg::OnEnChangeEditDatetime)
	ON_EN_CHANGE(IDC_EDIT_HOUR, &CTimeConvertDlg::OnEnChangeEditDatetime)
	ON_EN_CHANGE(IDC_EDIT_MINUTE, &CTimeConvertDlg::OnEnChangeEditDatetime)
	ON_EN_CHANGE(IDC_EDIT_SEC, &CTimeConvertDlg::OnEnChangeEditDatetime)
	ON_EN_CHANGE(IDC_EDIT_MILL_SEC, &CTimeConvertDlg::OnEnChangeEditDatetime)
	ON_BN_CLICKED(IDC_BUTTON, &CTimeConvertDlg::OnBnClickedButton)
	ON_BN_CLICKED(IDC_BUTTON2, &CTimeConvertDlg::OnBnClickedButton2)
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// CTimeConvertDlg ��Ϣ�������

BOOL CTimeConvertDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	MoveWindow(0, 0, 490, 155);
	CenterWindow();

	m_staTimeMillSec.MoveWindow(10, 13, 37, 25);
	m_timestamp.MoveWindow(50, 10, 130, 25);
	m_btn.MoveWindow(230, 10, 110, 25);
	m_btn2.MoveWindow(350, 10, 110, 25);

	m_staTimeSec.MoveWindow(10, 43, 37, 25);
	m_edtTimeSec.MoveWindow(50, 40, 85, 25);
	m_edtTimeMillSec.MoveWindow(140, 40, 40, 25);
	m_datetime.MoveWindow(230, 40, 230, 25);

	m_staDatetime.MoveWindow(10, 83, 37, 25);
	m_edtYear.MoveWindow(50, 80, 50, 25);
	m_staYear.MoveWindow(105, 83, 20, 25);
	m_edtMonth.MoveWindow(125, 80, 30, 25);
	m_staMonth.MoveWindow(160, 83, 20, 25);
	m_edtDay.MoveWindow(180, 80, 30, 25);
	m_staDay.MoveWindow(215, 83, 20, 25);
	m_edtHour.MoveWindow(235, 80, 30, 25);
	m_staHour.MoveWindow(270, 83, 20, 25);
	m_edtMinute.MoveWindow(290, 80, 30, 25);
	m_staMinute.MoveWindow(325, 83, 20, 25);
	m_edtSec.MoveWindow(345, 80, 30, 25);
	m_staSec.MoveWindow(380, 83, 20, 25);
	m_edtMillSec.MoveWindow(400, 80, 30, 25);
	m_staMillSec.MoveWindow(435, 83, 30, 25);

	CTimeConvertDlg::OnBnClickedButton();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTimeConvertDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTimeConvertDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTimeConvertDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTimeConvertDlg::OnEnChangeEditTimestamp()
{
	convert(1);
}

void CTimeConvertDlg::OnEnChangeEditTimestampSec()
{
	convert(2);
}

void CTimeConvertDlg::OnEnChangeEditDatetime()
{
	convert(3);
}

void CTimeConvertDlg::OnBnClickedButton()
{
	INT64 t = time(NULL);
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	t = t * 1000 + sys.wMilliseconds;
	CString text;
	text.Format(_T("%I64d"), t);
	m_timestamp.SetWindowText(text);
}

void CTimeConvertDlg::OnBnClickedButton2()
{
	CString text;
	text.Format(_T("%I64d"), (INT64)0x7FFFFFFF * 1000);
	m_timestamp.SetWindowText(text);
}

void CTimeConvertDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	convert(1);
	m_staTimeSec.SetFocus();
	CDialogEx::OnLButtonUp(nFlags, point);
}

void CTimeConvertDlg::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���
	convert(1);
	m_staTimeSec.SetFocus();
}

void CTimeConvertDlg::convert(int type)
{
	static BOOL isConverting = FALSE;
	if (isConverting)
	{
		return;
	}

	CString text;

	//���ʱ��
	CTime t;
	INT millsec = 0;
	if (1 == type)
	{
		m_timestamp.GetWindowText(text);
		INT64 timestamp = _ttoi64(text.GetBuffer());
		t = CTime(timestamp / 1000);
		millsec = timestamp % 1000;
	}
	else if (2 == type)
	{
		m_edtTimeSec.GetWindowText(text);
		t = CTime(_ttoi64(text.GetBuffer()));
		m_edtTimeMillSec.GetWindowText(text);
		millsec = _ttoi(text.GetBuffer());
		if (millsec < 0 || millsec > 999) return;
	}
	else if (3 == type)
	{
		m_edtYear.GetWindowText(text);
		INT year = _ttoi(text.GetBuffer());
		if (year < 1970) return;

		m_edtMonth.GetWindowText(text);
		INT month = _ttoi(text.GetBuffer());
		if (month < 1 || month > 12) return;

		m_edtDay.GetWindowText(text);
		INT day = _ttoi(text.GetBuffer());
		if (day < 1 || day > 31) return;

		m_edtHour.GetWindowText(text);
		INT hour = _ttoi(text.GetBuffer());
		if (hour < 0 || hour > 23) return;

		m_edtMinute.GetWindowText(text);
		INT minute = _ttoi(text.GetBuffer());
		if (minute < 0 || minute > 59) return;

		m_edtSec.GetWindowText(text);
		INT sec = _ttoi(text.GetBuffer());
		if (sec < 0 || sec > 59) return;

		t = CTime(year, month, day, hour, minute, sec);
		m_edtMillSec.GetWindowText(text);
		millsec = _ttoi(text.GetBuffer());
		if (millsec < 0 || millsec > 999) return;
	}
	else
	{
		return;
	}

	isConverting = TRUE;

	//���ʱ��
	text.Format(_T("%s.%03d"), t.Format(_T("%Y-%m-%d %H:%M:%S")), millsec);
	m_datetime.SetWindowText(text);
	
	if (1 != type)
	{
		text.Format(_T("%I64d"), (INT64)t.GetTime() * 1000 + millsec);
		m_timestamp.SetWindowText(text);
	}
	if (2 != type)
	{
		text.Format(_T("%I64d"), (INT64)t.GetTime());
		m_edtTimeSec.SetWindowText(text);
		text.Format(_T("%d"), millsec);
		m_edtTimeMillSec.SetWindowText(text);
	}
	if (3 != type)
	{
		text.Format(_T("%d"), t.GetYear());
		m_edtYear.SetWindowText(text);
		text.Format(_T("%d"), t.GetMonth());
		m_edtMonth.SetWindowText(text);
		text.Format(_T("%d"), t.GetDay());
		m_edtDay.SetWindowText(text);
		text.Format(_T("%d"), t.GetHour());
		m_edtHour.SetWindowText(text);
		text.Format(_T("%d"), t.GetMinute());
		m_edtMinute.SetWindowText(text);
		text.Format(_T("%d"), t.GetSecond());
		m_edtSec.SetWindowText(text);
		text.Format(_T("%d"), millsec);
		m_edtMillSec.SetWindowText(text);
	}

	isConverting = FALSE;
}
