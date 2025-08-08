#include "EobCS.hpp"
#include <algorithm>
#include <memory>

#include "entityManager.hpp"
#include "entity.hpp"
#include "componentManager.hpp"
#include "systemManager.hpp"
#include "scene.hpp"
#include "root.hpp"

using namespace EobCS;

// EntityManager
void EntityManager::use()
{
    getCurrEM() = this;
}
std::shared_ptr<Entity> EntityManager::createEntity(std::shared_ptr<Entity> parent)
{
    auto newentt = std::make_shared<Entity>(parent);
    entities.push_back(newentt);
    return newentt;
}
void EntityManager::destroyEntity(std::shared_ptr<Entity> entity)
{
    entities.erase(std::find(entities.begin(), entities.end(), entity));
}
// EntityManager

// ComponentManager
template <typename T>
void ComponentManager::removeComponent(Entity& entity)
{
    entity.components.erase(typeid(T));
}

// ComponentManager

// SystemManager
void SystemManager::use()
{
    getCurrSM() = this;
}
template <typename T>
std::shared_ptr<T> SystemManager::registerSystem(Signature sig)
{
    signatures[typeid(T)] = sig;
    auto newsys = std::make_shared<T>();
    systems[typeid(T)] = newsys;
    return newsys;
}

void SystemManager::entitySignatureChanged(std::shared_ptr<Entity> entity)
{
    for (auto [name, signature] : signatures)
    {
        auto& entities = systems[name]->entities;
        if ((entity->signature & signature) == signature)
        {
            entities.push_back(entity);
        }
        else
        {
            auto it = std::find(entities.begin(), entities.end(), &entity);
            if (it != systems[name]->entities.end())
            {
                systems[name]->entities.erase(it);
            }
        }
    }
}

template <typename T>
Signature SystemManager::getSignature()
{
    return signatures[typeid(T)];
}
// SystemManager

// entity
// entity