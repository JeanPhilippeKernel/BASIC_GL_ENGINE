#include <iostream>
#include "Display.h"



Display display(1000, 800, "GL ENGINE");


int main(int argc, char** argv)
{

	while (!display.IsClosed())
	{
		display.Update();
	}	  

	return 0;
}