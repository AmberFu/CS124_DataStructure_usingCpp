// generated by Fast Light User Interface Designer (fluid) version 1.0305

#include "bugGUI.h"

Fl_Double_Window *win=(Fl_Double_Window *)0;

static void cb_Move(Fl_Button*, void*) {
  bug.move();
b->position(bug.get_row(),bug.get_column());
b->image(img[bug.get_direction()]);
win->redraw();
}

static void cb_Turn(Fl_Button*, void*) {
  bug.trun_right();
b->image(img[bug.get_direction()]);
win->redraw();
}

static void cb_Path(Fl_Button*, void*) {
  bug.path();
b->image(img[bug.get_direction()]);
b->position(bug.get_row(),bug.get_column());
win->redraw();
}

Fl_Box *b=(Fl_Box *)0;

int main(int argc, char **argv) {
  printf("Program Start...\n");
  { win = new Fl_Double_Window(300, 200);
    { Fl_Button* o = new Fl_Button(250, 5, 45, 25, "Move");
      o->callback((Fl_Callback*)cb_Move);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(250, 30, 45, 25, "Turn");
      o->callback((Fl_Callback*)cb_Turn);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(250, 55, 45, 25, "Path");
      o->callback((Fl_Callback*)cb_Path);
    } // Fl_Button* o
    { b = new Fl_Box(0, 0, 40, 40);
      img[0] = new Fl_PNG_Image("bugNorth.png");
      img[1] = new Fl_PNG_Image("bugEast.png");
      img[2] = new Fl_PNG_Image("bugSouth.png");
      img[3] = new Fl_PNG_Image("bugWest.png");
    } // Fl_Box* b
    { new Fl_Box(160, 110, 25, 25, "x");
    } // Fl_Box* o
    b->image(img[bug.get_direction()]);
    win->end();
  } // Fl_Double_Window* win
  win->show(argc, argv);
  return Fl::run();
}
