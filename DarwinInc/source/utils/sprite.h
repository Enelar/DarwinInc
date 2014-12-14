#pragma once

#include "Iw2DSceneGraph.h"
#include "../def.h"
#include "texture.h"
#include "vec.h"
#include "../scene/scene.h"

struct sprite : scene_object
{
  sprite(string);
  sprite(texture);

  vec &Pos();
  vec &Size();
  float &Rot();
private:
  texture img;

  void Update(float dtime) override;
  void Draw() const override;
};