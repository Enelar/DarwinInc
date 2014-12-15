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

#include "c++\utility"

sprite &sprite::operator=(string file)
{
  img.~texture();
  new (&img) texture(file);
  return *this;
}

sprite &sprite::operator=(texture tex)
{
  img.~texture();
  new (&img) texture(tex);
  return *this;
}

void sprite::Update(float dtime)
{
  if (Size() == vec(0, 0))
    Size() = img.Size();

  matrix_object::Size() = vec(wished_size[0] / img.Size()[0], wished_size[1] / img.Size()[1]);
  scene_object::Update(dtime);
}

void sprite::Draw()
{
  scene_object::Draw();

  Iw2DDrawImage(img, vec(0, 0));
 // Iw2DDrawImageRegion(img, Pos(), vec(0, 0), Size());
}

auto sprite::Size() -> vec &
{
  return wished_size;
}

auto sprite::Size() const -> vec
{
  return wished_size;
}
