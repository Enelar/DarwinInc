#pragma once

#include "../utils/sprite.h"

struct spotmap : scene_object
{
  sprite spot = "img/RedWhite.jpg";
  void Update(catchball &) override;
  void Draw() override;
};