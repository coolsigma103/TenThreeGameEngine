#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include "EobCS.hpp"
#include "entity.hpp"

namespace EobCS
{
    class EntityManager
    {
       private:
        std::vector<std::shared_ptr<Entity>> entities;

        friend class Entity;
        Entity &createEntity(Entity *entity);

       public:
        EntityManager()
        {
            use();
        }
        void use();
        std::shared_ptr<Entity> createEntity(std::shared_ptr<Entity> parent);
        void destroyEntity(std::shared_ptr<Entity> entity);
        void setSignature(Entity &entity, Signature sig)
        {
            entity.signature = sig;
        }
        Signature getSignature(Entity &entity) const
        {
            return entity.signature;
        }
    };

    static EntityManager *currEM = nullptr;
    inline EntityManager *&getCurrEM()
    {
        return getCurrEM();
    }
}  // namespace EobCS

#endif