
// TimeConvertDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CTimeConvertDlg 对话框
class CTimeConvertDlg : public CDialogEx
{
// 构造
public:
	CTimeConvertDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TIMECONVERT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
