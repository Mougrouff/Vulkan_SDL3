#pragma once

#include "VkCommon.hpp"
#include "VkScreen.hpp"
namespace Graphics{

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////  Global utils functions  ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

bool check_validation_layer_support();
char const * const * get_required_extensions(const VkConfiguration& config, uint32_t& count);


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////  Global configuration  //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

#define NUM_VALIDATION_LAYERS 1
static const char* ValidationLayers[NUM_VALIDATION_LAYERS] = {
	"VK_LAYER_KHRONOS_validation"
};

#define NUM_DEVICE_EXTENSIONS 1
static const char* DeviceExtensions[NUM_DEVICE_EXTENSIONS] = {
	VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

#define MAX_FRAMES_IN_FLIGHT 2

#define WIDTH 800
#define HEIGHT 600


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////  Vk interface  ////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

class VkManager{
public:
    static VkManager& instance() {
        static VkManager instance;
        return instance;
    }

    VkManager(const VkManager&) = delete;
    void operator=(const VkManager&) = delete;

    uint32_t find_memory_type(uint32_t type_filter, VkMemoryPropertyFlags properties);
    DeviceResource createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties);
    void copyBuffer(VkBuffer src_buffer, VkBuffer dst_buffer, VkDeviceSize size);
    void clearResource(DeviceResource& resource);
    void showWindow();
    void waitIdle();

    // Not sure if should be public
    Graphics::SwapChainSupportDetails query_swap_chain_support(VkPhysicalDevice device);
    QueueFamilyIndices find_queue_families(VkPhysicalDevice device);
    VkPhysicalDevice pick_physical_device();
    void create_image_views();
    void cleanup_image_views();
    void create_framebuffers();
    void cleanup_framebuffers();
    void create_swap_chain();
    void cleanup_swap_chain();
    void recreate_swap_chain();
    VkShaderModule create_shader_module(const char* code, size_t code_size);
    VkExtent2D choose_swap_extent(VkSurfaceCapabilitiesKHR *capabilities);
    void create_graphics_pipeline();
    void init_vulkan();
    void draw_frame();
    void cleanup_vulkan();
    void record_command_buffer(VkCommandBuffer command_buffer, uint32_t image_index);

private:
    explicit VkManager();

    VkScreen vkScreen;

    VkInstance vkInstance{0};

    VkDebugUtilsMessengerEXT debug_messenger{0};
    VkSurfaceKHR surface{0};

    VkPhysicalDevice physical_device{VK_NULL_HANDLE};
    VkDevice device{0};

    VkQueue graphics_queue = {0};
    VkQueue present_queue = {0};

    // handle to images swap chain (images buffer)
    VkSwapchainKHR swap_chain = {0};
    uint32_t swap_chain_images_count = 0;
    VkImage *swap_chain_images = NULL;
    VkFormat swap_chain_image_format = VK_FORMAT_UNDEFINED;
    VkExtent2D swap_chain_extent = {0};
    uint32_t swap_chain_image_views_count = 0;
    VkImageView *swap_chain_image_views = NULL;
    uint32_t swap_chain_framebuffers_count = 0;
    VkFramebuffer *swap_chain_framebuffers = NULL;

    // Framebuffer informations and configuration
    VkRenderPass render_pass = {0};
    VkDescriptorSetLayout descriptor_set_layout = {0};
    VkPipelineLayout pipeline_layout = {0};
    VkPipeline graphics_pipeline = {0};

    VkDescriptorPool descriptor_pool = {0};
    VkDescriptorSet descriptor_sets[MAX_FRAMES_IN_FLIGHT] = {0};

    VkCommandPool command_pool = {0};
    const uint32_t command_buffers_count = MAX_FRAMES_IN_FLIGHT;
    VkCommandBuffer command_buffers[MAX_FRAMES_IN_FLIGHT] = {0};

    const uint32_t image_available_semaphores_count = MAX_FRAMES_IN_FLIGHT;
    VkSemaphore image_available_semaphores[MAX_FRAMES_IN_FLIGHT] = {0};
    const uint32_t render_finished_semaphores_count = MAX_FRAMES_IN_FLIGHT;
    VkSemaphore render_finished_semaphores[MAX_FRAMES_IN_FLIGHT] = {0};
    const uint32_t in_flight_fences_count = MAX_FRAMES_IN_FLIGHT;
    VkFence in_flight_fences[MAX_FRAMES_IN_FLIGHT] = {0};

    uint32_t current_frame = 0;
    bool framebuffer_resized = false;

    Graphics::VkConfiguration vk_config{
        .enableValidationLayers = true,
        .maxValidationLayers = 1,
        .numValidationLayers = 1,
        .numdeviceExtensions = 1
    };

};






} // Namespace Graphics