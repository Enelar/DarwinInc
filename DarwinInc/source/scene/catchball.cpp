#include "catchball.h"

catchball::catchball()
  : screensize(Iw2DGetSurfaceWidth(), Iw2DGetSurfaceHeight())
{

}

void catchball::Next()
{
  curtime = s3eTimerGetMs();
  if (!prevtime)
    prevtime = curtime;
  dtime = curtime - prevtime;
  ttime += dtime;
}