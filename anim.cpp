#include <stdlib.h>
#include <glut.h>
#include "anim.h"

// definition of static variables
int WinW, WinH;
//Menu *menu;

anim::anim(int argc, char **argv, int x, int y, int w, int h, const string &file_name)
{
  //menu = new Menu;
  WinW = w;
  WinH = h;

  glutInit(&argc, argv);
  glutInitWindowPosition(x, y);
  glutInitWindowSize(w, h);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutCreateWindow("Windows System");

  glutDisplayFunc(render);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouseButton);
  
  glOrtho(0, w, 0, h, -5.0, 5.0);
  //init static variables
  //menu->LoadMenu("data.txt");
  //menu->InitMenu(win_vec);
} 

anim::~anim(void)
{
}

/*void anim::DrowRect(const Color &color, const Coord &p, const Size &size)
{
  glColor3ub(color.Rcol, color.Gcol, color.Bcol);
  glRecti(p.x, p.y, p.x + size.W, p.y + size.H);
}*/
/*
void anim::DrawStr(const string &Str, const Color &Color, const Coord &Pos)
{
  glColor3f(Color.Rcol, Color.Bcol, Color.Gcol);
  glRasterPos2f(Pos.x, Pos.y);
  for (size_t i = 0; i < Str.size(); i++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, Str[i]);
}*/

void anim::DrowButtonVec(const vector<Button*> &but_vec)
{
  for (auto but : but_vec)
  {
    if (but->GetButState())
    {
      Size size = but->GetSize();
      Coord coord = but->GetCoordinate();
      DrowRect(but->GetColor(), coord, size);
      coord.x = coord.x + size.W / 2;
      coord.y = coord.y + size.H / 2;
      DrawStr(but->GetName(), Color(0, 0, 0), coord);
    }
  }
}

void anim::render(void)
{
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  //draw
  vector<Window*> open_windows = menu->GetOpenWinVec();
  for (auto win : open_windows)
  {
    //draw win
    DrowRect(win->GetColor(), win->GetCoord(), win->GetSize());
    //draw buttons
    vector<Button*> buttons = win->GetButVec();
    DrowButtonVec(buttons);
  }

  glutSwapBuffers();
  glutPostRedisplay();
  glFlush();
} 

void anim::keyboard(unsigned char key, int x, int y)
{
  if (key == 27)
  {
    delete menu;
    exit(0);
  }
  
} 

void anim::loop(void)
{
  glutMainLoop();
}

void anim::mouseButton(int button, int state, int x, int y) {

  // only start motion if the left button is pressed
  if (button == GLUT_LEFT_BUTTON) {

    // when the button is released
    if (state == GLUT_UP) 
    {
    }
    else
    {
      menu->SetPressedButton(Coord(x, WinH - y));
    }
  }
}
