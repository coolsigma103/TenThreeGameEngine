#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "utils.hpp"

namespace TTGE
{
    class Shader
    {
    public:
        GLuint ID;

        Shader() { ID = glCreateProgram(); }
        GLuint CreateShader(GLenum type, const char *source);
        void DeleteShader(GLuint shader)
        {
            glDeleteShader(shader);
        }
        GLuint LinkShader(GLuint &ID, std::vector<GLuint> shaders);
        void Bind() { glUseProgram(ID); }
        void Unbind() { glUseProgram(0); }
        void Delete() { 
            glDeleteProgram(ID); 
            ID = 0; 
        }

        void setFloat(const char *uniform, GLfloat value) { glUniform1f(glGetUniformLocation(ID, uniform), value); }
        void setInt(const char *uniform, GLint value) { glUniform1i(glGetUniformLocation(ID, uniform), value); }
        void setUInt(const char *uniform, GLuint value) { glUniform1ui(glGetUniformLocation(ID, uniform), value); }
        void setVec2(const char *uniform, const glm::vec2 &value) { glUniform2fv(glGetUniformLocation(ID, uniform), 1, glm::value_ptr(value)); }
        void setVec3(const char *uniform, const glm::vec3 &value) { glUniform3fv(glGetUniformLocation(ID, uniform), 1, glm::value_ptr(value)); }
        void setVec4(const char *uniform, const glm::vec4 &value) { glUniform4fv(glGetUniformLocation(ID, uniform), 1, glm::value_ptr(value)); }
        void setMat2(const char *uniform, const glm::mat2 &value) { glUniformMatrix2fv(glGetUniformLocation(ID, uniform), 1, GL_FALSE, glm::value_ptr(value)); }
        void setMat3(const char *uniform, const glm::mat3 &value) { glUniformMatrix3fv(glGetUniformLocation(ID, uniform), 1, GL_FALSE, glm::value_ptr(value)); }
        void setMat4(const char *uniform, const glm::mat4 &value) { glUniformMatrix4fv(glGetUniformLocation(ID, uniform), 1, GL_FALSE, glm::value_ptr(value)); }

        GLfloat getFloat(const char *uniform, GLfloat *value) { glGetUniformfv(ID, glGetUniformLocation(ID, uniform), value); }
        GLint getInt(const char *uniform, GLint *value) { glGetUniformiv(ID, glGetUniformLocation(ID, uniform), value); }
        GLuint getUInt(const char *uniform, GLuint *value) { glGetUniformuiv(ID, glGetUniformLocation(ID, uniform), value); }
        glm::vec2 getVec2(const char *uniform, glm::vec2 &value) { glGetUniformfv(ID, glGetUniformLocation(ID, uniform), glm::value_ptr(value)); }
        glm::vec3 getVec3(const char *uniform, glm::vec3 &value) { glGetUniformfv(ID, glGetUniformLocation(ID, uniform), glm::value_ptr(value)); }
        glm::vec4 getVec4(const char *uniform, glm::vec4 &value) { glGetUniformfv(ID, glGetUniformLocation(ID, uniform), glm::value_ptr(value)); }
        glm::mat2 getMat2(const char *uniform, glm::mat2 &value) { glGetUniformfv(ID, glGetUniformLocation(ID, uniform), glm::value_ptr(value)); }
        glm::mat3 getMat3(const char *uniform, glm::mat3 &value) { glGetUniformfv(ID, glGetUniformLocation(ID, uniform), glm::value_ptr(value)); }
        glm::mat4 getMat4(const char *uniform, glm::mat4 &value) { glGetUniformfv(ID, glGetUniformLocation(ID, uniform), glm::value_ptr(value)); }
    };
}

#endif