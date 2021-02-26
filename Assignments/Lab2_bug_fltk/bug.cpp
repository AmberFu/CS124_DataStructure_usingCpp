#include <cmath>
#include "bug.h"

Bug::Bug()
{
   y_position = 0;
   x_position = 0;
   direction = 1;
}

int Bug::get_column() const
{
   return y_position;
}

int Bug::get_row() const
{
   return x_position;
}

int Bug::get_direction() const
{
   return direction;
}

// TURN
void Bug::trun_right()
{
	if (direction >= 3){
		direction = 0;
	}else{
		direction++;
	}
}

// MOVE
void Bug::move()
{
	if (direction == NORTH && y_position != 0)
		y_position--;
	else if (direction == EAST && x_position != WINDOW_X_MAX)
		x_position++;
	else if (direction == SOUTH && y_position != WINDOW_Y_MAX)
		y_position++;
	else if (direction == WEST && x_position != 0)
		x_position--;
}

// PATH:

void Bug::go_south(int dest){
	direction = 2; // 0: North, 1: East, 2: South, 3: West
	// if destanation is large than 5, move faster ( move 5 unit a time)
	if (std::abs(dest) <= 5){
		y_position += 1;
	}else{
		y_position += 10;
	}
}

void Bug::go_north(int dest){
	direction = 0; // 0: North, 1: East, 2: South, 3: West
	// if destanation is large than 5, move faster ( move 5 unit a time)
	if (std::abs(dest) <= 5){
		y_position -= 1;
	}else{
		y_position -= 10;
	}
}

void Bug::go_east(int dest){
	direction = 1; // 0: North, 1: East, 2: South, 3: West
	// if destanation is large than 5, move faster ( move 5 unit a time)
	if (std::abs(dest) <= 5){
		x_position += 1;
	}else{
		x_position += 10;
	}
}

void Bug::go_west(int dest){
	direction = 3; // 0: North, 1: East, 2: South, 3: West
	// if destanation is large than 5, move faster ( move 5 unit a time)
	if (std::abs(dest) <= 5 || dest <= -5){
		x_position -= 1;
	}else{
		x_position -= 10;
	}
}

int Bug::destDiff_x(){
	return x_position - destinationX;
}

int Bug::destDiff_y(){
	return y_position - destinationY;
}

void Bug::path()
{
	int side_of_dest_x = destDiff_x();
	int side_of_dest_y = destDiff_y();
	if (side_of_dest_x < 0){
		go_east(side_of_dest_x);
	}else if (side_of_dest_x > 0){
		go_west(side_of_dest_x);
	}else{
		if (side_of_dest_y > 0){
			go_north(side_of_dest_y);
		}else if (side_of_dest_y < 0){
			go_south(side_of_dest_y);
		}else{
			return;
		}
	}
}