#pragma once
#include <external.hpp>
#include <vkargsetter.hpp>

namespace vkargsetter {

void setVkArg(VkOffset2D &offs, std::int32_t x,
              std::int32_t y) {
  offs.x = x;
  offs.y = y;
}
void setVkArg(VkOffset3D &offs, std::int32_t x,
              std::int32_t y, std::int32_t z) {
  offs.x = x;
  offs.y = y;
  offs.z = z;
}
}
