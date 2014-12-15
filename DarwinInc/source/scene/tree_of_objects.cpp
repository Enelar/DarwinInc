#include "tree_of_objects.h"

void tree_of_objects::Update(catchball &dtime)
{
  matrix_object::Update(dtime);
  if (root)
    Update(dtime, CIwFMat2D::g_Identity);
}

void tree_of_objects::Update(catchball &dtime, CIwFMat2D parent)
{
  // Entry point here
  if (!root)
    Update(dtime); // do user overloaded code
  matrix_object::Update(dtime, parent); // recalculate matrix

  for (auto &obj : childs)
    obj->Update(dtime, matrix_rendered);
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