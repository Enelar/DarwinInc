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
  sprite();

  sprite &operator=(string);
  sprite &operator=(texture);
  auto Size() -> vec&;
  auto Size() const -> vec;

private:
  texture img;
  vec wished_size;

  void Update(float dtime) override;
  void Draw() override;
};