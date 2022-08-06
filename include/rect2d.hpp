#pragma once
#include <extent.hpp>
#include <external.hpp>
#include <offset.hpp>
#include <vkargsetter.hpp>

namespace vkargsetter {
void setVkArg(VkRect2D &rect, const VkOffset2D &off,
              const VkExtent2D &ext) {
  rect.offset = off;
  rect.extent = ext;
}
}
