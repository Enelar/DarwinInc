#include "sprite.h"

struct bitmap : sprite
{
  auto operator[](vec) const -> uint8;
  auto operator[](vec) -> uint8 &;

private:
  auto Access(vec) const->uint8 *;
  uint8 dbg;
};