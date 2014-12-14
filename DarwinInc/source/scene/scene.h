#pragma once

//#include "Iw2DSceneGraph.h"
//using namespace Iw2DSceneGraphCore;
//using namespace Iw2DSceneGraph;

#include "c++\stl\_list.h"
#include "scene_object.h"


using std::list;
struct scene : interface_scene_object //: public CNode
{
  list<interface_scene_object *> objects;

public:
  void Update(float dtime) override;
  void Draw() override;

  scene &operator+=(interface_scene_object *);
  scene &operator+=(scene_object &);

  ~scene() override;
};