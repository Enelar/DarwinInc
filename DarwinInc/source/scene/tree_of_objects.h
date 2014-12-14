#pragma once

#include "scene_object.h"

#include "c++\list"

struct scene_object;
struct tree_of_objects : matrix_object
{
  std::list<matrix_object *> childs;

  void Update(float dtime) override;
  void Draw() override;
  ~tree_of_objects() override;

  tree_of_objects &operator+=(matrix_object *);
  tree_of_objects &operator+=(scene_object &);
};

#define _TREE_OBJECTS_DEFINED_
#include "scene_object.h"