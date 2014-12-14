#include "sprite.h"

sprite::sprite(string file)
  : sprite(texture(file))
{

}

sprite::sprite(texture tex)
  : img(tex)
{
}