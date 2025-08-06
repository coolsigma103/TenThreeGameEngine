#pragma once

#include "EobCS.hpp"

namespace EobCS
{
    class Entity
    {
        std::vector<Entity *> children;
        Entity *parent;
        std::string name = "Entity";
        EntityID entityID;
        Signature signature;

        friend class EntityManager;
        friend class ComponentManager;
        friend class SystemManager;

       public:
        Entity(EntityID id, Entity *parent) : parent(parent), entityID(id) {}
        void addChild(Entity *entity)
        {
            children.push_back(entity);
        }
        std::vector<Entity *> getChildren()
        {
            return children;
        }
        EntityID getEntityID()
        {
            return entityID;
        }
    };
}  // namespace EobCS