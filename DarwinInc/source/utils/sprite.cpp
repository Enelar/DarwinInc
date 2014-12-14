#include "sprite.h"

sprite::sprite(string file)
  : sprite(texture(file))
{

}

sprite::sprite(texture tex)
  : img(tex)
{
}

vec sprite::Pos() const
{
  return construct_vec(Sprite()->m_, X, Y);
}

vec sprite::Size() const
{
  return construct_vec(Sprite()->m_, W, H);
}

float sprite::Rot() const
{
  return Sprite()->m_Angle;
}

vec sprite::Pos(vec s)
{
  deconstruct_vec(s, Sprite()->m_, X, Y);
  return Pos();
}

vec sprite::Size(vec s)
{
  deconstruct_vec(s, Sprite()->m_, W, H);
  return Size();
}

float sprite::Rot(float s)
{
  Sprite()->m_Angle = s;
  return Rot();
}


void sprite::Draw()
{
  Iw2DDrawImage(img, Pos());
}

sprite::operator Iw2DSceneGraph::CSprite *()
{
  assert_msg(!self_destructing, "Already exported from sprite");
  self_destructing = true;
  return Sprite();
}

Iw2DSceneGraph::CSprite *sprite::Sprite() const
{
  if (!_sprite)
  {
    _sprite = new Iw2DSceneGraph::CSprite();
    _sprite->SetImage(img);
  }

  return _sprite;
}