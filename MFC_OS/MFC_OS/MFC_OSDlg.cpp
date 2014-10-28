
// MFC_OSDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_OS.h"
#include "MFC_OSDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFC_OSDlg 对话框



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


// CMFC_OSDlg 消息处理程序

BOOL CMFC_OSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	CDialog::OnInitDialog();
	//初始化列表框
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
	m_list.InsertColumn(0,L"序号",LVCFMT_CENTER,width);
	m_list.InsertColumn(1,L"进程名",LVCFMT_CENTER,width);
	m_list.InsertColumn(2,L"进程ID",LVCFMT_CENTER,width);
	m_list.InsertColumn(3,L"创建时间",LVCFMT_CENTER,width);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_OSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文
		//PaintDesktop(dc.m_hDC);
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // 用于绘制的设备上下文
		//PaintDesktop(dc.m_hDC);
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
			MessageBox(_T("创建进程失败！(因为进程名或ID不能为空)"));
		}
		else
			MessageBox(_T("创建进程失败！(因为进程ID不能为空)"));
	}
	else
	{
		if(m_name1==_T(""))
		{
			MessageBox(_T("创建进程失败！(因为进程名不能为空)"));
		}
		else
		{
			if(i>100||i<0)
			{
				MessageBox(_T("创建进程失败！(超出最大进程数)"));
			}
			else
			{
				str[i].ID=m_ID1;
				str[i].NAME=m_name1;
				i++;
				MessageBox(_T("创建进程成功！"));
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
			MessageBox(_T("进程撤销成功!"));
			i--;
			break;
		}
		else
			MessageBox(_T("该进程不存在!"));
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
	// TODO: 在此处添加消息处理程序代码
}
