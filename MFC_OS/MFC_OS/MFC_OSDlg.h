
// MFC_OSDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"

//extern MyStruct str[100];
// CMFC_OSDlg 对话框
class CMFC_OSDlg : public CDialogEx
{
// 构造
public:
	CMFC_OSDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_OS_DIALOG };

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
	CListCtrl m_list;
//	CEdit m_ID1;
//	CEdit m_name1;
//	CEdit m_ID2;
//	CEdit m_name2;
	afx_msg void OnBnClickedButton1();
	CString m_ID1;
	CString m_name1;
	CString m_ID2;
	CString m_name2;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnMove(int x, int y);
};
