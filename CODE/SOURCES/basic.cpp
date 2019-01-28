#include <GL/glew.h> 
#include <GL/glut.h>  
#include <GL/gl.h>
#include <iostream> 
#include <string> 

#include "mydrawing.h"

void init() 
{ 
    createpainter();
    

} 

void display() 
{  
     glClear(GL_COLOR_BUFFER_BIT); 

   drawingpage();
   glutSwapBuffers();

} 

void reshape(int width,int height)
{
	glViewport(0, 0, width, height);

}

int main(int argc, char** argv) 
{ 
  
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); 
    glutInitWindowSize(500, 500); 
    glutInitWindowPosition(100, 50); 
    glutCreateWindow("Modern OpenGL"); 
    glutReshapeFunc(reshape);
    glewInit(); 
    init(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
    return 0; 
} 

