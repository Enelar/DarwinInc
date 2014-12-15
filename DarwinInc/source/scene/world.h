#include "scene.h"
#include "../utils/sprite.h"
#include "../gameobjects/map.h"

struct world : public scene
{
  sprite map;
  ::map mask = "img/worldmap.png";
  string spot_file = "img/RedWhite.jpg";
  vec spotsize;
  vecI screensize;

  void Init();

  world();

  void Update(float dtime) override;
};