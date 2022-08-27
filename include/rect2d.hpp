#pragma once
#include <extent.hpp>
#include <external.hpp>
#include <offset.hpp>
#include <vkargsetter.hpp>

namespace vkargsetter {

/**
Rectangles are used to describe a specified rectangular
region of pixels within an image or
framebuffer. Rectangles include both an offset and an extent
of the same dimensionality, as
described above. Two-dimensional rectangles are defined by
the structure
 */
void setVkArg(VkRect2D &rect, const VkOffset2D &off,
              const VkExtent2D &ext) {
  rect.offset = off;
  rect.extent = ext;
}
}
