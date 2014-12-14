#include "scene.h"

void scene::Update(float dtime)
{
  for (auto &obj : objects)
    obj->Update(dtime);
}

void scene::Draw()
{
  for (auto &obj : objects)
    obj->Draw();
}

scene &scene::operator+=(interface_scene_object *obj)
{
  objects.push_back(obj);
  return *this;
}

scene &scene::operator+=(scene_object &obj)
{
  return *this += &obj.get_pluggable();
}

scene::~scene()
{
  for (auto &obj : objects)
    delete obj;
}
