#include "world.h"

world::world()
{

}

void world::Init()
{
  *this += map = "img/world1.png";
  map.Size().x = Iw2DGetSurfaceWidth();
  map.Size().y = Iw2DGetSurfaceHeight();

  //auto &spot = *this += "img/world1.png";
  //spot.Pos() = vec(0, 0);
  //spot.Size() = vec(100, 100);
//  AddChild(t);
}