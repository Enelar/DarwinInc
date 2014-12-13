#pragma once

#include "std\c++\string"
#include "Iw2D.h"

using std::string;

struct texture
{
  texture(string file);
  ~texture();

  operator CIw2DImage*();
private:
  string filename;
  CIw2DImage* img = nullptr;
};