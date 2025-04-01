#version 450

layout(binding = 0) uniform UniformBufferObject {
    mat4 model;
    mat4 view;
    mat4 proj;
} ubo;

layout(location = 0) in vec2 position_in;
layout(location = 1) in vec3 color_in;

layout(location = 0) out vec3 frag_color;

void main() {
    gl_Position = ubo.proj * ubo.view * ubo.model * vec4(position_in, 0.0, 1.0);
    frag_color = color_in;
}
