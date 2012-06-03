/***************************************************************
 * Name:      Digit_RecogApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2012-05-29
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "MainFrame.h"
#include "DigitRecog.h"

IMPLEMENT_APP(Digit_RecogApp);

bool Digit_RecogApp::OnInit()
{
    MainFrame* frame = new MainFrame(0L);

    frame->Show();

    return true;
}
