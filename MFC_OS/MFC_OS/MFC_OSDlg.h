
// MFC_OSDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"

//extern MyStruct str[100];
// CMFC_OSDlg �Ի���
class CMFC_OSDlg : public CDialogEx
{
// ����
public:
	CMFC_OSDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_OS_DIALOG };

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
