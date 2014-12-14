#include "world.h"

void world::Init()
{
  *this += map = "img/world1.png";
  map.Size().x = Iw2DGetSurfaceWidth();
  map.Size().y = Iw2DGetSurfaceHeight();
//  AddChild(t);
}