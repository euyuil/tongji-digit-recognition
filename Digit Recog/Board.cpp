#include "Board.h"

Board::Board(wxFrame *parent)
       : wxPanel(parent, wxID_ANY, wxDefaultPosition,
             wxDefaultSize, wxBORDER_NONE)
{

    m_stsbar = parent->GetStatusBar();

    Connect(wxEVT_PAINT, wxPaintEventHandler(Board::OnPaint));
    Connect(wxEVT_LEFT_DOWN, wxMouseEventHandler(Board::OnMouseLeftDownEvent));
    Connect(wxEVT_LEFT_UP, wxMouseEventHandler(Board::OnMouseLeftUpEvent));
    Connect(wxEVT_MOTION, wxMouseEventHandler(Board::OnMouseMoveEvent));

    cleanCanvas();

    mouseDown = false;
}

void Board::cleanCanvas()
{
    for( int i = 0; i < w_cells ; i++ )
    {
        for( int j = 0; j < h_cells ; j++ )
        {
            data[i][j] = ' ';
        }
    }
}

void Board::OnMouseMoveEvent(wxMouseEvent& event)
{
    if(event.GetX() < 0 || event.GetY() < 0 )
        return;
    if(event.GetX() > width || event.GetY() > height )
        return;
    wxString s = wxString::Format(wxT("(%d,%d)"),event.GetX(),event.GetY());

    m_stsbar->SetStatusText(s);

    if(mouseDown)
    {
        int x,y;
        convertPosition(event.GetX(),event.GetY(),x,y);
        data[x][y] = '*';
        updateDrawing();
    }

}

void Board::OnMouseLeftUpEvent(wxMouseEvent& event)
{
    mouseDown = false;
}

void Board::OnMouseLeftDownEvent(wxMouseEvent& event)
{
    mouseDown = true;
}

void Board::updateDrawing()
{
    wxPaintDC dc(this);

    wxSize size = GetClientSize();

    dc.Clear();
    PrepareDC(dc);

    wxPen pen(wxColour(0, 0, 0));
    pen.SetCap(wxCAP_PROJECTING);
    dc.SetPen(pen);
    dc.SetBrush(*wxBLACK_BRUSH);

    float w = width / w_cells;
    float h = height / h_cells;

    for( int i = 0; i < w_cells ; i++ )
    {
        for( int j = 0; j < h_cells ; j++ )
        {
            if(data[i][j] != ' ')
            {
                dc.DrawRectangle( w * i, h * j, w, h );

            }
        }
    }

}

void Board::convertPosition(int x,int y,int &cell_x,int &cell_y)
{
    float w = width / w_cells;
    float h = height / h_cells;
    cell_x = x / w;
    cell_y = y / h;
}


void Board::OnPaint(wxPaintEvent& event)
{
    updateDrawing();
}

