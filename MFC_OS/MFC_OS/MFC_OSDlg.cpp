
// MFC_OSDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_OS.h"
#include "MFC_OSDlg.h"
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


// CMFC_OSDlg �Ի���



CMFC_OSDlg::CMFC_OSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_OSDlg::IDD, pParent)
	, m_ID1(_T(""))
	, m_name1(_T(""))
	, m_ID2(_T(""))
	, m_name2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_OSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	//  DDX_Control(pDX, IDC_EDIT1, m_ID1);
	//  DDX_Control(pDX, IDC_EDIT2, m_name1);
	//  DDX_Control(pDX, IDC_EDIT3, m_ID2);
	//  DDX_Control(pDX, IDC_EDIT4, m_name2);
	DDX_Text(pDX, IDC_EDIT1, m_ID1);
	DDX_Text(pDX, IDC_EDIT2, m_name1);
	DDX_Text(pDX, IDC_EDIT3, m_ID2);
	DDX_Text(pDX, IDC_EDIT4, m_name2);
}

BEGIN_MESSAGE_MAP(CMFC_OSDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_OSDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_OSDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_OSDlg::OnBnClickedButton2)
	ON_WM_MOVE()
END_MESSAGE_MAP()


// CMFC_OSDlg ��Ϣ�������

BOOL CMFC_OSDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	CDialog::OnInitDialog();
	//��ʼ���б��
	LONG lStyle;
	lStyle=GetWindowLong(m_list.m_hWnd,GWL_STYLE);
	lStyle&=~LVS_TYPEMASK;
	lStyle|=LVS_REPORT;
	SetWindowLong(m_list.m_hWnd,GWL_STYLE,lStyle);
	DWORD DwStyle=m_list.GetExtendedStyle();
	DwStyle|=LVS_EX_FULLROWSELECT;
	DwStyle|=LVS_EX_GRIDLINES;
	m_list.SetExtendedStyle(DwStyle);
	CRect rc;
	m_list.GetClientRect(rc);
	int width=rc.Width()/4;
	m_list.InsertColumn(0,L"���",LVCFMT_CENTER,width);
	m_list.InsertColumn(1,L"������",LVCFMT_CENTER,width);
	m_list.InsertColumn(2,L"����ID",LVCFMT_CENTER,width);
	m_list.InsertColumn(3,L"����ʱ��",LVCFMT_CENTER,width);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC_OSDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_OSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������
		//PaintDesktop(dc.m_hDC);
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
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������
		//PaintDesktop(dc.m_hDC);
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_OSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_OSDlg::OnBnClickedButton1()
{
	UpdateData(true);
	CTime time;
	time=CTime::GetCurrentTime();
	Time[i]=time.Format("%H:%M:%S");
	MessageBox(Time[i],NULL,MB_OK);
	if(m_ID1.GetLength()==0)
	{
		if(m_name1==_T(""))
		{
			MessageBox(_T("��������ʧ�ܣ�(��Ϊ��������ID����Ϊ��)"));
		}
		else
			MessageBox(_T("��������ʧ�ܣ�(��Ϊ����ID����Ϊ��)"));
	}
	else
	{
		if(m_name1==_T(""))
		{
			MessageBox(_T("��������ʧ�ܣ�(��Ϊ����������Ϊ��)"));
		}
		else
		{
			if(i>100||i<0)
			{
				MessageBox(_T("��������ʧ�ܣ�(������������)"));
			}
			else
			{
				str[i].ID=m_ID1;
				str[i].NAME=m_name1;
				i++;
				MessageBox(_T("�������̳ɹ���"));
			}
		}
	}
	
	m_ID1="";
	m_name1="";
	UpdateData(false);
}


void CMFC_OSDlg::OnBnClickedButton3()
{
	m_list.DeleteAllItems();
	UpdateData(false);
	for(int n=0;n<i;n++)
	{
		CString s;
		s.Format(_T("%d"),n+1);
		int count=m_list.GetItemCount();
		m_list.InsertItem(count,s);
		m_list.SetItemText(count,1,str[n].NAME);
		m_list.SetItemText(count,2,str[n].ID);
		m_list.SetItemText(count,3,Time[n]);
	}


		
}


void CMFC_OSDlg::OnBnClickedButton2()
{
	UpdateData(true);
	int Num=0;
	for(Num=0;Num<i;Num++)
	{
		if(m_name2==str[Num].NAME&&m_ID2==str[Num].ID)
		{	for(int a=Num;a<i;a++)
			{
				str[a]=str[a+1];
			}
			MessageBox(_T("���̳����ɹ�!"));
			i--;
			break;
		}
		else
			MessageBox(_T("�ý��̲�����!"));
	}
	m_ID2="";
	m_name2="";
	UpdateData(false);
}


void CMFC_OSDlg::OnMove(int x, int y)
{
	CDialogEx::OnMove(x, y);
	/*CDC* pDC=GetDC();
	PaintDesktop(pDC->m_hDC);*/
	// TODO: �ڴ˴������Ϣ����������
}
