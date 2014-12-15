#pragma once

#include "../utils/texture.h"
struct map
{
  union texel
  {
    __declspec(align(1)) struct
    {
      char r, g, b, a;
    } pixel;
    uint32 mem;

    operator bool() const
    {
      return pixel.a > 0x20;
    }
  };
  static_assert(sizeof(texel) == 4, "Aligment failed");


  map(string file);
  ~map();

  texel &operator[](vecI);
  vecI Size();

private:
  void LoadImage();
  uint8 *mem = nullptr;
  uint32 memsize = 0, line_offset = 0;
  vecI size = vecI(0, 0);
  string filename;
};