#include "scene_object.h"

void matrix_object::Update(float dtime)
{
  interface_scene_object::Update(dtime);
}

void matrix_object::Update(float dtime, CIwFMat2D parent)
{
  deconstruct_vec(Pos(), matrix_local.t., x, y);

  auto scale = Size();
  double angr = Rot() * 2 * PI / 360;
  matrix_local.m[0][0] = (float)cos(angr) * scale.x;
  matrix_local.m[0][1] = -(float)sin(angr) * scale.y;
  matrix_local.m[1][0] = (float)sin(angr) * scale.x;
  matrix_local.m[1][1] = (float)cos(angr) * scale.y;

  matrix_rendered = matrix_local * parent;
}

#include "Iw2D.h"

void matrix_object::Draw()
{
  interface_scene_object::Draw();
  Iw2DSetTransformMatrix(matrix_rendered);
}

auto matrix_object::Pos()->vec&
{
  return pos;
}
auto matrix_object::Size()->vec&
{
  return size;
}
auto matrix_object::Rot() -> float&
{
  return rot;
}

auto matrix_object::Pos() const -> vec
{
  return pos;
}
auto matrix_object::Size() const -> vec
{
  return size;
}
auto matrix_object::Rot()  const -> float
{
  return rot;
}