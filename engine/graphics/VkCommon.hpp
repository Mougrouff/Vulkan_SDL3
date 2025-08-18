#pragma once

extern "C" {
	#include <SDL3/SDL.h>
	#include <SDL3/SDL_vulkan.h>
	#include <vulkan/vulkan.h>
	#include "io.h"
	#include <stdio.h>
	#include <stdbool.h>
	#include <stdlib.h>
	#include <string.h>
	#include <assert.h>
	
	#include <cglm/cglm.h>

	#include "io.h"
}
namespace Graphics{

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  Common data types  ///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////


// Configuration

struct QueueFamilyIndices {
    uint32_t graphics_family;
    uint32_t present_family;
	bool has_graphics_family;
	bool has_present_family;
};

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
	uint32_t formats_count;
	uint32_t present_modes_count;
	VkSurfaceFormatKHR* formats;
	VkPresentModeKHR* present_modes;
};

struct VkConfiguration {
    int maxFramesInFlight = 2;
    bool enableValidationLayers = true;
    int maxValidationLayers = 1;
    int numValidationLayers = 1;
    int numdeviceExtensions = 1;
};

// Data structures

struct Vertex {
	vec2 pos;
	vec3 color;
};

template <uint32_t Vertices, uint32_t Indices>
struct Mesh {
	Vertex vertices[Vertices];
	uint16_t indices[Indices];
	uint32_t vertex_count = Vertices;
	uint32_t index_count = Indices;
};

struct UniformBufferObject {
	mat4 model;
	mat4 view;
	mat4 proj;
};

struct DeviceResource {
	VkBuffer buffer{0};
	VkDeviceMemory memory{0};
	VkDeviceSize size{0};
};

}