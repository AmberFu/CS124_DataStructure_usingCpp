#include <iostream>

using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;
const int WINDOW_X_MAX = 300;
const int WINDOW_Y_MAX = 200;
const int destinationX = 150;
const int destinationY = 100;

class Bug
{
public:
   Bug();
   int get_column() const;
   int get_row() const;
   int get_direction() const;
   void trun_right();
   void move();
   void path();
   void go_east(int);
   void go_west(int);
   void go_north(int);
   void go_south(int);
   int destDiff_x();
   int destDiff_y();
private:
   int direction; // 0: North, 1: East, 2: South, 3: West
   int y_position; // 0 - 200
   int x_position; // 0 - 300
};
