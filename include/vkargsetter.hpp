#pragma once
#include <utils.hpp>

namespace vkargsetter {

void setVkArg() {}

template <class StructType, std::size_t N, class... Ts>
struct setVkArray {
  static void set(StructType &s,
                  const std::array<Ts, N> &... arrs) {}
};

template <class StructType, class... Ts>
struct setVkVector {
  static void set(StructType &s,
                  const std::vector<Ts> &... vecs) {}
};
};
