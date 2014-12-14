#include "scene.h"

void scene::Update(float dtime)
{
  for (auto &obj : objects)
    obj->Update(dtime);
}

void scene::Draw() const
{
  for (auto &obj : objects)
    obj->Draw();
}