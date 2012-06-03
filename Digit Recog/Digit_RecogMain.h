/***************************************************************
 * Name:      Digit_RecogMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2012-05-29
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef DIGIT_RECOGMAIN_H
#define DIGIT_RECOGMAIN_H



#include "Digit_RecogApp.h"


#include "GUIFrame.h"

class Digit_RecogFrame: public GUIFrame
{
    public:
        Digit_RecogFrame(wxFrame *frame);
        ~Digit_RecogFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};

#endif // DIGIT_RECOGMAIN_H
