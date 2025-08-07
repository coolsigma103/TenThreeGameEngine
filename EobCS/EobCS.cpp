#include "EobCS.hpp"
#include <memory>

#include "entityManager.hpp"
#include "entity.hpp"
#include "componentManager.hpp"
#include "systemManager.hpp"

#include "scene.hpp"

using namespace EobCS;

// EntityManager
void EntityManager::use()
{
    getCurrEM() = this;
}
Entity* EntityManager::createEntity(Entity* parent)
{
    EntityID id = getNextID();
    auto newEntt = new Entity(id, parent);
    entities[id] = newEntt;
    return newEntt;
}
void EntityManager::destroyEntity(Entity* entity)
{
    entities.erase(entity->entityID);
    freeIDs.push(entity->entityID);
    delete entity;
}
// EntityManager

// ComponentManager
void ComponentManager::use()
{
    getCurrCM() = this;
}
template <typename T>
void ComponentManager::registerComponent(ComponentType type)
{
    const char* name = typeid(T).name();
    auto newCompArr = std::make_shared<ComponentArray<T>>();
    newCompArr->type = type;
    componentArrays[name] = newCompArr;
}
template <typename T>
void ComponentManager::setComponent(Entity* entity, const T& component)
{
    getComponent<T>(entity) = component;
}
template <typename T>
void ComponentManager::removeComponent(Entity* entity)
{
    auto components = getComponentArray<T>()->components;
    delete components[entity->getEntityID()];
    components.erase(entity->getEntityID());
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
    const char* name = typeid(T).name();
    signatures[name] = sig;
    auto newsys = std::make_shared<T>();
    systems[name] = newsys;
    return newsys;
}

void SystemManager::entitySignatureChanged(Entity* entity)
{
    for (auto [name, signature] : signatures)
    {
        if ((entity->signature & signature) == signature)
        {
            systems[name]->entities.insert(entity);
        }
        else
        {
            auto it = systems[name]->entities.find(entity);
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
    const char* name = typeid(T).name();
    return signatures[name];
}
// SystemManager

// entity
Entity::Entity(Entity* parent) : parent(parent)
{
    EntityID id = getCurrEM()->getNextID();
    entityID = id;
    getCurrEM()->entities[id] = this;
}
// entity