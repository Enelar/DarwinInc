#pragma once

#include "std\c++\string"
#include "Iw2D.h"
#include "../def.h"
#include "vec.h"

using std::string;

struct texture
{
  texture(string file);
  texture();
  ~texture();

  void operator=(string file);

  CIw2DImage* operator->() const;
  operator CIw2DImage*() const;
  vec Size() const;
private:
  string filename;
  mutable CIw2DImage* img = nullptr;
};