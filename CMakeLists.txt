cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project("Vulkan Overloaded")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)

# cmake .. -D CMAKE_CXX_COMPILER="/home/kaan/miniconda3/envs/clang/bin/clang-cpp" -D CMAKE_INSTALL_PREFIX="../bin/"

# set(CMAKE_CXX_FLAGS "-std=c++17")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -ggdb -Wall -Wextra -o2 -pedantic")

set(AbsPathPrefix 
    "/home/kaan/GitProjects")

# executables

# main program
add_executable(
    vmain.out 
    "src/vkmain.cpp"
)

# simple triangle program

include_directories("./include/")

# libs and linking etc

# vulkan
set(VulkanPath "${AbsPathPrefix}/vulkan-1.2/x86_64")
# find_package(Vulkan REQUIRED)
add_library(VulkanLib SHARED IMPORTED)
set_target_properties(VulkanLib PROPERTIES IMPORTED_LOCATION
    "${VulkanPath}/lib/libvulkan.so"
)
message("Vulkan Include Path: ${VulkanPath}/include/")
message("Vulkan Library Path: ${VulkanPath}/lib/libvulkan.so")
include_directories("${VulkanPath}/include/")

# vk main
target_link_libraries(vmain.out -lm VulkanLib)

# glfw
# find_package(glfw3 REQUIRED)
add_library(glfwLib SHARED IMPORTED)
set_target_properties(glfwLib PROPERTIES IMPORTED_LOCATION
    "${AbsPathPrefix}/glfw-3.3.4/bin/lib/libglfw.so")
include_directories("${AbsPathPrefix}/glfw-3.3.4/bin/include/")

# vk main
target_link_libraries(vmain.out -lm glfwLib)


# glm
# find_package(glm REQUIRED)
include_directories("${AbsPathPrefix}/glm/glm/")
# target_link_libraries(ex01.out ${glm_LIBRARY_DIRS})


add_library(
    AssimpLib 
    SHARED 
    IMPORTED
)
set_target_properties(
    AssimpLib PROPERTIES IMPORTED_LOCATION 
    "${AbsPathPrefix}/assimp-5.0.1/build/code/libassimp.so.5"
)
include_directories("${AbsPathPrefix}/assimp-5.0.1/build/include/")

# vk main
target_link_libraries(vmain.out -lm -ldl AssimpLib)

# libs

install(TARGETS vmain.out DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
