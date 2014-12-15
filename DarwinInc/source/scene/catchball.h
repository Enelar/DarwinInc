#pragma once

#include "../utils/vec.h"
struct catchball
{
  float dtime = 0;
  float ttime = 0;
  uint64 prevtime = 0, curtime = 0;
  vecI screensize;

  catchball();

  void Next();

  operator float() const
  {
    return dtime;
  }

  vecI Size()
  {
    return screensize;
  }
};