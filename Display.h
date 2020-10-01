#include "framework.h"
#include "Resource.h"
#pragma once
class Display
{
	private:
		int height=0;
		int width=0;
		int display_type=0;
		VkInstance  instance;// = (VkInstance*)malloc(sizeof(VkInstance));
		VkSurfaceKHR  surface;
		VkPhysicalDevice  phys_device;
		//std::vector<VkPhysicalDevice> devices;
		VkDevice device;
		VkQueue graphicsQueue;//TODO expand to multiple queues
		bool isGoodDevice(VkPhysicalDevice d);
	public:
		GLFWwindow* window;
		Display(int wid, int hei);
		virtual ~Display();
		void setDisplayType(int type);//define types: windowed==0; fullscreen==1;
		void setResolution(int wid, int hei);
		int getWid();
		int getHei();
		//TODO methods to adjust display settings

};

