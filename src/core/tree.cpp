#include "tree.hpp"

Tree::Tree()
{
    root = new Node();
    root->tree = this;
}

Tree::~Tree() { delete root; }