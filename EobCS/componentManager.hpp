#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <typeindex>
#include <unordered_map>
#include "EobCS.hpp"
#include "entity.hpp"

namespace EobCS
{
    class ComponentManager
    {
        std::unordered_map<std::type_index, ComponentType> componentTypes;

       public:
        ComponentManager() {}
        template <typename T>
        void registerComponent(ComponentType type)
        {
            componentTypes[typeid(T)] = type;
        }
        template <typename T>
        ComponentType getComponentType()
        {
            return componentTypes[typeid(T)];
        }

        template <typename T>
        T &getComponent(Entity &entity)
        {
            return entity.components[typeid(T)];
        }
        template <typename T>
        void setComponent(Entity &entity, const T &comp)
        {
            getComponent<T>(entity) = comp;
        }
        template <typename T>
        void removeComponent(Entity &entity);
    };

    static ComponentManager *currCM = nullptr;
    inline ComponentManager *&getCurrCM()
    {
        return currCM;
    }
}  // namespace EobCS

#endif