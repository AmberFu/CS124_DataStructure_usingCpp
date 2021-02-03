#include "animation.h"
#include <iostream>

class Bug
{
public:
   Bug(Picture&, Picture&);
   int get_yposition() const;
   int get_xposition() const;
   int get_poleHeight();
   int get_bottom() const;
   bool isUp();
   void up();
   void down();
private:
   Picture bugPic;
   Picture polePic;
   int bottom;
   int y_position;
   int x_position;
   bool climbUp;
};

Bug::Bug(Picture& bug, Picture& pole)
{
   bugPic = bug;
   polePic = pole;
   bottom = pole.height() - bug.height();
   y_position = bottom;
   x_position = (pole.width()/2) - (bug.width()/2);
   climbUp = true;
}

int Bug::get_yposition() const
{
   return y_position;
}

int Bug::get_xposition() const
{
   return x_position;
}

int Bug::get_bottom() const
{
   return bottom;
}

bool Bug::isUp()
{
   return climbUp;
}

/* Climb UP first: up == true && y posi != poleHeight */
void Bug::up()
{
   if (y_position == 0){
      climbUp = false;
   }else{
      y_position -= 1;
   }
}

/* After climb to the top, climb down to the bottum position */
void Bug::down()
{
   if (y_position != get_bottom()){
	   y_position += 1;
   }
}

int main()
{
   Picture picBug("smallBug_transparency.png"); // Bug which going up and down.
   Picture picPole("halfTreePole.png"); // Background picture: a pole. 
   Bug smallbug(picBug, picPole);
   /* Using tree pole png create this GIF's background */
   Animation anim("animation.gif", picPole.width(), picPole.height());
   while(smallbug.isUp() == true){
      smallbug.up();
      anim.add(picPole, 0, 0);
      anim.add(picBug, smallbug.get_xposition(), smallbug.get_yposition());
      anim.frame();
   }
   while(smallbug.isUp() == false && 
	 smallbug.get_yposition() != smallbug.get_bottom()){
      smallbug.down();
      anim.add(picPole, 0, 0);
      anim.add(picBug, smallbug.get_xposition(), smallbug.get_yposition());
      anim.frame();
   }
   anim.close();
}
