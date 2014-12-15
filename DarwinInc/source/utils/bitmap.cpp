#include "bitmap.h"

auto bitmap::operator[](vec v) const->uint8
{
  return dbg;
}

auto bitmap::operator[](vec)->uint8 &
{
  return dbg;
}

auto bitmap::Access(vec) const ->uint8 *
{
  return nullptr;
}
