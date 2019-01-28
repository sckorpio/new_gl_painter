#include "renderer.h"
#include "debug.h"

void GLClearError()
{
	while(glGetError()!=GL_NO_ERROR);
}

bool GLLogCall(const char* function,const char* file,int line)
{
	while(GLenum error =glGetError())
	{
		std::cout<<"[ OpenGL Error ] ("<< error <<")"<<function<<" "<< file<<" : "<<line<<std::endl;
	    return false;
	}
	return true;
}

//---------------------------------------------------
Renderer::Renderer()
{
	DebugMessage("Constructor Renderer");
	fill_mode=GL_LINE;
    render_mode=GL_LINES;
}

Renderer::~Renderer()
{
   DebugMessage("Destructor Renderer");
}

bool Renderer::Find_GL_Entity(unsigned int id)
{
	//TODO: find the gl_entity in map

}

void Renderer::Use_GL_Entity(unsigned int id)
{
	//current_gl_entity= gl_entity corresponding to id
}

void Renderer::Add_New_GL_Entity()
{
	current_gl_entity = new GL_Entity();
}

void Renderer::Add_Vertex(float x,float y,float z)
{
	vertices.push_back(x);
	vertices.push_back(y);
	vertices.push_back(z);

    unsigned int l=(unsigned int)(indices.size());
	indices.push_back((l));

}

void Renderer::Clear_Data()
{
	vertices.clear();
	indices.clear();
}

void Renderer::Add_Data_To_GL_Entity()
{
   current_gl_entity->LoadData(&vertices[0] , vertices.size()*sizeof(float) , 
   	                           &indices[0]  , indices.size() );

}

void Renderer::Select_Fill(GLenum fill)
{
	fill_mode=fill;
}

void Renderer::Select_Render_Mode(GLenum mode)
{
   render_mode=mode;
}

void Renderer::Select_Line_Width(float width)
{
	glLineWidth(width);
}

void Renderer::CreateShaderProgram()
{
	DebugMessage("generating Shader");
	SH.Gen("CODE/RES/SHADERS/basic_shader.shader");
	
	SH.UnBind();
}

void Renderer::Select_Color(float R,float G,float B,float A)
{
	SH.Bind();
	SH.SetUniform4f("u_Color",R,G,B,A);
    SH.UnBind();
}
    
void Renderer::Set_Default()
{
	fill_mode=GL_LINE;
    render_mode=GL_LINES;
    Select_Line_Width(1);
    Clear_Data();
}
    
void Renderer::Draw()
{
	glPolygonMode(GL_FRONT_AND_BACK, fill_mode);
    
    SH.Bind();

    //TODO: check if entity already exist
    //if not the add new
      Add_New_GL_Entity();
      //and load data
      Add_Data_To_GL_Entity();

    //else
     //pick entity from map and use that  

    current_gl_entity->Bind();

    //finally draw
     glDrawElements(render_mode,
     	            current_gl_entity->GetIndices(),
     	            GL_UNSIGNED_INT,
     	            0);

     //again set things to default for next entity
     Set_Default();

}
