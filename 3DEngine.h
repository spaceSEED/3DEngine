#pragma once
#include "framework.h"
#include "resource.h"
#include "Display.h"

class Engine{
public:
	static Display* disp;
	static VkApplicationInfo appInfo;
	Engine();
	int run();
};