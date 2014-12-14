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

  auto Pos() -> vec&;
  auto Size() -> vec&;
  auto Rot() -> float&;

  auto Pos() const -> vec;
  auto Size() const -> vec;
  auto Rot() const -> float;

private:
  texture img;
  vec pos = vec(0, 0), size = vec(0, 0);
  float rot = 0;

  void Update(float dtime) override;
  void Draw() override;
};