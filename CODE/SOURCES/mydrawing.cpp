#include "mydrawing.h"

Painter painter;

void createpainter()
{
   painter.ReadyShader();
   painter.MoveTo(0,0);
}


void linecheck()
{
   painter.LineWidth(2);
   painter.SelectColor(1,0,0,1);
   painter.MoveTo(0,0);
   painter.LineTo(0.4,0.4);
   painter.LineTo(0.4,0);
   painter.LineTo(0.8,0.4);
   painter.LineTo(0.8,-0.1);
  
   painter.Stroke();
}

void closedcheck()
{
   painter.LineWidth(2);
   painter.SelectColor(1,0,0,1);
   painter.MoveTo(0,-0.5);
   painter.LineTo(0.4,-0.2);
   painter.LineTo(0.4,-0.5);
   painter.LineTo(0.8,-0.2);
   painter.LineTo(0.8,-0.7);
   painter.ClosePath();
   
   painter.Stroke();
}

void closedfillcheck()
{
   painter.LineWidth(2);
   painter.SelectColor(1,0,0,1);
   painter.MoveTo(0,0.7);
   painter.LineTo(0.4,0.9);
   painter.LineTo(0.4,0.7);
   painter.LineTo(0.8,0.9);
   painter.LineTo(0.8,0.6);
   painter.ClosePath();
   painter.Fill();
   painter.Stroke();
}

void rectanglecheck()
{
	painter.SelectColor(1,0,1,1);
	painter.MoveTo(-0.8,-0.8);
	painter.Rectangle(-0.5,-0.4);
    painter.Fill();
	painter.Stroke();
}

void circlecheck()
{   
	painter.LineWidth(3);
	painter.SelectColor(0,0,1,1);
	painter.Circle(-0.5,0.5,0.3);
	painter.Stroke();
}

void gridcheck()
{
	painter.SelectColor(1,1,1,1);
	for(float i=-1;i<1;i=i+0.25)
	{
		painter.MoveTo(i,1);
		painter.LineTo(i,-1);
	}

	painter.Stroke();

	painter.SelectColor(1,1,1,1);
	for(float i=-1;i<1;i=i+0.25)
	{
		painter.MoveTo(1,i);
		painter.LineTo(-1,i);
	}

	painter.Stroke();
}
void drawingpage()
{  
	painter.Clear(0,0.52,0);

	 gridcheck();
   
    linecheck();

    rectanglecheck();

    circlecheck();

    closedcheck();

     closedfillcheck();
    

}

