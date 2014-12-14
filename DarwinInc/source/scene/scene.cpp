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
  tree += obj;
  return *this;
}

scene &scene::operator+=(scene_object &obj)
{
  tree += obj;
  return *this;
}

scene::~scene()
{
}
