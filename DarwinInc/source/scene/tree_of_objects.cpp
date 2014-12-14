#include "tree_of_objects.h"

void tree_of_objects::Update(float dtime)
{
  matrix_object::Update(dtime);
  for (auto obj : childs)
  {
    obj->Update(dtime);
    obj->Update(dtime, matrix_rendered);
  }
}

void tree_of_objects::Draw()
{
  for (auto &obj : childs)
    obj->Draw();
  matrix_object::Draw();
}

tree_of_objects &tree_of_objects::operator+=(matrix_object *obj)
{
  childs.push_back(obj);
  obj->root = false;
  return *this;
}

tree_of_objects &tree_of_objects::operator+=(scene_object &obj)
{
  return *this += &obj.get_pluggable();
}

tree_of_objects::~tree_of_objects()
{
  for (auto &obj : childs)
    delete obj;
}