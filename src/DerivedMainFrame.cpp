#include "DerivedMainFrame.h"

void DerivedMainFrame::Clean( wxCommandEvent& event ) { event.Skip(); }
void DerivedMainFrame::Learn( wxCommandEvent& event ) { event.Skip(); }
void DerivedMainFrame::Help( wxCommandEvent& event ) { event.Skip(); }
void DerivedMainFrame::About( wxCommandEvent& event ) { event.Skip(); }

DerivedMainFrame::DerivedMainFrame( wxWindow* parent ): MainFrame( parent )
{

}
