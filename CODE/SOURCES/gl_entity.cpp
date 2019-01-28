#include "gl_entity.h"

GL_Entity :: GL_Entity()
{

}

GL_Entity::~GL_Entity()
{
	
}

void GL_Entity::LoadData(float* vertices,int size,unsigned int* indices,int count)
{

 //--------VAO-----------
  VAO.Gen();

 //--------VBO ------	
  VBO.Gen(vertices , size);

 //---------IB---------
  IBO.Gen(indices, count );
  
 //--------layout--------
  VertexBufferLayout layout;
  layout.Push<float>(3);

 //--------attaching VB and (its)layout to VA---  
  VAO.AddBuffer(VBO,layout);

}

void GL_Entity::Bind()
{
	//---------bind--------------
	VBO.Bind();
    VAO.Bind();
    IBO.Bind();
   
}

void GL_Entity::UnBind()
{
	//---------unbind--------------
    VBO.UnBind();
    VAO.UnBind();
    IBO.UnBind();
}

unsigned int GL_Entity::GetIndices()
{
	return IBO.GetCount();
}

void GL_Entity::ClearData()
{

}

void Delete()
{
	
}