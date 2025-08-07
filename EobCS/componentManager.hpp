#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include "EobCS.hpp"
#include "entity.hpp"

namespace EobCS
{
    template <typename T>
    class ComponentArray
    {
        ComponentType type;
        std::unordered_map<EntityID, T *> components;
        friend class ComponentManager;
    };

    class ComponentManager
    {
        std::unordered_map<const char *, std::shared_ptr<void>> componentArrays;
        template <typename T>
        std::shared_ptr<ComponentArray<T>> getComponentArray()
        {
            const char *name = typeid(T).name();
            return componentArrays[name];
        }

       public:
        ComponentManager()
        {
            use();
        }
        void use();
        template <typename T>
        void registerComponent(ComponentType type);

        template <typename T>
        void setComponent(Entity *entity, const T &component);

        template <typename T>
        T *&getComponent(Entity *entity)
        {
            auto component = getComponentArray<T>()->components[entity->getEntityID()];
            return component;
        }

        template <typename T>
        void removeComponent(Entity *entity);

        template <typename T>
        ComponentType getComponentType() const
        {
            return getComponentArray<T>().type;
        }
    };

    static ComponentManager *currCM = nullptr;
    inline ComponentManager *&getCurrCM()
    {
        return getCurrCM();
    }
}  // namespace EobCS

#endif