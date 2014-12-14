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

uint8 *map::operator[](vec p)
{
  if (!mem)
    LoadImage();
  return mem + (int)p.y * line_offset + (int)p.x;
}

void map::LoadImage()
{
  CIwImage im;
  im.LoadFromFile(filename.c_str());
  memsize = im.GetPaletteMemSize();
  mem = new uint8(memsize);
  memcpy(mem, im.GetPalette(), memsize);

  size[0] = im.GetWidth();
  size[1] = im.GetHeight();

  line_offset = im.GetByteWidth();
}