#include "world.h"

world::world()
{

}

void world::Init()
{
  *this += map = "img/world1.png";
  map.Size().x = Size().x;
  map.Size().y = Size().y;

  spotsize.x = Size().x / mask.Size().x;
  spotsize.y = Size().y / mask.Size().y;
  spotsize = vec(4, 4);

  auto &spot = *this += "img/RedWhite.jpg";
 // spot.Pos() = vec(0, 0);
  spot.Size() = spotsize;
//  AddChild(t);

}

//void world::Update(catchball &dtime)
//{
//  scene::Update(dtime);
//}