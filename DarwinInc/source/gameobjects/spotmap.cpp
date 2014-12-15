#include "spotmap.h"

spotmap::spotmap(map &m)
  : mask(m)
{

}

void spotmap::Init(catchball &b)
{
  // Forcing texture load
  tex.Size();

  auto size = mask.Size();
  spotsize.x = b.Size().x / size.x;
  spotsize.y = b.Size().y / size.y;

  for (auto y = 0; y < size.y; y++)
    for (auto x = 0; x < size.x; x++)
    {
      auto p = new extern_sprite(tex);
      *this += p;
      p->Pos() = vec(x * spotsize.x, y * spotsize.y);
      p->Size() = spotsize;
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