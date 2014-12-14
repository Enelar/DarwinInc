#pragma once
#include "../def.h"

struct interface_scene_object
{
  virtual void Update(float dtime)
  {}
  virtual void Draw() const
  {}
  virtual ~interface_scene_object()
  {}
};

struct scene_object_reference : interface_scene_object
{
  bool removed = false;
  interface_scene_object &obj;

  scene_object_reference(interface_scene_object &_obj)
    : obj(_obj)
  {

  }

  void Update(float dtime) override
  {
    if (this == nullptr)
      return;
    if (removed)
      return;
    obj.Update(dtime);
  }

  void Draw() const override
  {
    if (this == nullptr)
      return;
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

struct scene_object_shared_pluggable : interface_scene_object
{
  shared<scene_object_reference> *detached_storage = new shared<scene_object_reference>();;
  scene_object_shared_pluggable()
  {}
  void HostRemove()
  {
    detached_storage->data->Remove();
    detached_storage->Remove();
  }
  void ClientRemove()
  {
    detached_storage->Remove();
  }
  ~scene_object_shared_pluggable()
  {
    ClientRemove();
  }
  void Update(float dtime) override
  {
    detached_storage->data->Update(dtime);
  }

  void Draw() const override
  {
    detached_storage->data->Draw();
  }
};

struct scene_object : interface_scene_object // interface resolution
{
  ~scene_object() override
  {
    pluggable->HostRemove();
  }

  interface_scene_object &get_pluggable()
  {
    if (!pluggable->detached_storage->data)
    {
      pluggable->detached_storage->data = new scene_object_reference(*this);
      pluggable->detached_storage->Add();
    }
    return *pluggable;
  }
private:
  scene_object_shared_pluggable *pluggable = new scene_object_shared_pluggable();
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