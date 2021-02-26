# Lab2 - FLTK

# Describe assignment:

## Horstmann BigC++ Chapter 9 Object-oriented programming

### Use FLTK/FLUID to demonstrate control of a small image (e.g. bug)

* Lab goals: Explore the use of constructors and a array of object pointers

* Loading the image (read section 9.6)

	Buttons to allow user to make image move, turn, and/or follow a path.
	
	Add default contructor to class to set initial position and direction

	Declare/define a global object to place in FLTK Box

	Instead of storing image data directly in executable, load from png file

* Array of ojects (read section 9.10)
	
	Create 4 images facing in the four directions (N,E,S,W)

	Create array to hold pointers to these images

	Copies of images are not allowed (read section 13.5)

* Turning the image

	In the "turn" button callback, cycle through the 4 images

	Redraw the parent (window) after each

	Use local static variable which will remember its previous value

	Sequencing the path of image

* Create button to walk the image through some predetermined path

	Create array of characters such as "mmt" that means "move, move, turn"

	Each click of the path button reads next character from string

	Use local variable to remember last character processed

##################

To make video of your program running (instead of the animated gif!)

I tried various options for ffmpeg and got pretty good results for this command:

```
rm bug.mp4 && ./bug & ffmpeg -video_size 300x200 -framerate 1 -f x11grab -t 20 -i :0.0 -crf 0 -preset ultrafast -c:v libx264rgb bug.mp4
```

You may have to adjust **framerate**  -  this is just one frame per second!

Also change ./bug  if your program has a different name

Make sure your program is in upper left corner of screen or add position to video_size. 

e.g.  300x200+100+50 if your "window" is at (100,50) on desktop

##################

# Create 4 images facing in the four directions (N,E,S,W)

	`$ convert bugN.png -rotate 90 bugE.png`

# How to program FLTK with FLUID?

> FLTK official documents: [Programming with FLUID](https://www.fltk.org/doc-1.4/fluid.html)
> 
> JSLinux: https://bellard.org/jslinux/vm.html?url=alpine-x86-xwin.cfg&mem=1024&graphic=1&w=1200&h=800
> 
> 	* login: xhost + && vflogin ACCOUNT
>

* Right click mouse, then choose "FLDev"

* Create bugGUI.fl file by using FLDev interface:

	![bugGUI.fl]()

	* Create Declaretion:

		* #include <iostream>
		* #include <FL/Fl_PNG_Image.h>
		* #include <bug.h>
		* Fl_PNG_Image* img[4]; // Create an an array to hold Fl_PNG_Image pointer.

		* Bug bug; // Create an Bug instance as global variable

	* Create main() enterpoint:

	* Create Double_Window under/inside main():

		* Create a Box to hold images

		* Create 3 buttoms letting user change position/direction of the images

* Create bug.cpp and bug.h: <-- do I need this?

	* bug.h

	```

	
	```

	* bug.cpp

	```
	
	```

* Creating & Setting Box to hold the images:

	* Name: b

	* Extra Code: 

	```
	img[0] = new Fl_PNG_Image("bugNorth.png");
	img[1] = new Fl_PNG_Image("bugEast.png");
	img[2] = new Fl_PNG_Image("bugSouth.png");
	img[3] = new Fl_PNG_Image("bugWest.png");

	```

* Creating & Setting each buttom: 

	* MOVE: move one unit follow by direction.

	```
	bug.move()
	b->position(bug.get_row(), bug.get_column());
	win->redraw();
	```

	* TURN: turn right for each click.

	* PATH: follow the path to the end point.

* Create .cxx and .h files:

	`$ fluid -c xxx.fl`

* How to complile bug.cpp with bugGUI.cxx?

	`$ g++ bug.cpp bugGUI.cxx -o bug -lfltk -lXext -lX11 -lm`

	OR use: $ g++ bugGUI.cxx bug.cpp -o bug `fltk-config --cxxflags --ldflags --use-images`

* test program:

	`$ ./bug`

# 

