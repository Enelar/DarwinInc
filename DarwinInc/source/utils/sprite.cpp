#include "sprite.h"

sprite::sprite(string file)
  : sprite(texture(file))
{

}

sprite::sprite(texture tex)
  : img(tex)
{
}

sprite::sprite()
{
}

sprite &sprite::operator=(string file)
{
  img = file;
  return *this;
}

void sprite::Update(float dtime)
{

}

void sprite::Draw()
{
  if (Size() == vec(0, 0))
    Size() = vec(img->GetWidth(), img->GetHeight());
  //Iw2DDrawImage(img, Pos());
  Iw2DDrawImageRegion(img, Pos(), vec(0, 0), Size());
}

auto sprite::Pos()->vec&
{
  return pos;
}
auto sprite::Size()->vec&
{
  return size;
}
auto sprite::Rot() -> float&
{
  return rot;
}

auto sprite::Pos() const -> vec
{
  return pos;
}
auto sprite::Size() const -> vec
{
  return size;
}
auto sprite::Rot()  const -> float
{
  return rot;
}