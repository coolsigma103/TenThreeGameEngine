#pragma once

#include "EobCS.hpp"

namespace EobCS
{
    class Entity
    {
        std::vector<std::shared_ptr<Entity>> children;
        std::shared_ptr<Entity> parent;
        std::string name = "Entity";
        Signature signature;
        std::unordered_map<std::type_index, std::unique_ptr<void>> components;

        friend class EntityManager;
        friend class ComponentManager;
        friend class SystemManager;

       protected:
        Entity(std::shared_ptr<Entity> parent) : parent() {}

       public:
        Entity(const Entity& other) : name(other.name), signature(other.signature)
        {
            if (other.parent)
                parent = other.parent;

            children = other.children;
        }
        ~Entity() = default;

        Entity& operator=(const Entity& other)
        {
            if (this != &other)
            {
                name = other.name;
                signature = other.signature;

                if (other.parent)
                    parent = other.parent;
                else
                    parent.reset();

                children.clear();
                children = other.children;
            }
            return *this;
        }

        // Move constructor
        Entity(Entity&& other) noexcept
            : children(std::move(other.children)),
              parent(std::move(other.parent)),
              name(std::move(other.name)),
              signature(std::move(other.signature)),
              components(std::move(other.components))
        {
        }

        // Move assignment operator
        Entity& operator=(Entity&& other) noexcept
        {
            if (this != &other)
            {
                children = std::move(other.children);
                parent = std::move(other.parent);
                name = std::move(other.name);
                signature = std::move(other.signature);
                components = std::move(other.components);
            }
            return *this;
        }

        std::string& getName()
        {
            return name;
        }
        void setName(const std::string name)
        {
            getName() = name;
        }

        std::shared_ptr<Entity> getParent()
        {
            return parent;
        }
        std::vector<std::shared_ptr<Entity>> getChildren()
        {
            return children;
        }
    };
}  // namespace EobCS