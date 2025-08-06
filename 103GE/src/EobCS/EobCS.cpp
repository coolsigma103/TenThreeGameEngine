#include "EobCS.hpp"
#include <memory>
#include "entityManager.hpp"
#include "entity.hpp"
#include "componentManager.hpp"
#include "systemManager.hpp"

using namespace EobCS;

static EntityManager* currEM;
static ComponentManager* currCM;
static SystemManager* currSM;

EntityManager*& getCurrEM()
{
    return getCurrEM();
}
ComponentManager*& getCurrCM()
{
    return getCurrCM();
}
SystemManager*& getCurrSM()
{
    return getCurrSM();
}
// EntityManager
void EntityManager::use()
{
    getCurrEM() = this;
}
Entity* EntityManager::createEntity(Entity* parent)
{
    EntityID id = getNextID();
    auto newEntt = new Entity(id, parent);
    return newEntt;
}
void EntityManager::destroyEntity(Entity* entity)
{
    entities.erase(entity->entityID);
    freeIDs.push(entity->entityID);
    delete entity;
}
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