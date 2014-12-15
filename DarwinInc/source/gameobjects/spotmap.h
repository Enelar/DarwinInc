#pragma once

#include "../utils/extern_sprite.h"
#include "map.h"

struct spotmap : scene_object
{
  texture tex = "img/RedWhite.jpg";
  extern_sprite spot = tex;
  vec spotsize;
  bool inited = false;
  void Update(catchball &) override;
  void Draw() override;

  spotmap(map &);

private:
  map &mask;
  void Init(catchball &b);
};