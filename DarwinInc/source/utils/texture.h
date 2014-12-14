#pragma once

#include "std\c++\string"
#include "Iw2D.h"
#include "../def.h"

using std::string;

struct texture
{
  texture(string file);
  texture();
  ~texture();

  void operator=(string file);

  CIw2DImage* operator->() const;
  operator CIw2DImage*() const;
private:
  string filename;
  mutable CIw2DImage* img = nullptr;
};