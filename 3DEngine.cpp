// 3DEngine.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "3DEngine.h"
#include "Display.h"

Display* disp;
void init() {
	disp = new Display();
}

int run() {

	return 1;
}

int main() {
	init();
	while(run());

	return 0;
}
