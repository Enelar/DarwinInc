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

template<typename T>
struct shared_scene_obj_plug
{
  bool removed = false;
  T &obj;

  shared_scene_obj_plug(T &_obj)
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

template<typename T>
struct shared_scene_obj
{
  shared<shared_scene_obj_plug<T>> *removed;
  shared_scene_obj()
    : sh(new shared())
  {

  }

  ~shared_scene_obj() override
  {
    removed->data->Remove();
    removed->Remove();
  }

  T &object() const
  {
    assert(!removed);
    return *reinterpret_cast<T *>(this + 1);
  }
};