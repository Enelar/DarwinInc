#include "s3e.h"
#include "IwDebug.h"
#include "scene\world.h"

void app()
{
  world test;
  test.Init();

  // Loop forever, until the user or the OS performs some action to quit the app
  while (!s3eDeviceCheckQuitRequest())
  {
    //Update the input systems
    s3eKeyboardUpdate();
    s3ePointerUpdate();

    test.Update((float)30 / 1000);
    test.Render();

    // Sleep for 0ms to allow the OS to process events etc.
    s3eDeviceYield(0);
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
