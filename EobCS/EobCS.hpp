#ifndef EOBCS_H
#define EOBCS_H

#include <bitset>
#include <cstdint>
#include <functional>
#include <memory>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <typeindex>

using EntityID = std::uint16_t;
using Signature = std::bitset<32>;

enum ComponentType
{
    RENDERABLE = 0,
    TRANSFORMABLE = 1,
};

#endif