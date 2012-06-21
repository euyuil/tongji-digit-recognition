#include <cstdio>
using namespace std;
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
    CompleteDrawing();
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
        IncrementDrawing(x, y);
    }

}

void Board::OnMouseLeftUpEvent(wxMouseEvent& event)
{
    mouseDown = false;
}

void Board::OnMouseLeftDownEvent(wxMouseEvent& event)
{
    mouseDown = true;
    convertPosition(event.GetX(),event.GetY(),startPaintingX,startPaintingY);
}



// DDA's line algorithm
void Board::draw_line(int x0, int y0, int x1, int y1)
{
    wxClientDC dc(this);

    PrepareDC(dc);

    wxPen pen(wxColour(0, 0, 0));
    pen.SetCap(wxCAP_PROJECTING);
    dc.SetPen(pen);
    dc.SetBrush(*wxBLACK_BRUSH);

    float w = width / w_cells;
    float h = height / h_cells;


	int dx,dy,n,k;float xinc,yinc,x,y;
	dx=x1-x0;dy=y1-y0;
	if (abs(dx)>abs(dy))
		n=abs(dx);
	else
		n=abs(dy);
	xinc=(float)dx/n;	yinc=(float)dy/n;
	x=(float)x0;y=(float)y0;
	for (k=1;k<=n;k++)
	{
		//Drawpixel(int (x+0.5),int (y+0.5),color);
		dc.DrawRectangle( w * int (x+0.5), h * int (y+0.5), w, h );
        data[int (x+0.5)][int (y+0.5)] = '*';
		x+=xinc;	y+=yinc;
	}

}



void Board::IncrementDrawing(int x, int y)
{
    draw_line(startPaintingX,startPaintingY,x,y);
    startPaintingX = x;
    startPaintingY = y;
}

void Board::CompleteDrawing()
{
    wxClientDC dc(this);

    // wxSize size = GetClientSize();

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
    printf("onpaint\n");
    CompleteDrawing();
}

