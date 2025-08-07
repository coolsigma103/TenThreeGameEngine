#include <glad/glad.h>
#include <engine.hpp>

#include "EobCS/entityManager.hpp"
#include "EobCS/entity.hpp"
#include "EobCS/componentManager.hpp"
#include "EobCS/systemManager.hpp"

#include "EobCS/scene.hpp"

int main()
{
    init();
    run();
    destroy();
    return 0;
}