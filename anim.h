#pragma once
#ifndef ANIM_H_INCLUDED__
#define ANIM_H_INCLUDED__
#include "support.h"

class anim
{
public:
  anim(int argc, char **argv, int x, int y, int w, int h, const string &file_name);

  static void render(void);
  static void keyboard(unsigned char key, int x, int y);
  static void mouseButton(int button, int state, int x, int y);

  void loop(void);
  //static void DrowRect(const Color &color, const Coord &p, const Size &size);
  //static void DrawStr(const string &Str, const Color &Color, const Coord &Pos);
//  static void DrowButtonVec(const vector<Button*> &but_vec);
  ~anim(void);
}; 
#endif
