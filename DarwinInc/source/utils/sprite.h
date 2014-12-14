#pragma once

#include "Iw2DSceneGraph.h"
#include "../def.h"
#include "texture.h"
#include "vec.h"

struct sprite
{
  sprite(string);
  sprite(texture);

  vec Pos() const;
  vec Size() const;
  float Rot() const;
  vec Pos(vec);
  vec Size(vec);
  float Rot(float);

  void Draw();

  operator Iw2DSceneGraph::CSprite *();
private:
  Iw2DSceneGraph::CSprite *Sprite() const;

private:
  texture img;
  bool self_destructing = false;
  mutable Iw2DSceneGraph::CSprite *_sprite = nullptr;
};