#ifndef MESH_MANAGER_H
#define MESH_MANAGER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include "vertex.hpp"
#include "material.hpp"
#include "shader.hpp"
#include "texture.hpp"

namespace TTGE
{
    struct Mesh
    {
        GLuint VAO;
        GLuint VBO;
        GLuint EBO;
        GLuint vertexCount;
        GLuint indexCount;
        Material material;
        glm::mat4 model = mat4(0.0f);

        Mesh(vertex *vertices, GLuint vertexCount, GLuint *indices, GLuint indexCount)
            : vertexCount(vertexCount), indexCount(indexCount)
        {
            glGenVertexArrays(1, &VAO);
            glGenBuffers(1, &VBO);
            glGenBuffers(1, &EBO);

            glBindVertexArray(VAO);

            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(vertex), vertices, GL_STATIC_DRAW);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(GLuint), indices, GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void *)offsetof(vertex, position));
            glEnableVertexAttribArray(0);

            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void *)offsetof(vertex, normal));
            glEnableVertexAttribArray(1);

            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void *)offsetof(vertex, texCoords));
            glEnableVertexAttribArray(2);

            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
        }
    };

    class MeshManager
    {
    public:
        Shader *defaultShader;
        MeshManager(Shader *defaultShader)
            : defaultShader(defaultShader) {}
        void renderMesh(const Mesh &mesh, Shader &shader, GLenum mode = GL_TRIANGLES)
        {
            shader.Bind();
            glBindVertexArray(mesh.VAO);
            shader.setMat4("model", mesh.model);
            glDrawElements(mode, mesh.indexCount, GL_UNSIGNED_INT, 0);
            glBindVertexArray(0);
            shader.Unbind();
        }
        void renderMesh(const Mesh &mesh, GLenum mode = GL_TRIANGLES) { renderMesh(mesh, *defaultShader, mode); }
    };
}

#endif