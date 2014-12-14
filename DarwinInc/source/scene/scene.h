#pragma once

//#include "Iw2DSceneGraph.h"
//using namespace Iw2DSceneGraphCore;
//using namespace Iw2DSceneGraph;

#include "c++\list"
#include "scene_object.h"


using std::list;
struct scene : scene_object //: public CNode
{
  list<scene_object *> objects;

public:
  void Update(float dtime) override;
  void Draw() const override;

  //scene &operator+=(scene_object);
  //scene &operator+=(scene_object);
};