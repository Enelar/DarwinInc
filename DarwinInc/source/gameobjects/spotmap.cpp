#include "spotmap.h"

spotmap::spotmap(map &m)
  : mask(m)
{

}

void spotmap::Init(catchball &scene)
{
  // Forcing texture load
  tex.Size();

  auto world_size = mask.Size();
  spotsize.x = (float)scene.Size().x / world_size.x;
  spotsize.y = (float)scene.Size().y / world_size.y;

  array.resize(world_size.x * world_size.y);

  for (auto y = 0; y < world_size.y; y++)
    for (auto x = 0; x < world_size.x; x++)
    {
      auto bit = mask[vecI(x, y)];

      auto &spotsel = array[world_size.x * y + x];
      if (!bit)
        continue;
      spotsel.skip = false;

      auto p = new extern_sprite(tex);
      p->Pos() = vec(x * spotsize.x, y * spotsize.y);
      p->Size() = spotsize;
      *this += spotsel.sprite = p;
    }
  inited = true;
}

void spotmap::Update(catchball &b)
{
  if (!inited)
    Init(b);
  scene_object::Update(b);
}

void spotmap::Draw()
{
  scene_object::Draw();
}