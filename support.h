#pragma once
#ifndef SUPPORT_H_INCLUDED__
#define SUPPORT_H_INCLUDED__
#include <iostream>

using namespace std;

class Size
{
public:
  int H, W;
  Size(const int w, const int h) : W(w), H(h) {}
};

class Color
{
public:
  int Rcol, Gcol, Bcol;
  Color(const int r, const int g, const int b) : Rcol(r), Gcol(g), Bcol(b) {}
};

class Coord
{
public:
  int x, y;
  Coord(const int x_, const int y_) : x(x_), y(y_){}
};

static bool CheckCoord(Coord p1, Coord p2, Size size)
{
  if (p1.x >= p2.x && p1.x <= p2.x + size.W && p1.y >= p2.y && p2.y <=p2.y + size.H)
    return 1;
  else return 0;
}

static string ReadName(const string cur_line)
{
  string name;
  size_t i = 0, k = 0;
  for (i = 0; i < cur_line.size(); i++)
  {
    if (cur_line[i] == '=')
      break;
  }
  name = cur_line.substr(i + 2);
  return name;
}
#endif