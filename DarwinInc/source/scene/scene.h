#pragma once

//#include "Iw2DSceneGraph.h"
//using namespace Iw2DSceneGraphCore;
//using namespace Iw2DSceneGraph;

#include "c++\stl\_list.h"
#include "scene_object.h"


using std::list;
struct scene : interface_scene_object
{
  tree_of_objects tree;
  list<interface_scene_object *> fictive_elements;

public:
  void Update(float dtime) override;
  void Draw() override;

  scene &operator+=(interface_scene_object *);
  scene &operator+=(matrix_object *);
  scene &operator+=(scene_object &);

  ~scene() override;
};