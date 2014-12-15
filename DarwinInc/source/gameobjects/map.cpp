#include "map.h"

map::map(string file)
  : filename(file)
{

}

map::~map()
{
  if (mem)
    delete mem;
}

map::texel &map::operator[](vecI p)
{
  if (!mem)
    LoadImage();
  assert_msg(p.y >= 0 && p.x >= 0, "Negative map access");
  assert_msg(p.y < size.y && p.x < size.x, "Out of bound map access");

  auto *ptr = mem + p.y * line_offset + p.x * 4;
  return *reinterpret_cast<map::texel *>(ptr);
}

void map::LoadImage()
{
  CIwImage im;
  im.SetFormat(CIwImage::ARGB_8888);

  {
    CIwImage source;
    source.LoadFromFile(filename.c_str());
    source.ConvertToImage(&im);
  }

  memsize = im.GetTexelsMemSize();
  mem = new uint8[memsize];
  memcpy(mem, im.GetTexels(), memsize);

  size[0] = im.GetWidth();
  size[1] = im.GetHeight();

  line_offset = im.GetByteWidth();
}

vecI map::Size()
{
  if (!size.GetLengthSquared())
    LoadImage();
  return size;
}