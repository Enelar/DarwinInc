#include "scene.h"
#include "../utils/sprite.h"
#include "../gameobjects/map.h"

struct world : public scene
{
  sprite map;
  ::map bitmap = "img/worldmap.png";
  string spot_file = "img/RedWhite.jpg";

  void Init();

  world();
};