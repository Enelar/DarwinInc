#include "scene_object.h"

void matrix_object::Update(catchball &dtime)
{
  interface_scene_object::Update(dtime);
}

void matrix_object::Update(catchball &dtime, CIwFMat2D parent)
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
#include "IwColour.h"

void matrix_object::Draw()
{
  interface_scene_object::Draw();

  vec4 t = color;
  for (auto i = 0; i < 4; i++)
    if (t[i] < 0)
      t[i] = 0;
    else if (t[i] > 1)
      t[i] = 1;

  if (alpha < 0)
    t.w = 0;
  else if (alpha <= 1)
    t.w *= alpha;

  t *= 0xFF;
  CIwColour c;

  c.Set(t.x, t.y, t.z, t.w);
  Iw2DSetColour(c);
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

auto matrix_object::Alpha() -> float&
{
  return alpha;
}

auto matrix_object::Color() -> vec4&
{
  return color;
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
auto matrix_object::Alpha() const -> float
{
  return alpha;
}

auto matrix_object::Color() const -> vec4
{
  return color;
}
