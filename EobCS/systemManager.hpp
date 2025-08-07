#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include "EobCS.hpp"
#include "entity.hpp"

namespace EobCS
{
    class System
    {
       public:
        std::unordered_set<Entity *> entities;

        virtual void update(float dt) = 0;
    };

    class SystemManager
    {
        std::unordered_map<const char *, std::shared_ptr<System>> systems;
        std::unordered_map<const char *, Signature> signatures;

       public:
        SystemManager()
        {
            use();
        }
        void use();
        template <typename T>
        std::shared_ptr<T> registerSystem(Signature sig);

        void entitySignatureChanged(Entity *entity);

        template <typename T>
        Signature getSignature();

        std::unordered_map<const char *, std::shared_ptr<System>> getSystems()
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