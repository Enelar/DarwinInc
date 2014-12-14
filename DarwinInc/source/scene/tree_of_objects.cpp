#include "tree_of_objects.h"

void tree_of_objects::Update(float dtime)
{
  matrix_object::Update(dtime);
  for (auto obj : childs)
    obj->Update(dtime, matrix_rendered);
}

void tree_of_objects::Draw()
{
  for (auto &obj : childs)
    obj->Draw();
}

tree_of_objects &tree_of_objects::operator+=(matrix_object *obj)
{
  childs.push_back(obj);
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

void matrix_object::Update(float dtime)
{
  Update(dtime, CIwFMat2D::g_Identity);
}

void matrix_object::Update(float dtime, CIwFMat2D parent)
{
  matrix_rendered = matrix_local * parent;
}

void matrix_object::Draw()
{

}