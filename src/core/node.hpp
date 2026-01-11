#pragma once

#include <algorithm>
#include <memory>
#include <vector>

class Tree;

class Node
{
    Node* parent = nullptr;
    std::vector<std::unique_ptr<Node>> children;

    std::string script;

    Tree* tree = nullptr;

    friend class Tree;

    Tree* get_tree();

public:
    Node();
    Node(Node* parent);
    ~Node() = default;

    std::vector<Node*> get_children();

    void add_child(std::unique_ptr<Node> child);
    std::unique_ptr<Node> remove_child(Node*);
    void reparent(Node* newParent);
};