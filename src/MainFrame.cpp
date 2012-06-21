///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Board.h"

#include "MainFrame.h"
#include <wx/aboutdlg.h>
#include <wx/numdlg.h>
///////////////////////////////////////////////////////////////////////////

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
	m_toolBar3->AddTool( wxID_CleanToolbar, wxT("Clean"), wxBitmap( wxT("edit_clear.png") ), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	m_toolBar3->Realize();

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_resultLabel = new wxStaticText( this, wxID_ANY, wxT("Draw A Number"), wxDefaultPosition, wxDefaultSize, 0 );
	m_resultLabel->Wrap( -1 );
	m_resultLabel->SetFont( wxFont( 20, 70, 90, 92, false, wxEmptyString ) );

	bSizer3->Add( m_resultLabel, 0, wxALL, 5 );

	m_panel2 = new Board( this );
	bSizer3->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );

	this->SetSizer( bSizer3 );
	this->Layout();

    // Connect Events
	this->Connect( m_menuItem_Clean->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::Clean ) );
	this->Connect( m_menuItem_learn->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::Learn ) );
	this->Connect( m_menuItem_help->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::Help ) );
	this->Connect( m_menuItem_about->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::About ) );
    this->Connect( wxID_CleanToolbar, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::Clean ));

}

MainFrame::~MainFrame()
{
    // Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::Clean ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::Learn ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::Help ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::About ) );
}

void MainFrame::Clean( wxCommandEvent& event )
{
    printf("clean\n");
    m_panel2->cleanCanvas();
}
void MainFrame::Learn( wxCommandEvent& event )
{
    int number =  wxGetNumberFromUser( wxT("Which digit are you drawing?"), wxT("Input a digit"), wxT("Number?"), 0, 0, 9, this, wxDefaultPosition);
    printf("learn %d\n",number);
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
