#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>

#include "shader.hpp"
#include "texture.hpp"

namespace TTGE
{
    struct Material
    {
        Texture *albedoMap = nullptr;
        Texture *metallicMap = nullptr;
        Texture *roughnessMap = nullptr;
        Texture *normalMap = nullptr;
        Texture *aoMap = nullptr;
        Texture *emissiveMap = nullptr;
        Texture *opacityMap = nullptr; 

        glm::vec3 albedoColor = glm::vec3(1.0f); // RGB color
        float metallic = 0.0f;                 // [0.0, 1.0]
        float roughness = 1.0f;                // [0.0, 1.0]
        float opacity = 1.0f;                  // [0.0, 1.0]
        float emissiveStrength = 0.0f;
    };
}

#endif