#include "sprite.h"

sprite::sprite(string file)
  : sprite(texture(file))
{

}

sprite::sprite(texture tex)
  : img(tex)
{
}

void sprite::Update(float dtime)
{

}

void sprite::Draw() const
{
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