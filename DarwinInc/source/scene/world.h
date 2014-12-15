#include "scene.h"
#include "../utils/sprite.h"
#include "../gameobjects/spotmap.h"
#include "../gameobjects/map.h"

struct world : public scene
{
  sprite map;
  ::map mask = "img/worldmap.png";
  spotmap spots = mask;

  void Init();

  world();

  //void Update(catchball &dtime) override;
};