
#include "Display.h"
#include "3DEngine.h"
#include <optional>

Display::Display(int wid, int hei) {
	//Initialize Variables and default settings
	this->width = wid;
	this->height = hei;
	this->display_type = 0;
	this->instance = nullptr;
	this->surface = nullptr;
	this->phys_device = VK_NULL_HANDLE;

	//Create Window
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	this->window = glfwCreateWindow(this->width, this->height, Engine::appInfo.pApplicationName, nullptr, nullptr);

	//Create Instance
	VkInstanceCreateInfo icreateInfo{};
	icreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	icreateInfo.pApplicationInfo = &Engine::appInfo;

	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	if (glfwExtensions == NULL) {
		printf("glfw ERROR!");
	}

	icreateInfo.enabledExtensionCount = glfwExtensionCount;
	icreateInfo.ppEnabledExtensionNames = glfwExtensions;
	icreateInfo.enabledLayerCount = 0;

	//VkAllocationCallbacks * pAllocator=nullptr;// (VkAllocationCallbacks*)malloc(sizeof(VkAllocationCallbacks));//TODO init
	if (vkCreateInstance(
		&icreateInfo,
		nullptr,
		&this->instance) != VK_SUCCESS) {
		printf("Error!");
	}

	//Get Physical Device (GPU)
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
	if (deviceCount == 0) {
		printf("No Vulkan Devices!\n");
	}
	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

	for (int i = 0; i < deviceCount; i++) {
		if (isGoodDevice(devices.at(i))) {
			phys_device = devices.at(i);// get a better device
			break;
		}
	}
	if (device == VK_NULL_HANDLE) {
		printf("No suitable device available!\n");
	}
	
	//check queue families
	uint32_t queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(phys_device, &queueFamilyCount, nullptr);
	std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(phys_device, &queueFamilyCount, queueFamilies.data());
	std::optional<uint32_t> indices;
	int i = 0;
	for (const auto& queueFamily : queueFamilies) {
		if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
			indices = i;
		}
		i++;
	}
	
	//Create Logical Device
	VkDeviceQueueCreateInfo queueCreateInfo{};
	queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	queueCreateInfo.queueFamilyIndex = indices.value();
	queueCreateInfo.queueCount = 1;

	VkDeviceCreateInfo dcreateInfo{};
	dcreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	dcreateInfo.pQueueCreateInfos = &queueCreateInfo;
	dcreateInfo.queueCreateInfoCount = 1;
	VkPhysicalDeviceFeatures pdf;
	vkGetPhysicalDeviceFeatures(phys_device, &pdf);
	dcreateInfo.pEnabledFeatures = &pdf;
	dcreateInfo.enabledExtensionCount = 0;
	dcreateInfo.enabledLayerCount = 0;
	if (vkCreateDevice(phys_device, &dcreateInfo, nullptr, &device) != VK_SUCCESS) {
		printf("failed to create logical device!\n");
	}
	//Get Graphics Queue
	vkGetDeviceQueue(device, indices.value(), 0, &graphicsQueue);

}
Display::~Display() {
	glfwDestroyWindow(window);
	vkDestroyInstance(instance, nullptr);
	vkDestroyDevice(device, nullptr);

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