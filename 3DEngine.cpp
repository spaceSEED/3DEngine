// 3DEngine.cpp : Defines the entry point for the application.
//


#include "3DEngine.h"

#define VK_API_VERSION_1_2 VK_MAKE_VERSION(1, 2, 0)


VkApplicationInfo Engine::appInfo = VkApplicationInfo{};
Display * Engine::disp;

 Engine::Engine() {
	glfwInit();
	if (!glfwVulkanSupported()) {
		printf("Vulkan not supported!\n");
	}

	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "3DEngine";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 2, 0);
	appInfo.pEngineName = "3DEngine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 2, 0);
	appInfo.apiVersion = VK_API_VERSION_1_2;

	disp = new Display();

	disp->setResolution(640, 480);
	disp->setDisplayType(0);

}

int Engine::run() {

	return 1;
}

int main() {
	Engine * e = new Engine();
	while(e->run());


	glfwTerminate();
	return 0;
}
