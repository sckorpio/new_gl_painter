#include "painter.h"
#include "debug.h"

Painter::Painter()
{
   DebugMessage("Constructor Painter");
  
}

Painter::~Painter()
{
    DebugMessage("Destructor Painter");
}

void Painter::ReadyShader()
{
	 RND.CreateShaderProgram();
}

void Painter::MoveTo(float x,float y)
{
	px=x; py=y;
	
	//std::cout<<"pen moved to "<<px<<","<<py<<std::endl;
}

void Painter::LineTo(float x,float y)
{
	RND.Add_Vertex(px,py);   // line from pen(x,y) ----P(x,y)
	RND.Add_Vertex(x,y);

    MoveTo(x,y);            // setting new
}


void Painter::Rectangle(float x,float y)
{
   RND.Add_Vertex(px,py);
   RND.Add_Vertex(px,y);
   RND.Add_Vertex(x,y);
   RND.Add_Vertex(x,py);

   RND.Select_Render_Mode(GL_QUADS);

   // pen coordinates remains same
}

void Painter::Fill()
{
	RND.Select_Fill(GL_FILL);
	RND.Select_Render_Mode(GL_POLYGON);
}

void Painter::ClosePath()
{
	RND.Select_Render_Mode(GL_LINE_LOOP);
}

void Painter::SelectColor(float R,float G,float B,float A)
{
	RND.Select_Color(R,G,B,A);
}

void Painter::Circle(float x,float y,float r)
{
	float angle=0;
	for(int i=0;i<curve_points;i++)
	{
        angle=( ((float)i)/curve_points )*(2*PI);
		RND.Add_Vertex( (x+r*cos(angle)) , (y+r*sin(angle)) );

		std::cout<<(x+r*cos(angle))<<","<<(y+r*sin(angle))<<std::endl; 
	}
	RND.Select_Render_Mode(GL_LINE_LOOP);
}

void Painter::Clear(float R,float G,float B)
{
	glClearColor(R,G,B,1);
    glClear(GL_COLOR_BUFFER_BIT); 
}

void Painter::Clear(float R,float G,float B,float A)
{
     glClearColor(R,G,B,A);
    glClear(GL_COLOR_BUFFER_BIT); 
}

void Painter::Stroke()
{
	RND.Draw();
}

void Painter::LineWidth(float d)
{
	RND.Select_Line_Width(d);
}