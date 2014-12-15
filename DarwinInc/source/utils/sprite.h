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
  ~sprite();

  sprite &operator=(string);
  sprite &operator=(texture);
  auto Size() -> vec&;
  auto Size() const -> vec;

  void Update(catchball &dtime) override;
  void Draw() override;
protected:
  texture *img = nullptr;
private:
  vec wished_size = vec(0, 0);
};