#pragma once

#include "VkCommon.hpp"

namespace Graphics {

    
class VkScreen {
public:
    VkScreen(const char* title, uint16_t width, uint16_t height, SDL_WindowFlags flags);

    // Convenience functions
    SDL_WindowFlags get_flags() const { return flags_m; }
    SDL_Window* sdlWindow{nullptr};
    void cleanup();
private:
    uint16_t width_m;
    uint16_t height_m;

    const SDL_WindowFlags flags_m;

};


}
