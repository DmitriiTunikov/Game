#include <iostream>
#include "anim.h"

int main(int argc, char **argv)
{
  anim anim(argc, argv, 20, 20, 500, 500, "data.txt");
  anim.loop();
  return 0;
}
