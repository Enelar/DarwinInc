#include "scene_object.h"

scene_object_reference::scene_object_reference(interface_scene_object &_obj)
  : obj(_obj)
{

}

void scene_object_reference::Update(float dtime)
{
  if (this == nullptr)
    return;
  if (removed)
    return;
  obj.Update(dtime);
}

void scene_object_reference::Draw() const
{
  if (this == nullptr)
    return;
  if (removed)
    return;
  obj.Draw();
}

void scene_object_reference::Remove()
{
  if (this == nullptr)
    return;
  removed = true;
}

scene_object_shared_pluggable::scene_object_shared_pluggable()
{}
void scene_object_shared_pluggable::HostRemove()
{
  detached_storage->data->Remove();
  detached_storage->Remove();
}
void scene_object_shared_pluggable::ClientRemove()
{
  detached_storage->Remove();
}
scene_object_shared_pluggable::~scene_object_shared_pluggable()
{
  ClientRemove();
}
void scene_object_shared_pluggable::Update(float dtime)
{
  detached_storage->data->Update(dtime);
}
void scene_object_shared_pluggable::Draw() const
{
  detached_storage->data->Draw();
}

scene_object::~scene_object()
{
  pluggable->HostRemove();
}

interface_scene_object &scene_object::get_pluggable()
{
  if (!pluggable->detached_storage->data)
  {
    pluggable->detached_storage->data = new scene_object_reference(*this);
    pluggable->detached_storage->Add();
  }
  return *pluggable;
}