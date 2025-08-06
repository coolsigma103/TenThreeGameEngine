#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>
#include <stb/stb_image.h>
#include "shader.hpp"

namespace TTGE
{
    class Texture
    {
    public:
        GLuint ID;
        GLenum type;
        Texture(GLenum slot);
        Texture(const char *image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

        void texUnit(Shader &shader, const char *uniform, GLuint unit);

        void Bind() { glBindTexture(type, ID); }

        void Unbind() { glBindTexture(type, 0); }

        void Delete()
        {
            glDeleteTextures(1, &ID);
            ID = 0;
        }
    };
}

#endif