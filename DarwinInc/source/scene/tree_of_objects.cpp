#include "tree_of_objects.h"

void tree_of_objects::Update(float dtime)
{
  matrix_object::Update(dtime);
  if (root)
    matrix_object::Update(dtime, CIwFMat2D::g_Identity);

  for (matrix_object *obj : childs)
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