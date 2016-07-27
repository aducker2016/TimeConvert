
// TimeConvertDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CTimeConvertDlg �Ի���
class CTimeConvertDlg : public CDialogEx
{
// ����
public:
	CTimeConvertDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TIMECONVERT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditTimestamp();
	afx_msg void OnEnChangeEditTimestampSec();
	afx_msg void OnEnChangeEditDatetime();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton();
	afx_msg void OnBnClickedButton2();
	virtual void OnOK();
	void convert(int type);

	CStatic m_staTimeSec;
	CEdit m_edtTimeSec;
	CEdit m_edtTimeMillSec;
	CEdit m_datetime;
	CButton m_btn;
	CButton m_btn2;

	CStatic m_staTimeMillSec;
	CEdit m_timestamp;
	CStatic m_staYear;
	CStatic m_staMonth;
	CStatic m_staDay;
	CStatic m_staHour;
	CStatic m_staMinute;
	CStatic m_staSec;
	CStatic m_staMillSec;
	CEdit m_edtYear;
	CEdit m_edtMonth;
	CEdit m_edtDay;
	CEdit m_edtHour;
	CEdit m_edtMinute;
	CEdit m_edtSec;
	CEdit m_edtMillSec;
	CStatic m_staDatetime;
};
