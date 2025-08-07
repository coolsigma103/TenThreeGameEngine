#ifndef SCENE_H
#define SCENE_H

#include "EobCS.hpp"
#include "entityManager.hpp"
#include "entity.hpp"
#include "componentManager.hpp"
#include "systemManager.hpp"

namespace EobCS
{
    class Scene : public Entity
    {
        EntityManager em;
        ComponentManager cm;
        SystemManager sm;

       public:
        Scene() : Entity() {}
        void update();
    };
}  // namespace EobCS

#endif