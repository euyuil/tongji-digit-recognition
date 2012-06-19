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

    void CompleteDrawing();
    void IncrementDrawing(int x, int y);

private:
    void draw_line(int x1, int y1, int x2, int y2);
    wxStatusBar *m_stsbar;
    bool mouseDown;
    int startPaintingX,startPaintingY;
    char data[w_cells][h_cells];
};

#endif
