#pragma once

#include "std\c++\string"
#include "Iw2D.h"

using std::string;

struct texture
{
  texture(string file);
  ~texture();

  operator CIw2DImage*() const;
private:
  string filename;
  mutable CIw2DImage* img = nullptr;
};