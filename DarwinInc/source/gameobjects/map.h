#pragma once

#include "../utils/texture.h"
struct map
{
  map(string file);
  ~map();

  uint8 &operator[](vecI);
  vecI Size();

private:
  void LoadImage();
  uint8 *mem = nullptr;
  uint32 memsize = 0, line_offset = 0;
  vecI size = vecI(0, 0);
  string filename;
};