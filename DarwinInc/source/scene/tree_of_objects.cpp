#include "tree_of_objects.h"

void tree_of_objects::Update(float dtime)
{
  if (root)
    matrix_object::Update(dtime, CIwFMat2D::g_Identity);
  matrix_object::Update(dtime);

  for (matrix_object *obj : childs)
  {
    obj->Update(dtime, matrix_rendered);
    obj->Update(dtime);
  }
}

void tree_of_objects::Draw()
{
  for (auto &obj : childs)
    obj->Draw();
  matrix_object::Draw();
}

tree_of_objects &tree_of_objects::operator+=(tree_of_objects *obj)
{
  childs.push_back(obj);
  obj->root = false;
  return *this;
}

tree_of_objects::~tree_of_objects()
{
  for (auto &obj : childs)
    delete obj;
}