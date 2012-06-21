///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 21 2009)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __noname__
#define __noname__

class Board;

#include <wx/statusbr.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/toolbar.h>
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////
#define wxID_CleanToolbar 1000
#define wxID_LearnToolbar 1001

class UpdateDisplayClass;
///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame
{
	private:

	protected:
		wxStatusBar* m_statusBar1;
		wxToolBar* m_toolBar3;
		wxStaticText* m_resultLabel;
		Board* m_panel2;
		wxMenuBar* m_menubar1;
		wxMenu* Menu_Edit;
		wxMenu* Menu_Learn;
		wxMenu* Menu_Help;
        UpdateDisplayClass *updateTimer;

        // Virtual event handlers
		virtual void Clean( wxCommandEvent& event );
		virtual void Learn( wxCommandEvent& event );
		virtual void Help( wxCommandEvent& event ) ;
		virtual void About( wxCommandEvent& event );

	public:

		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Digit Recognization"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 300,400 ), long style = wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX|wxTAB_TRAVERSAL );
		~MainFrame();

};

#endif //__noname__
