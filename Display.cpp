#include "Display.h"

Display::Display() {
	VkResult temp;
	VkInstanceCreateInfo* pCreateInfo;//TODO init
	VkAllocationCallbacks* pAllocator;//TODO init
	temp= vkCreateInstance(
		pCreateInfo,
		pAllocator,
		this->instance);

	if (temp != 0) {
		printf("Error: %d", temp);
	}


}

void Display::setDisplayType(int type) {
	this->display_type = type;
	VkResult temp;
	if (type == 0) { 
		temp = vkCreateWin32SurfaceKHR(
			/*VkInstance                                  instance,
    const VkWin32SurfaceCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface*/
		);
	}
	else {
		temp = vkGetPhysicalDeviceDisplayPropertiesKHR(
			/*VkPhysicalDevice                            physicalDevice,
			uint32_t * pPropertyCount,
			VkDisplayPropertiesKHR * pProperties*/
		);
	}

	if (temp != 0) {
		printf("Error: %d", temp);
	}
}

void Display::setResolution(int wid, int hei) {
	this->width = wid;
	this->height = hei;
}

int Display::getWid() {
	return this->width;
}

int Display::getHei() {
	return this->height;
}