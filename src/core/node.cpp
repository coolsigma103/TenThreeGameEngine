#include "node.hpp"

Node::Node() : Node::Node(nullptr) {}
Node::Node(Node* parent) : parent(parent) {}

Tree* Node::get_tree()
{
    if (tree)
        return tree;
    if (!parent)
        return nullptr;
    return parent->get_tree();
}

std::vector<Node*> Node::get_children()
{
    std::vector<Node*> out;
    for (const auto& c : children)
        out.push_back(c.get()); // expose raw pointer only
    return out;
}

void Node::add_child(std::unique_ptr<Node> child)
{
    if (!child || child.get() == this)
        return;

    child->reparent(this);
    children.push_back(std::move(child)); // take ownership
}

std::unique_ptr<Node> Node::remove_child(Node* child)
{
    for (auto it = children.begin(); it != children.end(); ++it)
    {
        if (it->get() == child)
        {
            child->parent = nullptr;
            auto out = std::move(*it); // transfer ownership
            children.erase(it);        // remove slot
            return out;
        }
    }
    return nullptr;
}

void Node::reparent(Node* newParent)
{
    if (!newParent || newParent == this || parent == newParent)
        return;

    std::unique_ptr<Node> self;

    if (parent)
        self = parent->remove_child(this); // steal from old parent

    parent = newParent;
    newParent->children.push_back(std::move(self)); // give to new parent
}
