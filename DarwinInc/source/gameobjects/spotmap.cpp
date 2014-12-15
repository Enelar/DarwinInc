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
        spotsel.people = 2;
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
        spotsel.people += rand() & 127;
      else
        continue;

      auto density = spotsel.people / 1000.0f;
      if (density > 1)
      {
        spotsel.skip = true;
        density = 1;
        spotsel.people *= 0.9;
      }
      spotsel.sprite->Alpha() = density;


      vec4 color(0, 0, 0, 1);
      color.z = (spotsel.people - 700) / 500.f;
      if (spotsel.people < 500)
        color.y = spotsel.people / 500.f;
      else
        color.y = 1 - (spotsel.people - 500) / 200.f;
      //color.z = spotsel.people / 1000.f;

      spotsel.sprite->Color() = color;

      if (spotsel.people < 500)
        continue;
      auto moving = (spotsel.people - 500) / 10;
      spotsel.people -= moving;

      auto direction = rand() & 3;
      auto target = Neibors({ x, y })[direction];
      target->people += moving / 2; // dying
    }

  scene_object::Update(b);
}

void spotmap::Draw()
{
  scene_object::Draw();
}

// Clockwise
std::vector<spotsel *> spotmap::Neibors(vecI p)
{
  std::vector<spotsel *> ret;
  ret.push_back(Access({p.x, p.y - 1}));
  ret.push_back(Access({ p.x + 1, p.y }));
  ret.push_back(Access({ p.x, p.y + 1 }));
  ret.push_back(Access({ p.x - 1, p.y }));
  return ret;
}

vecI spotmap::ShortCut(vecI p) const
{
  for (auto i = 0; i < 2; i++)
    if (p[i] < 0)
      p[i] += world_size[i];
    else if (p[i] >= world_size[i])
      p[i] -= world_size[i];
  return p;
}

spotsel *spotmap::Access(vecI p)
{
  auto point = ShortCut(p);
  return &array[point.x + point.y * world_size.x];
}