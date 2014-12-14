#pragma once

#include "../utils/texture.h"
struct map
{
  map(string file);
  ~map();

  uint8 *operator[](vec x);
private:
  void LoadImage();
  uint8 *mem = nullptr;
  uint32 memsize = 0, line_offset = 0;
  uint32 size[2];
  string filename;
};