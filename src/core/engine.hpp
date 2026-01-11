#pragma once

#include "core/tree.hpp"
class Engine
{
    Tree* tree = nullptr;

public:
    Engine();
    ~Engine();

    Tree* get_tree();
};