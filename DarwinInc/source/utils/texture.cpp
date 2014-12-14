#include "texture.h"

texture::texture(string file)
  : filename(file)
{

}

texture::texture() {}

texture::operator CIw2DImage*() const
{
  if (img)
    return img;
  return img = Iw2DCreateImage(filename.c_str());
}

CIw2DImage* texture::operator->() const
{
  return (CIw2DImage*)*this;
}

texture::~texture()
{
  if (img)
    delete img;
}

void texture::operator=(string file)
{
  assert_msg(!img, "Is danger to change texture on fly, sorry");
  filename = file;
}