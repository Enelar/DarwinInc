#include "scene.h"
#include "../utils/sprite.h"

struct world : public scene
{
  sprite map;
  void Init();
};