#include "s3e.h"
#include "IwDebug.h"
#include "scene\world.h"

#define FPS 20

void app()
{
  world test;
  test.Init();

  uint64 oldtime = 0, newtime = s3eTimerGetMs();
  // Loop forever, until the user or the OS performs some action to quit the app
  while (!s3eDeviceCheckQuitRequest())
  {
    //Update the input systems
    s3eKeyboardUpdate();
    s3ePointerUpdate();

    Iw2DSurfaceClear(0xff000000);
    test.Update();
    test.Draw();

    Iw2DSurfaceShow();

    int yield = 1000 / FPS - (newtime - oldtime);
    // wished time - actual time
    // if actual less, then we making to many fps, and could wait
    // Otherwise we should render!
    //debug: if (yield < 0)
      yield = 0;
    s3eDeviceYield(yield);

    oldtime = newtime;
    newtime = s3eTimerGetMs();
  }
}

// Main entry point for the application
int main()
{
    Iw2DInit();

    app();

    Iw2DTerminate();
    return 0;
}
