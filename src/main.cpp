#include "engine/graphics/VkManager.hpp"


int main(void) {
	printf("Hello, Vulkan!\n");

	// Initialise SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
		printf("SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

	VK::Init();
	printf("Vulkan initialized\n");

	VK::VkManager::instance().showWindow();
	
	// ----- Main loop -----
    bool running = true;
    SDL_Event event;
    while (running) {
        // Poll for events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
			else if (event.type == SDL_EVENT_KEY_DOWN) {
				if (event.key.key == SDLK_ESCAPE || event.key.key == SDLK_Q) {
					printf("Quitting...\n");
					running = false;
				}
			}
        }

		VK::VkManager::instance().drawFrame();
    }

	VK::VkManager::instance().waitIdle();

	VK::Quit();
	printf("Vulkan cleaned up\n");

	// Cleanup SDL
	printf("Cleaning up SDL\n");
    SDL_Quit();
	
	printf("Goodbye Vulkan!\n");
	printf("Built: %s %s\n", __DATE__, __TIME__);
}
