cmake_minimum_required(VERSION 3.31.6)

include(/Users/thorbenschirra/pico-sdk/pico_sdk_init.cmake)

project(graphics_pipeline_128x32)
add_executable(graphics_pipeline_128x32
    main.cpp
    framebuffer/framebuffer.cpp
    driver/ssd1305.cpp
)

pico_sdk_init()

target_link_libraries(graphics_pipeline_128x32 
    pico_stdlib
    hardware_spi
)

pico_add_extra_outputs(graphics_pipeline_128x32)