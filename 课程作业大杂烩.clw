; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGrapicSetting
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "课程作业大杂烩.h"
LastPage=0

ClassCount=6
Class1=CMyApp
Class2=CMyDoc
Class3=CMyView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CGrapicSetting
Resource3=IDD_DIALOG1

[CLS:CMyApp]
Type=0
HeaderFile=课程作业大杂烩.h
ImplementationFile=课程作业大杂烩.cpp
Filter=N

[CLS:CMyDoc]
Type=0
HeaderFile=课程作业大杂烩Doc.h
ImplementationFile=课程作业大杂烩Doc.cpp
Filter=N

[CLS:CMyView]
Type=0
HeaderFile=课程作业大杂烩View.h
ImplementationFile=课程作业大杂烩View.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=IDM_MODE_TEXT_EDIT


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDM_MODE_DRAW
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=课程作业大杂烩.cpp
ImplementationFile=课程作业大杂烩.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=IDM_SHAPE
Command18=IDM_COLOR
Command19=IDM_EMPTY_CLIENT
Command20=IDM_SET_FONT
Command21=IDM_MODE_DRAW
Command22=IDM_MODE_TEXT_EDIT
CommandCount=22

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG1]
Type=1
Class=CGrapicSetting
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_LINE_WIDTH,edit,1350631552
Control3=IDC_STATIC,button,1342177287
Control4=IDC_SOLID,button,1342308361
Control5=IDC_DASH,button,1342177289
Control6=IDC_DOTTED,button,1342177289
Control7=IDC_STATIC,button,1342177287
Control8=IDC_DOT,button,1342308361
Control9=IDC_LINE,button,1342177289
Control10=IDC_RECTANGLE,button,1342177289
Control11=IDC_ELLIPSE,button,1342177289
Control12=IDOK,button,1342242816

[CLS:CGrapicSetting]
Type=0
HeaderFile=GrapicSetting.h
ImplementationFile=GrapicSetting.cpp
BaseClass=CDialog
Filter=D
LastObject=CGrapicSetting
VirtualFilter=dWC

