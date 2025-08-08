#include "EobCS.hpp"
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
Entity& EntityManager::createEntity(Entity& parent)
{
    EntityID id = getNextID();
    entities[id] = Entity(id, parent);
    return entities[id];
}
Entity& EntityManager::createEntity(Entity* entity)
{
    EntityID id = getNextID();
    entity->entityID = id;
    entities[id] = *entity;
    delete entity;
    return entities[id];
}
void EntityManager::destroyEntity(Entity& entity)
{
    freeIDs.push(entity.entityID);
    entities.erase(entity.entityID);
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
void ComponentManager::setComponent(Entity& entity, const T& component)
{
    getComponent<T>(entity) = component;
}
template <typename T>
void ComponentManager::removeComponent(Entity& entity)
{
    auto components = getComponentArray<T>()->components;
    delete components[entity.getEntityID()];
    components.erase(entity.getEntityID());
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

void SystemManager::entitySignatureChanged(Entity& entity)
{
    for (auto [name, signature] : signatures)
    {
        std::vector<Entity*>& entities = systems[name]->entities;
        if ((entity.signature & signature) == signature)
        {
            systems[name]->entities.push_back(&entity);
        }
        else
        {
            auto it = std::find(entities.begin(), entities.end(), &entity);
            if (it != systems[name]->entities.end())
            {
                delete *it;
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
Entity::Entity(Entity& parent) : parent(&parent)
{
    getCurrEM()->createEntity(this);
}
Entity::Entity() : parent(&getRoot())
{
    getCurrEM()->createEntity(this);
}
// entity