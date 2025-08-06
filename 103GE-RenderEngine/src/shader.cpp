#include "shader.hpp"

namespace TTGE
{
    GLuint Shader::CreateShader(GLenum type, const char *source)
    {
        GLuint ID = glCreateShader(type);
        glShaderSource(ID, 1, &source, nullptr);
        glCompileShader(ID);

        GLint success;
        glGetShaderiv(ID, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            char infoLog[512];
            glGetShaderInfoLog(ID, 512, nullptr, infoLog);
            std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n"
                      << infoLog << std::endl;
        }
        return ID;
    }

    GLuint Shader::LinkShader(GLuint &ID, std::vector<GLuint> shaders)
    {
        for (GLuint shader : shaders)
        {
            glAttachShader(ID, shader);
        }
        glLinkProgram(ID);

        GLint success;
        glGetProgramiv(ID, GL_LINK_STATUS, &success);
        if (!success)
        {
            char infoLog[512];
            glGetProgramInfoLog(ID, 512, nullptr, infoLog);
            std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                      << infoLog << std::endl;
        }
        return ID;
    }
}