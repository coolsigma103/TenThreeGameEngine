#pragma once

#include <glm/glm.hpp>
#include <iostream>

namespace TTGE
{
    struct vertex
    {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texCoords;

        vertex(const glm::vec3 &pos, const glm::vec3 &norm, const glm::vec2 &tex)
            : position(pos), normal(norm), texCoords(tex) {}
    };
}