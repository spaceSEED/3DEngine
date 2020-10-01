
#include "Display.h"
#include "3DEngine.h"

Display::Display(int wid, int hei) {
	this->width = wid;
	this->height = hei;
	this->display_type = 0;
	this->instance = nullptr;
	this->surface = nullptr;
	this->device = VK_NULL_HANDLE;

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	this->window = glfwCreateWindow(this->width, this->height, Engine::appInfo.pApplicationName, nullptr, nullptr);

	
	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &Engine::appInfo;

	uint32_t glfwExtensionCount = 0;
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

	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
	if (deviceCount == 0) {
		printf("No Vulkan Devices!\n");
	}
	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

	for (int i = 0; i < deviceCount; i++) {
		if (isGoodDevice(devices.at(i))) {
			device = devices.at(i);// get a better device
			break;
		}
	}
	if (device == VK_NULL_HANDLE) {
		printf("No suitable device available!\n");
	}
	
	
	
}
Display::~Display() {
	glfwDestroyWindow(window);
	vkDestroyInstance(instance, nullptr);

}

bool Display::isGoodDevice(VkPhysicalDevice d) {
	VkPhysicalDeviceProperties pdp;
	vkGetPhysicalDeviceProperties(d,&pdp);
	VkPhysicalDeviceFeatures pdf;
	vkGetPhysicalDeviceFeatures(d, &pdf);

	printf(pdp.deviceName);
	return pdp.deviceType==VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU && pdf.geometryShader;//check pdf against desired graphics features?
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