#include "engine/graphics/VkScreen.hpp"



namespace Graphics {

    
VkScreen::VkScreen(const char* title, uint16_t width, uint16_t height, SDL_WindowFlags flags): flags_m(flags) {
    width_m = width;
    height_m = height;

    // Enforce VULKAN flag
    flags |= SDL_WINDOW_VULKAN;
    
    sdlWindow = SDL_CreateWindow(title, width_m, height_m, flags);
    if (!sdlWindow) {
        fprintf(stderr, "Failed to create SDL window: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    printf("SDL window created\n");

    SDL_SetWindowPosition(sdlWindow, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

void VkScreen::cleanup() {
    SDL_DestroyWindow(sdlWindow);
}

}