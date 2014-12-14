#include "texture.h"

texture::texture(string file)
  : filename(file)
{

}

texture::operator CIw2DImage*() const
{
  if (img)
    return img;
  return img = Iw2DCreateImage(filename.c_str());
}

texture::~texture()
{
  if (img)
    delete img;
}