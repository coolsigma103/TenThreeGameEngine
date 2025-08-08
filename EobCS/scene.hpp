#ifndef SCENE_H
#define SCENE_H

#include "EobCS.hpp"
#include "entityManager.hpp"
#include "entity.hpp"
#include "componentManager.hpp"
#include "systemManager.hpp"

#include <fstream>

namespace EobCS
{
    class Scene : public Entity
    {
        EntityManager em;
        ComponentManager cm;
        SystemManager sm;

       public:
        Scene();
        void update(float delta)
        {
            for (auto [name, system] : sm.getSystems())
            {
                system->update(delta);
            }
        }
    };

    class PackedScene
    {
       public:
        void saveAsBinary() {}

        static Scene load(PackedScene packedScene) {}
    };
}  // namespace EobCS

#endif