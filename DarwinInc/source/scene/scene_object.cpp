#include "scene_object.h"

scene_object_reference::scene_object_reference(interface_scene_object &_obj)
  : obj(_obj)
{

}

void scene_object_reference::Update(catchball &dtime)
{
  if (this == nullptr)
    return;
  if (removed)
    return;
  obj.Update(dtime);
}

void scene_object_reference::Draw()
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
  if (!detached_storage->Remove())
    return;
  // Host was last user, we should remove pluggable with our hands
  detached_storage = nullptr;
  delete this;
}

void scene_object_shared_pluggable::ClientRemove()
{
  detached_storage->Remove();
}
scene_object_shared_pluggable::~scene_object_shared_pluggable()
{
  ClientRemove();
}
void scene_object_shared_pluggable::Update(catchball &dtime)
{
  detached_storage->data->Update(dtime);
}
void scene_object_shared_pluggable::Draw()
{
  detached_storage->data->Draw();
}

scene_object::~scene_object()
{
  if (pluggable)
    pluggable->HostRemove();
}

scene_object_shared_pluggable &scene_object::get_pluggable()
{
  if (!pluggable)
    pluggable = new scene_object_shared_pluggable();
  if (!pluggable->detached_storage->data)
  {
    pluggable->detached_storage->data = new scene_object_reference(*this);
    pluggable->detached_storage->Add();
  }
  return *pluggable;
}