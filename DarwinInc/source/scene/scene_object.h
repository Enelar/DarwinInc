#ifndef _BASE_SCENE_OBJECT
#define _BASE_SCENE_OBJECT

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

#include "IwGeom.h"
#include "../utils/vec.h"

struct matrix_object : interface_scene_object
{
  void Update(float dtime) override;
  void Update(float dtime, CIwFMat2D parent);

  void Draw() override;

  auto Pos() -> vec&;
  auto Size() -> vec&;
  auto Rot() -> float&;

  auto Pos() const -> vec;
  auto Size() const -> vec;
  auto Rot() const -> float;

  bool root = true;
protected:
  CIwFMat2D matrix_local, matrix_rendered;
private:
  vec pos = vec(0, 0), size = vec(0, 0);
  float rot = 0;
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
struct scene_object_shared_pluggable : matrix_object
{
  shared<scene_object_reference> *detached_storage = new shared<scene_object_reference>();;
  scene_object_shared_pluggable();
  void HostRemove();
  void ClientRemove();
  
  ~scene_object_shared_pluggable() override;
  void Update(float dtime) override;
  void Draw() override;
};

struct memleak_scene_object : interface_scene_object
{
  interface_scene_object &obj;

  memleak_scene_object(interface_scene_object &_obj)
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

#endif

#include "tree_of_objects.h"

#ifdef _TREE_OBJECTS_DEFINED_
#ifndef _SCENE_OBJECT_DEFINED_
#define _SCENE_OBJECT_DEFINED_
struct scene_object : tree_of_objects
{
  ~scene_object() override;
  scene_object_shared_pluggable &get_pluggable();
private:
  scene_object_shared_pluggable *pluggable = nullptr;
};
#endif
#endif