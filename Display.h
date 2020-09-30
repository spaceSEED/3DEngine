#include "framework.h"
#include "Resource.h"
#pragma once
class Display
{
	private:
		int height;
		int width;
		int display_type;
		VkInstance * instance;
		VkSurfaceKHR surface;
		VkPhysicalDevice device;
	public:
		void init();
		void setDisplayType(int type);//define types: windowed==0; fullscreen==1;
		void setResolution(int wid, int hei);
		int getWid();
		int getHei();
		//TODO methods to adjust display settings

};

