#pragma once

#include "scene_object.h"

#include "c++\list"

struct scene_object;
struct tree_of_objects : matrix_object
{
  std::list<tree_of_objects *> childs;

  void Update(float dtime) override;
  void Draw() override;
  ~tree_of_objects() override;

  tree_of_objects &operator+=(tree_of_objects *);
  bool root = true;
};

#define _TREE_OBJECTS_DEFINED_
#include "scene_object.h"