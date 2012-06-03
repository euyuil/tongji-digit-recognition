///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Board.h"

#include "MainFrame.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_toolBar1 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	m_toolBar1->AddTool( wxID_ANY, wxT("Clean"), wxBitmap( wxT("clean.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Clean"), wxEmptyString );
	m_toolBar1->AddSeparator();
	m_toolBar1->AddTool( wxID_ANY, wxT("Help"), wxBitmap( wxT("help.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Help"), wxEmptyString );
	m_toolBar1->Realize();

	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
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
	this->Connect( wxID_ANY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrame::CleanClicked ) );
	this->Connect( wxID_ANY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrame::HelpClicked ) );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrame::CleanClicked ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( MainFrame::HelpClicked ) );
}
