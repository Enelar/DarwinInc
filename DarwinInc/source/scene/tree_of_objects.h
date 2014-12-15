#pragma once

#include "scene_object.h"

#include "c++\list"

struct scene_object;
// Refactor this crap!
struct tree_of_objects : matrix_object
{
  std::list<tree_of_objects *> childs;

  // Entry point from interface
  void Update(float dtime) override;
  // Entry point from parent tree(if any) object
  void Update(float dtime, CIwFMat2D parent);
  void Draw() override;
  ~tree_of_objects() override;

  tree_of_objects &operator+=(tree_of_objects *);
  bool root = true;
};

#define _TREE_OBJECTS_DEFINED_
#include "scene_object.h"