#ifndef ROOT_H
#define ROOT_H

#include "EobCS.hpp"
#include "entityManager.hpp"
#include "entity.hpp"
#include "componentManager.hpp"
#include "systemManager.hpp"
#include "scene.hpp"

namespace EobCS
{
    class Root : public Entity
    {
        EntityManager em;
        ComponentManager cm;
        SystemManager sm;
        Scene* currentScene = nullptr;

       public:
        Root();
        void changeToScene(Scene* newScene)
        {
            currentScene = newScene;
        }
    };
    inline Root root = Root();
    inline Root& getRoot()
    {
        return root;
    }
}  // namespace EobCS

#endif