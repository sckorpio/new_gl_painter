#ifndef RENDERER_H
#define RENDERER_H
#include <GL/glew.h>  
#include <GL/gl.h>
#include <signal.h> 

#include <vector>

#include "gl_entity.h"
#include "shader.h"
//---------------Error handling(if needed)----------------------

 #define ASSERT(x) if (!(x)) raise(SIGINT);
 
 #define GLCall(x) GLClearError();\
   x;\
   ASSERT(GLLogCall(#x,__FILE__,__LINE__))



void GLClearError();
bool GLLogCall(const char* function,const char* file,int line);

//--------------------------------------------------------------

class Renderer
{
private:   
    std::vector<float> vertices;          // for vertex data
    std::vector<unsigned int> indices;    //for indices data

	GLenum render_mode;                   //mode for render
    GLenum fill_mode;                     //mode for filling
    
     Shader SH;                           //Shader

	// TODO: map of <id,gl_entity>
    

	GL_Entity* current_gl_entity;

public:

	Renderer();

	~Renderer();

	void CreateShaderProgram();
  
    bool Find_GL_Entity(unsigned int id);
	
	void Use_GL_Entity(unsigned int id);

    void Add_New_GL_Entity();

	void Add_Vertex(float x,float y,float z=0.0f);
	
	void Clear_Data();

	void Add_Data_To_GL_Entity();

	void Select_Fill(GLenum fill);

	void Select_Render_Mode(GLenum mode);

    void Select_Color(float R,float G,float B,float A);

    void Select_Line_Width(float width);
    
    void Set_Default();

	void Draw();


};
#endif // RENDERER_H