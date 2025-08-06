#include "texture.hpp"

namespace TTGE
{
    Texture::Texture(GLenum slot)
    {
        unsigned char whitePixel[] = {255, 255, 255, 255}; // RGBA: pure white, opaque

        type = GL_TEXTURE_2D;

        glGenTextures(1, &ID);

        glActiveTexture(slot);
        glBindTexture(GL_TEXTURE_2D, ID);

        // Set texture parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        // Upload the 1x1 pixel texture
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, whitePixel);
    }
    Texture::Texture(const char *image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
    {
        type = texType;

        int widthImg, heightImg, numColCh;

        stbi_set_flip_vertically_on_load(true);

        unsigned char *bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

        glGenTextures(1, &ID);

        glActiveTexture(slot);
        glBindTexture(texType, ID);


        glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
        glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


        glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);


        glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);

        glGenerateMipmap(texType);


        stbi_image_free(bytes);


        glBindTexture(texType, 0);
    }

    void Texture::texUnit(Shader &shader, const char *uniform, GLuint unit)
    {
        GLuint texUni = glGetUniformLocation(shader.ID, uniform);
        shader.Bind();
        glUniform1i(texUni, unit);
    }
}