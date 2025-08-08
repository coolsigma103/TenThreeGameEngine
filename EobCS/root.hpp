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
        EntityManager em = EntityManager(0);
        ComponentManager cm;
        SystemManager sm;
        Scene* currentScene = nullptr;

       public:
        Root()
        {
            getParent() = nullptr;
        }
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