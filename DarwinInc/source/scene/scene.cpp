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

scene &scene::operator+=(scene_object obj)
{
  objects.push_back(new memleak_scene_object(obj));
  return *this;
}

scene &scene::operator+=(shared_scene_obj obj)
{
  objects.push_back(&obj.object());
  return *this;
}

scene::~scene()
{
  for (auto &obj : objects)
    delete obj;
}
