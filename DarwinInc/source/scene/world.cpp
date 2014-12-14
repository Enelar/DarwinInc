#include "world.h"

void world::Init()
{
  sprite t("img/world1.png");
  *this += t;
//  AddChild(t);
}