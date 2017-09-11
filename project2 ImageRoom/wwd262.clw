; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWwd262View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "wwd262.h"
LastPage=0

ClassCount=6
Class1=CWwd262App
Class2=CWwd262Doc
Class3=CWwd262View
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=CDlgHistogram
Resource3=IDD_DIALOG1

[CLS:CWwd262App]
Type=0
HeaderFile=wwd262.h
ImplementationFile=wwd262.cpp
Filter=N

[CLS:CWwd262Doc]
Type=0
HeaderFile=wwd262Doc.h
ImplementationFile=wwd262Doc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CWwd262Doc

[CLS:CWwd262View]
Type=0
HeaderFile=wwd262View.h
ImplementationFile=wwd262View.cpp
Filter=C
LastObject=ID_SHOW_ORIGIN
BaseClass=CScrollView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=wwd262.cpp
ImplementationFile=wwd262.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

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
CommandCount=16

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
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_GRAY
Command10=ID_HISTOGRAM
Command11=ID_LINERTRANS
Command12=ID_EQUALIZE
Command13=ID_FT
Command14=ID_IFT
Command15=ID_FFT
Command16=ID_IFFT
Command17=ID_AVERAGEFILTER
Command18=ID_MEDIANFILTER
Command19=ID_GRADSHARP
Command20=ID_RAPLASSHARP
Command21=ID_LOW
Command22=ID_HIGH
Command23=ID_BLOW
Command24=ID_BHIGH
Command25=ID_SHOW_ORIGIN
CommandCount=25

[DLG:IDD_DIALOG1]
Type=1
Class=CDlgHistogram
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CDlgHistogram]
Type=0
HeaderFile=DlgHistogram.h
ImplementationFile=DlgHistogram.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlgHistogram

