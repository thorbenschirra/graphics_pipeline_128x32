cmake_minimum_required(VERSION 3.31.6)

set(PICO_BOARD pico2_w)
set(PICO_PLATFORM rp2350)

include(/Users/thorbenschirra/pico-sdk/external/pico_sdk_import.cmake)

project(graphics_pipeline_128x32)

pico_sdk_init()

add_executable(graphics_pipeline_128x32
main.cpp
framebuffer/framebuffer.cpp
framebuffer/framebuffer.h
driver/ssd1305.cpp
)

target_include_directories(graphics_pipeline_128x32 PRIVATE
    driver/
    framebuffer/
)

target_link_libraries(graphics_pipeline_128x32 
    pico_stdlib
    hardware_spi
)

pico_add_extra_outputs(graphics_pipeline_128x32)