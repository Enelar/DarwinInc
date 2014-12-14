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

  auto Pos() -> vec&;
  auto Size() -> vec&;
  auto Rot() -> float&;

  auto Pos() const -> vec;
  auto Size() const -> vec;
  auto Rot() const -> float;

private:
  texture img;
  vec pos, size;
  float rot;

  void Update(float dtime) override;
  void Draw() const override;
};