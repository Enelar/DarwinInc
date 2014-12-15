#pragma once

#include "../utils/extern_sprite.h"
#include "map.h"

struct spotsel
{
  bool skip = true;
  extern_sprite *sprite = nullptr;
  int people = 0;
};

#include "c++\vector"
struct spotmap : scene_object
{
  texture tex = "img/spot.png";
  extern_sprite spot = tex;
  vec spotsize;
  vecI world_size;
  bool inited = false;
  void Update(catchball &) override;
  void Draw() override;

  spotmap(map &);
  std::vector<spotsel> array;
private:
  map &mask;
  void Init(catchball &b);
};