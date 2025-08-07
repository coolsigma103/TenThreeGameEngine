#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "EobCS.hpp"
#include "entity.hpp"

namespace EobCS
{
    class EntityManager
    {
       private:
        EntityID nextID = 1;
        std::unordered_map<EntityID, Entity *> entities;
        std::queue<EntityID> freeIDs;

        EntityID getNextID()
        {
            if (freeIDs.empty())
                return nextID++;
            else
            {
                EntityID id = freeIDs.front();
                freeIDs.pop();
                return id;
            }
        }

        friend class Entity;

       public:
        EntityManager()
        {
            use();
        }
        void use();
        Entity *createEntity(Entity *parent = nullptr);
        void destroyEntity(Entity *entity);
        void setSignature(Entity *entity, Signature sig)
        {
            entity->signature = sig;
        }
        Signature getSignature(Entity *entity) const
        {
            return entity->signature;
        }
    };

    static EntityManager *currEM = nullptr;
    inline EntityManager *&getCurrEM()
    {
        return getCurrEM();
    }
}  // namespace EobCS

#endif