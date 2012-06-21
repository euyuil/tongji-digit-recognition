#ifndef BOARD_H
#define BOARD_H

#include <wx/wx.h>

#define width 300
#define height 396

#define w_cells 50
#define h_cells 66

class Board : public wxPanel
{

public:
    Board(wxFrame *parent);

    void cleanCanvas();

    const char *getData();

    bool Learn(char c);

    bool isNeedDisplay();

    char getRecognizedChar();

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
    bool needDisplay;
    char recognizedChar;
    int startPaintingX,startPaintingY;
    char data[w_cells][h_cells];
};

#endif
