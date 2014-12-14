#pragma once

#include "scene_object.h"

#include "c++\list"

struct scene_object;
struct tree_of_objects : interface_scene_object
{
  std::list<interface_scene_object *> objects;

  void Update(float dtime) override;
  void Draw() override;
  ~tree_of_objects() override;

  tree_of_objects &operator+=(interface_scene_object *);
  tree_of_objects &operator+=(scene_object &);
};

#define _TREE_OBJECTS_DEFINED_
#include "scene_object.h"