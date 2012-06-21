///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Board.h"
#include "Recognize.h"
#include "MainFrame.h"
#include <wx/aboutdlg.h>
#include <wx/numdlg.h>
#include <wx/timer.h>
///////////////////////////////////////////////////////////////////////////


class UpdateDisplayClass : public wxTimer
{
    public:
        wxStaticText* label;
		Board* board;
		MainFrame *mainFrame;
        void Notify()
        {
            if(board->isNeedDisplay())
            {
                label->SetLabel(wxString::Format(wxT("%c"),board->getRecognizedChar()));
                mainFrame->implementToolbar();
            }
        }
};


MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_menubar1 = new wxMenuBar( 0 );
	Menu_Edit = new wxMenu();
	wxMenuItem* m_menuItem_Clean;
	m_menuItem_Clean = new wxMenuItem( Menu_Edit, wxID_ANY, wxString( wxT("Clean") ) , wxEmptyString, wxITEM_NORMAL );
	Menu_Edit->Append( m_menuItem_Clean );

	m_menubar1->Append( Menu_Edit, wxT("Edit") );

	Menu_Learn = new wxMenu();
	wxMenuItem* m_menuItem_learn;
	m_menuItem_learn = new wxMenuItem( Menu_Learn, wxID_ANY, wxString( wxT("Learn Number") ) , wxEmptyString, wxITEM_NORMAL );
	Menu_Learn->Append( m_menuItem_learn );

	m_menubar1->Append( Menu_Learn, wxT("Learn") );

	Menu_Help = new wxMenu();
	wxMenuItem* m_menuItem_help;
	m_menuItem_help = new wxMenuItem( Menu_Help, wxID_ANY, wxString( wxT("Help") ) , wxEmptyString, wxITEM_NORMAL );
	Menu_Help->Append( m_menuItem_help );

	wxMenuItem* m_menuItem_about;
	m_menuItem_about = new wxMenuItem( Menu_Help, wxID_ANY, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	Menu_Help->Append( m_menuItem_about );

	m_menubar1->Append( Menu_Help, wxT("Help") );

	this->SetMenuBar( m_menubar1 );

	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	m_toolBar3 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	//m_toolBar3->AddTool( wxID_LearnToolbar, wxT("Learn"), wxBitmap( wxT("res/learn.png") ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );

    m_toolBar3->Realize();


	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

    wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 2, 2, 0, 0 );


    wxFlexGridSizer* fgSizer4;
	fgSizer4 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer4->SetFlexibleDirection( wxBOTH );
	fgSizer4->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("             "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	fgSizer4->Add( m_staticText5, 0, wxALL, 5 );


	m_resultLabel = new wxStaticText( this, wxID_ANY, wxT("?"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_resultLabel->Wrap( -1 );
	m_resultLabel->SetFont( wxFont( 200, 70, 90, 92, false, wxEmptyString ) );

    fgSizer4->Add( m_resultLabel, 0, wxALL, 5 );

	gSizer1->Add( fgSizer4, 1, wxEXPAND, 5 );


	m_panel2 = new Board( this );
	gSizer1->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );

	bSizer3->Add( gSizer1, 1, wxEXPAND, 5 );

	this->SetSizer( bSizer3 );
	this->Layout();

    // Connect Events
	this->Connect( m_menuItem_Clean->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::Clean ) );
	this->Connect( m_menuItem_learn->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::Learn ) );
	this->Connect( m_menuItem_help->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::Help ) );
	this->Connect( m_menuItem_about->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::About ) );
    this->Connect( wxID_CleanToolbar, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::Clean ));
    this->Connect( wxID_LearnToolbar, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::Learn ));


    updateTimer = new UpdateDisplayClass();
    updateTimer->board = m_panel2;
    updateTimer->label = m_resultLabel;
    updateTimer->mainFrame = this;
    updateTimer->Start(100);

    if(!LoadLearning())
    {
        printf("fuck! load error\n");
    }

    for(int i = 0; i < 10; i++)
    {
        numberOrderArray[i] = 9-i;
    }
    implementToolbar();

    this->Connect( wxID_Number0, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrame::Learn0 ));
    this->Connect( wxID_Number1, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrame::Learn1 ));
    this->Connect( wxID_Number2, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrame::Learn2 ));
    this->Connect( wxID_Number3, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrame::Learn3 ));
    this->Connect( wxID_Number4, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrame::Learn4 ));
    this->Connect( wxID_Number5, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrame::Learn5 ));
    this->Connect( wxID_Number6, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrame::Learn6 ));
    this->Connect( wxID_Number7, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrame::Learn7 ));
    this->Connect( wxID_Number8, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrame::Learn8 ));
    this->Connect( wxID_Number9, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrame::Learn9 ));


}

void MainFrame::implementToolbar()
{
    //m_toolBar3->AddTool( wxID_LearnToolbar, wxT("Learn"), wxBitmap( wxT("res/learn.png") ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
    m_toolBar3->ClearTools();
    for(int i = 0; i < 10; i++)
    {
        m_toolBar3->AddTool( wxID_NumberStart + numberOrderArray[i], wxString::Format(wxT("%d"),numberOrderArray[i]),wxString::Format(wxT("res/%d.png"),numberOrderArray[i]), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
    }
    m_toolBar3->Realize();
    m_toolBar3->AddSeparator();
    m_toolBar3->AddTool( wxID_CleanToolbar, wxT("Clean"), wxBitmap( wxT("res/edit_clear.png") ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
    m_toolBar3->Realize();
}


MainFrame::~MainFrame()
{
    // Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::Clean ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::Learn ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::Help ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::About ) );

    delete updateTimer;
}

void MainFrame::Clean( wxCommandEvent& event )
{
    printf("clean\n");
    m_panel2->cleanCanvas();
}

void MainFrame::Learn1( wxCommandEvent& event )
{
    LearnNumber(1);
}
void MainFrame::Learn2( wxCommandEvent& event )
{
    LearnNumber(2);
}
void MainFrame::Learn3( wxCommandEvent& event )
{
    LearnNumber(3);
}
void MainFrame::Learn4( wxCommandEvent& event )
{
    LearnNumber(4);
}
void MainFrame::Learn5( wxCommandEvent& event )
{
    LearnNumber(5);
}
void MainFrame::Learn6( wxCommandEvent& event )
{
    LearnNumber(6);
}
void MainFrame::Learn7( wxCommandEvent& event )
{
    LearnNumber(7);
}
void MainFrame::Learn8( wxCommandEvent& event )
{
    LearnNumber(8);
}
void MainFrame::Learn9( wxCommandEvent& event )
{
    LearnNumber(9);
}
void MainFrame::Learn0( wxCommandEvent& event )
{
    LearnNumber(0);
}

void MainFrame::LearnNumber( int number )
{
    if(m_panel2->Learn(number + '0'))
    {
        m_panel2->cleanCanvas();
        //m_panel2->SetLabel(wxString::Format(wxT("Now I know it is %c"),number + '0'));
    }
}
void MainFrame::Learn( wxCommandEvent& event )
{
    int number =  wxGetNumberFromUser( wxT("Which digit are you drawing?"), wxT("Input a digit"), wxT("Number?"), 0, 0, 9, this, wxDefaultPosition);
    printf("learn %d\n",number);
    LearnNumber(number);
}
void MainFrame::Help( wxCommandEvent& event )
{
    printf("help\n");
    wxAboutDialogInfo info;
    info.SetName(_("Digit Recognization"));
    info.SetDescription(_("Draw a number and enjoy~~^o^"));
    wxAboutBox(info);
}


void MainFrame::About( wxCommandEvent& event )
{
    printf("about\n");
    wxAboutDialogInfo info;
    info.SetName(_("Digit Recognization"));
    info.SetVersion(_("1.0.0"));
    info.SetDescription(_("This program does something great. Automatically recognize a handwritting numberic token."));
    info.SetCopyright(_T("(C) 2012 Euyuil & sbhhbs "));

    wxAboutBox(info);
}
