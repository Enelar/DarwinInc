#pragma once

//#include "Iw2DSceneGraph.h"
//using namespace Iw2DSceneGraphCore;
//using namespace Iw2DSceneGraph;

#include "c++\stl\_list.h"
#include "scene_object.h"
#include "../utils/sprite.h"


using std::list;
struct sprite;
struct scene : interface_scene_object
{
  tree_of_objects tree;
  list<interface_scene_object *> fictive_elements;
  vecI screensize = { 0, 0 };

public:
  void Update(float dtime) override;
  void Draw() override;

  vecI Size();

  scene &operator+=(interface_scene_object *);
  scene &operator+=(tree_of_objects *);
  scene &operator+=(scene_object &);
  sprite &operator+=(string);

  ~scene() override;
};