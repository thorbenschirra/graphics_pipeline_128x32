cmake_minimum_required(VERSION 3.31.6)

include(/Users/thorbenschirra/pico-sdk/pico_sdk_init.cmake)

project(graphics_pipeline_128x32)

pico_sdk_init()

add_executable(graphics_pipeline_128x32
main.cpp
framebuffer/
driver/
)

target_include_directories(graphics_pipeline_128x32 PRIVATE
    driver
    framebuffer/
)

target_link_libraries(graphics_pipeline_128x32 
    pico_stdlib
    hardware_spi
)

pico_add_extra_outputs(graphics_pipeline_128x32)