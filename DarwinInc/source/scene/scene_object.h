#pragma once
#include "../def.h"

struct interface_scene_object
{
  virtual void Update(float dtime)
  {}
  virtual void Draw()
  {}
  virtual ~interface_scene_object()
  {}
};

/*
 * Completely NULL safe. You could call it like nullptr->Draw(), and nothing bad happens!
 * Reference could not be copyed!
 */
struct scene_object_reference : interface_scene_object
{
  bool removed = false;
  interface_scene_object &obj;

  scene_object_reference(interface_scene_object &_obj);

  void Update(float dtime) override;
  void Draw() override;

  void Remove();
};

/*
 * Used on every stack object, as scene primitive, help avoiding cleared memory access
 */
struct scene_object_shared_pluggable : interface_scene_object
{
  shared<scene_object_reference> *detached_storage = new shared<scene_object_reference>();;
  scene_object_shared_pluggable();
  void HostRemove();
  void ClientRemove();
  
  ~scene_object_shared_pluggable() override;
  void Update(float dtime) override;
  void Draw() override;
};

struct scene_object : interface_scene_object // only interface resolution
{
  ~scene_object() override;
  interface_scene_object &get_pluggable();
private:
  scene_object_shared_pluggable *pluggable = nullptr;
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

  void Draw() override
  {
    obj.Draw();
  }
};