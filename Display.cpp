
#include "Display.h"
#include "3DEngine.h"

Display::Display() {
	this->width = 640;
	this->height = 480;
	this->display_type = 0;
	this->instance = nullptr;
	this->surface = nullptr;
	this->device = nullptr;
	this->glfwExtensionCount = 0;

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	this->window = glfwCreateWindow(this->width, this->height, "Vulkan", nullptr, nullptr);

	
	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &Engine::appInfo;

	const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	if (glfwExtensions == NULL) {
		printf("glfw ERROR!");
	}

	createInfo.enabledExtensionCount = glfwExtensionCount;
	createInfo.ppEnabledExtensionNames = glfwExtensions;
	createInfo.enabledLayerCount = 0;

	//VkAllocationCallbacks * pAllocator=nullptr;// (VkAllocationCallbacks*)malloc(sizeof(VkAllocationCallbacks));//TODO init
	if (vkCreateInstance(
		&createInfo,
		nullptr,
		&this->instance) != VK_SUCCESS) {
		printf("Error!");
	}
	
}
Display::~Display() {
	glfwDestroyWindow(window);
	vkDestroyInstance(instance, nullptr);

}


void Display::setDisplayType(int type) {
	this->display_type = type;
	//VkResult temp;
	if (type == 0) { 
		//temp = vkCreateWin32SurfaceKHR(
			//*(this->instance),
			/*VkInstance                                  instance,
    const VkWin32SurfaceCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface*/
		//);
	}
	else {
		//temp = vkGetPhysicalDeviceDisplayPropertiesKHR(
			/*VkPhysicalDevice                            physicalDevice,
			uint32_t * pPropertyCount,
			VkDisplayPropertiesKHR * pProperties*/
		//);
	}

	/*if (temp != VK_SUCCESS) {
		printf("Error: %d", temp);
	}*/
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