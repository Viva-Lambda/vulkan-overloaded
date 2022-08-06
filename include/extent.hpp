#pragma once
#include <external.hpp>
#include <vkargsetter.hpp>

namespace vkargsetter {
void setVkArg(VkExtent2D &extent, std::uint32_t width,
              std::uint32_t height) {
  extent.width = width;
  extent.height = height;
}
void setVkArg(VkExtent3D &extent, std::uint32_t width,
              std::uint32_t height, std::uint32_t depth) {
  extent.width = width;
  extent.height = height;
  extent.depth = depth;
}
};
