#include "engine.hpp"

Engine::Engine() { tree = new Tree(); }
Engine::~Engine() { delete tree; }

Tree* Engine::get_tree() { return tree; }