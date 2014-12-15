#include "world.h"

world::world()
{

}

void world::Init()
{
  *this += map = "img/world1.png";
  map.Size().x = Size().x;
  map.Size().y = Size().y;


  *this += spots;

}

//void world::Update(catchball &dtime)
//{
//  scene::Update(dtime);
//}