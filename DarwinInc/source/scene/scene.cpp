#include "scene.h"

void scene::Update(float dtime)
{
  tree.Update(dtime);
}

void scene::Draw()
{
  tree.Draw();
}

scene &scene::operator+=(interface_scene_object *obj)
{
  fictive_elements.push_back(obj);
  return *this;
}

scene &scene::operator+=(tree_of_objects *obj)
{
  tree += obj;
  return *this;
}

scene &scene::operator+=(scene_object &obj)
{
  fictive_elements.push_back(&obj.get_pluggable());
  return *this;
}

sprite &scene::operator+=(string file)
{
  auto *t = new sprite(file);
  *this += t;
  return *t;
}

scene::~scene()
{
}
