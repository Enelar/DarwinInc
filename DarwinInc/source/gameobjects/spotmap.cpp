#include "spotmap.h"

spotmap::spotmap(map &m)
  : mask(m)
{

}

void spotmap::Init(catchball &scene)
{
  // Forcing texture load
  tex.Size();

  world_size = mask.Size();
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
      p->Color() = vec4(0, 1, 0, 1);
      p->Alpha() = 0;
      *this += spotsel.sprite = p;
      if (x == 140 && y == 80)
        spotsel.people = 1;
    }
  inited = true;
}

void spotmap::Update(catchball &b)
{
  if (!inited)
    Init(b);

  for (auto y = 0; y < world_size.y; y++)
    for (auto x = 0; x < world_size.x; x++)
    {
      auto &spotsel = array[world_size.x * y + x];
      if (spotsel.skip)
        continue;
      if (spotsel.people)
        spotsel.people += 10;

      auto density = spotsel.people / 1000.0f;
      if (density > 1)
        density = 1;
      spotsel.sprite->Alpha() = density;
      if (spotsel.people < 500)
        continue;
      spotsel.people -= 50;
      if (x + 1 < world_size.x)
        array[world_size.x * y + x + 1].people += 50;
    }

  scene_object::Update(b);
}

void spotmap::Draw()
{
  scene_object::Draw();
}