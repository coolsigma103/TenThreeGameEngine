#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <typeindex>
#include "EobCS.hpp"
#include "entity.hpp"

namespace EobCS
{
    class System
    {
       public:
        std::vector<std::shared_ptr<Entity>> entities;

        virtual void update(float dt) = 0;
    };

    class SystemManager
    {
        std::unordered_map<std::type_index, std::shared_ptr<System>> systems;
        std::unordered_map<std::type_index, Signature> signatures;

       public:
        SystemManager()
        {
            use();
        }
        void use();
        template <typename T>
        std::shared_ptr<T> registerSystem(Signature sig);

        void entitySignatureChanged(std::shared_ptr<Entity> entity);

        template <typename T>
        Signature getSignature();

        std::unordered_map<std::type_index, std::shared_ptr<System>> getSystems()
        {
            return systems;
        }
    };
    static SystemManager *currSM = nullptr;
    inline SystemManager *&getCurrSM()
    {
        return getCurrSM();
    }
}  // namespace EobCS

#endif