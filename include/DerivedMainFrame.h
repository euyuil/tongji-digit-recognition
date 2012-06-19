#ifndef DERIVEDMAINFRAME_H_INCLUDED
#define DERIVEDMAINFRAME_H_INCLUDED

#include "MainFrame.h"

class DerivedMainFrame : public MainFrame
{
    protected:
        virtual void Clean( wxCommandEvent& event );
        virtual void Learn( wxCommandEvent& event );
        virtual void Help( wxCommandEvent& event );
        virtual void About( wxCommandEvent& event );
    public:
        DerivedMainFrame( wxWindow* parent );

};

#endif // DERIVEDMAINFRAME_H_INCLUDED
