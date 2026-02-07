#include "wallGL.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

struct DrawGL::wallGLP{
    GLFWwindow* window;
    int x,y;
    glm::mat4 View,Projection;
};

struct DrawGL::renderData{
    GLuint VAO = 0;
    GLuint VBO = 0;
    GLuint EBO = 0;
    GLuint shaderprogram = 0;
    size_t indexCount = 0;
    int modelid;
};

struct DrawGL::shader {
    GLuint ShaderProgram;
    int identifiquer;
};
DrawGL::DrawGL(GLFWwindow* window)
: data(std::make_unique<wallGLP>())
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }
    data ->window = window;

}

void DrawGL::init(int X,int Y)
{
    glEnable(GL_DEPTH_TEST);
    glViewport(0,0,X,Y);
    data -> x = X;
    data -> y = Y;
}

renderact DrawGL::chargeSTL(const float* vertizes,size_t vertexSize,const unsigned int* indices,size_t indexCout,int model){
    renderData rd;
    //Creo buffers VAO,VBO,EBO
    CreateBuffers(&rd,vertizes,vertexSize,indices,indexCout * sizeof(unsigned int));

    //creamos un id interno para el model
    rd.modelid = model;
    //Creo su shader program
    MeshHandle id = nextId++;
    RenderMeshes[id] = std::move(rd);
    return renderact::render_success;
}


void DrawGL::CreateBuffers(renderData* render,const float* vertices, size_t vertSize,const unsigned int* indices, size_t indexSize){
    glGenVertexArrays(1,&render->VAO);
    glGenBuffers(1,&render -> VBO);
    glGenBuffers(1,&render -> EBO);

    glBindVertexArray(render -> VAO);

    // El VAO we :3
    glBindBuffer(GL_ARRAY_BUFFER, render ->VBO);
    glBufferData(GL_ARRAY_BUFFER,vertSize,vertices,GL_STATIC_DRAW);
    
    // EL EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, render -> EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexSize, indices,GL_STATIC_DRAW);
    render -> indexCount = indexSize / sizeof(unsigned int);

    glVertexAttribPointer(0,3, GL_FLOAT,GL_FALSE, 6 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE, 6 * sizeof(float), (void*) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

GLuint DrawGL::createprogram(){
    const char* vertexsrc = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aColor;

    uniform mat4 MVP;
    out vec3 vColor;

    void main()
    {
    vColor = aColor;
    gl_Position = MVP * vec4(aPos, 1.0);
    }
    )";
    const char* fragmentsrc = R"(
    #version 330 core
    in vec3 vColor;
    out vec4 FragColor;

    void main()
    {
    FragColor = vec4(vColor, 1.0);
    }
    )";

    //Creacion del vertex shader y el fragment shader
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs,1,&vertexsrc,nullptr);
    glCompileShader(vs);
    
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs,1,&fragmentsrc,nullptr);
    glCompileShader(fs);

    //Verificar los cambios
    int sucess;
    char infolog[1024];
    glGetShaderiv(vs,GL_COMPILE_STATUS,&sucess);
    if (!sucess)
    {
        glGetShaderInfoLog(vs,1024,nullptr,infolog);
        throw std::runtime_error(infolog);
    }

    glGetShaderiv(fs,GL_COMPILE_STATUS,&sucess);
    if (!sucess)
    {
        glGetShaderInfoLog(fs,1024,nullptr,infolog);
        throw std::runtime_error(infolog);
    }

    //crear el shader program
    GLuint program = glCreateProgram();
    glAttachShader(program,vs);
    glAttachShader(program,fs);
    glLinkProgram(program);

    glGetProgramiv(program,GL_LINK_STATUS,&sucess);
    if (!sucess)
    {
        glGetProgramInfoLog(program,1024,nullptr,infolog);
        throw std::runtime_error(infolog);
    }
    
    //eliminamos los shaders poque ya estan linkeados al programa
    
    glDeleteShader(vs);
    glDeleteShader(fs);

    //retornamos el program shader
    return program;
}

void DrawGL::beginframe(const glm::mat4& View,const glm::mat4& projection) {
    data -> View = View;
    data -> Projection = projection;
}

Action DrawGL::draw(const glm::mat4& model,int idmodel,int shader = 1) {

}