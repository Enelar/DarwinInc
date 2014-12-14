#include "tree_of_objects.h"

void tree_of_objects::Update(float dtime)
{
  for (auto &obj : objects)
    obj->Update(dtime);
}

void tree_of_objects::Draw()
{
  for (auto &obj : objects)
    obj->Draw();
}

tree_of_objects &tree_of_objects::operator+=(interface_scene_object *obj)
{
  objects.push_back(obj);
  return *this;
}

tree_of_objects &tree_of_objects::operator+=(scene_object &obj)
{
  return *this += &obj.get_pluggable();
}

tree_of_objects::~tree_of_objects()
{
  for (auto &obj : objects)
    delete obj;
}