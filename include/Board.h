#ifndef BOARD_H
#define BOARD_H

#include <wx/wx.h>

#define width 600
#define height 220

#define w_cells 50
#define h_cells 20

class Board : public wxPanel
{

public:
    Board(wxFrame *parent);

    void cleanCanvas();

protected:
    void OnPaint(wxPaintEvent& event);

    void OnMouseLeftDownEvent(wxMouseEvent& event);
    void OnMouseLeftUpEvent(wxMouseEvent& event);
    void OnMouseMoveEvent(wxMouseEvent& event);

    void convertPosition(int x,int y,int &cell_x,int &cell_y);

    void updateDrawing();

private:
    wxStatusBar *m_stsbar;
    bool mouseDown;
    char data[w_cells][h_cells];
};

#endif
