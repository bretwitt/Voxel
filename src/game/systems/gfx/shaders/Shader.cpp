#include "Shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

void Shader::use() {
    if(shaderProg != -1)
    {
        glUseProgram(shaderProg);
    }
}

void Shader::loadFromFile(char * vertexPath, char * fragPath) {
    int success = 0;
    char infoLog[512];

    std::ifstream vertStream, fragStream;
    std::stringstream vertBufferStream, fragBufferStream;

    vertStream.open(vertexPath);
    fragStream.open(fragPath);

    vertBufferStream << vertStream.rdbuf();
    fragBufferStream << fragStream.rdbuf();

    std::string vertexSource = vertBufferStream.str();
    std::string fragSource = fragBufferStream.str();

    const char * vertexSourceCStr = vertexSource.c_str();
    const char * fragSourceCStr = fragSource.c_str();

    vertStream.close();
    fragStream.close();

    unsigned int vertShader_ID;
    unsigned int fragShader_ID;

    vertShader_ID = glCreateShader(GL_VERTEX_SHADER);
    fragShader_ID = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertShader_ID, 1, &vertexSourceCStr, NULL);
    glCompileShader(vertShader_ID);

    glGetShaderiv(vertShader_ID, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(vertShader_ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    glShaderSource(fragShader_ID, 1, &fragSourceCStr, NULL);
    glCompileShader(fragShader_ID);

    if(!success) {
        glGetShaderInfoLog(fragShader_ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    shaderProg = glCreateProgram();
    glAttachShader(shaderProg,vertShader_ID);
    glAttachShader(shaderProg,fragShader_ID);
    glLinkProgram(shaderProg);

    glGetProgramiv(shaderProg, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProg, 512, NULL, infoLog);
        std::cout << "::ERROR LINKING SHADER PROGRAM::\n" << infoLog << std::endl;
    }

    glDeleteShader(vertShader_ID);
    glDeleteShader(fragShader_ID);
}

void Shader::setUniformMat4(const GLchar *name, glm::mat4 mat4)
{
    int loc = glGetUniformLocation(shaderProg, name);
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mat4));
}

void Shader::setUniformVec3(const GLchar * name, glm::vec3 vec) {
    int loc = glGetUniformLocation(shaderProg, name);
    glUniform3fv(loc, 1, glm::value_ptr(vec));
}

void Shader::setUniformInt(const GLchar * name, int i) {
    int loc = glGetUniformLocation(shaderProg, name);
    glUniform1i(loc, i);
}
