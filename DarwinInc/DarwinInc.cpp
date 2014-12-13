#include "s3e.h"
#include "IwDebug.h"
#include "Iw2D.h"
#include "source\utils\texture.h"

void app()
{
  texture test("img/world1.png");
  CIwFVec2    image_position = CIwFVec2::g_Zero;

  // Loop forever, until the user or the OS performs some action to quit the app
  while (!s3eDeviceCheckQuitRequest())
  {
    //Update the input systems
    s3eKeyboardUpdate();
    s3ePointerUpdate();


    // Your rendering/app code goes here.
    Iw2DDrawImage(test, image_position);

    Iw2DSurfaceShow();
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
