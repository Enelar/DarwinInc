#include "sprite.h"

struct extern_sprite : sprite
{
  extern_sprite(texture &t)
  {
    delete img;
    img = &t;
  }

  ~extern_sprite() override
  {
    img = nullptr;
  }
};