#pragma once
#include "../def.h"

struct scene_object
{
  virtual void Update(float dtime)
  {}
  virtual void Draw() const
  {}
  virtual ~scene_object()
  {}
};

struct shared_scene_obj_plug : scene_object
{
  bool removed = false;
  scene_object &obj;

  shared_scene_obj_plug(scene_object &_obj)
    : obj(_obj)
  {

  }

  void Update(float dtime) override
  {
    if (removed)
      return;
    obj.Update(dtime);
  }

  void Draw() const override
  {
    if (removed)
      return;
    obj.Draw();
  }

  void Remove()
  {
    if (this == nullptr)
      return;
    removed = true;
  }
};

struct shared_scene_obj : scene_object // interface resolution
{
  shared<shared_scene_obj_plug> *removed;
  shared_scene_obj()
    : removed(new shared<shared_scene_obj_plug>())
  {

  }

  ~shared_scene_obj() override
  {
    removed->data->Remove();
    removed->Remove();
  }

  scene_object &object()
  {
    return *reinterpret_cast<scene_object *>(this + 1);
  }

  operator scene_object &()
  {
    if (!removed->data)
      removed->data = new shared_scene_obj_plug(object());
    return *removed->data;
  }
};

struct memleak_scene_object : scene_object
{
  scene_object &obj;

  memleak_scene_object(scene_object &_obj)
    : obj(_obj)
  {

  }


  void Update(float dtime) override
  {
    obj.Update(dtime);
  }

  void Draw() const override
  {
    obj.Draw();
  }
};