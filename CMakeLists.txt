cmake_minimum_required(VERSION 3.12)
project("stable-diffusion")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT XCODE AND NOT MSVC AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set(SD_STANDALONE ON)
else()
    set(SD_STANDALONE OFF)
endif()

add_subdirectory(stable-diffusion.cpp)

set(SD_UI stable_diffusion_ui)

add_library(${SD_UI} ./imgui/imgui.cpp ./imgui/imgui_demo.cpp ./imgui/imgui_draw.cpp ./imgui/imgui_tables.cpp ./imgui/imgui_widgets.cpp ./imgui/backends/imgui_impl_glfw.cpp ./imgui/backends/imgui_impl_opengl3.cpp )
target_link_libraries(${SD_UI} PUBLIC stable-diffusion)
target_include_directories(${SD_UI} PUBLIC ./imgui)
target_include_directories(${SD_UI} PUBLIC ./imgui/backends)
target_compile_features(${SD_UI} PUBLIC cxx_std_11)

set(SD_EXEC sd_ui)
add_executable(${SD_EXEC} main.cpp src/sd_ui.cpp)
target_include_directories(${SD_EXEC} PUBLIC ./imgui)
target_include_directories(${SD_EXEC} PUBLIC ./imgui/backends)
if(APPLE)
    target_link_libraries(${SD_EXEC} PRIVATE ${SD_UI} glfw "-framework OpenGL")
else()
    target_link_libraries(${SD_EXEC} PRIVATE ${SD_UI} glfw)
endif()
