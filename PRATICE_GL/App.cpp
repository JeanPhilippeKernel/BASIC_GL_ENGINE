#include <iostream>
#include "Display.h"



Display display(1000, 800, "GL ENGINE", true);


int main(int argc, char** argv)
{

	while (!display.IsClosed())
	{
		display.ClearColor(.2f, .5f, .3f, 1.0f);
		display.EnableDepthTesting();




		display.Update();
	}	  

	return 0;
}