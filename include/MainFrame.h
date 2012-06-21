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

#define wxID_NumberStart 1010
#define wxID_Number0 1010
#define wxID_Number1 1011
#define wxID_Number2 1012
#define wxID_Number3 1013
#define wxID_Number4 1014
#define wxID_Number5 1015
#define wxID_Number6 1016
#define wxID_Number7 1017
#define wxID_Number8 1018
#define wxID_Number9 1019



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
		wxStaticText* m_staticText5;
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

        virtual void Learn1( wxCommandEvent& event );
        virtual void Learn2( wxCommandEvent& event );
        virtual void Learn3( wxCommandEvent& event );
        virtual void Learn4( wxCommandEvent& event );
        virtual void Learn5( wxCommandEvent& event );
        virtual void Learn6( wxCommandEvent& event );
        virtual void Learn7( wxCommandEvent& event );
        virtual void Learn8( wxCommandEvent& event );
        virtual void Learn9( wxCommandEvent& event );
        virtual void Learn0( wxCommandEvent& event );

        virtual void LearnNumber( int number );

        int numberOrderArray[10];



	public:
        void implementToolbar();
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Digit Recognization"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX|wxTAB_TRAVERSAL );
		~MainFrame();

};

#endif //__noname__
