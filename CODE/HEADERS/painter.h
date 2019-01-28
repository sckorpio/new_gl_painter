#ifndef PAINTER_H
#define PAINTER_H
#include "renderer.h"
#include <math.h>

#define PI 3.14159265

class Painter
{
   private:

    Renderer RND;

   	float px=0,py=0; //pen coordinates

    int curve_points=100;
    
    
   public:
    Painter();
    ~Painter();
    void ReadyShader();
    void MoveTo(float x,float y);
    void LineWidth(float d);
    void Rectangle(float x2,float y2);
    void LineTo(float x2,float y2);
    void Circle(float x,float y,float r);
    void Fill();
    void ClosePath();
    void SelectColor(float R,float G,float B,float A);
    void Stroke();	
    void Clear(float R,float G,float B);
    void Clear(float R,float G,float B,float A);
    void Check();
};

#endif // PAINTER_H