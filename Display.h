#include "framework.h"
#include "Resource.h"
#pragma once
class Display
{
	private:
		int height=0;
		int width=0;
		int display_type=0;
		VkInstance * instance=nullptr;
		VkSurfaceKHR * surface = nullptr;
		VkPhysicalDevice * device = nullptr;
		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;
	public:
		Display();
		virtual ~Display();
		void init();
		void setDisplayType(int type);//define types: windowed==0; fullscreen==1;
		void setResolution(int wid, int hei);
		int getWid();
		int getHei();
		//TODO methods to adjust display settings

};

