#pragma once
#include <external.hpp>

namespace vkargsetter {
// basic utilities

template <typename T> std::uint32_t to_uint32(T v) {
  return static_cast<std::uint32_t>(v);
}

template <typename Source, typename Target, std::size_t N>
void transform_to_arr(
    const std::array<Source, N> &a,
    std::array<Target, N> &b,
    const std::function<Target(Source)> &f) {

  for (std::size_t i = 0; i < N; i++) {
    b[i] = f(a[i]);
  }
}
template <typename Source, typename Target, std::size_t N>
void cast_to_arr(const std::array<Source, N> &a,
                 std::array<Target, N> &b) {
  const std::function<Target(Source)> f = [](Source s) {
    return static_cast<Target>(s);
  };
  transform_to_arr<Source, Target, N>(a, b, f);
}
template <typename Source, typename Target>
void transform_to_vec(
    const std::vector<Source> &a, std::vector<Target> &b,
    const std::function<Target(Source)> &f) {
  b.clear();
  for (std::size_t i = 0; i < a.size(); i++) {
    b.push_back(f(a[i]));
  }
}

template <typename Source, typename Target>
void cast_to_vec(const std::vector<Source> &a,
                 std::vector<Target> &b) {
  const std::function<Target(Source)> f = [](Source s) {
    return static_cast<Target>(s);
  };
  transform_to_vec<Source, Target>(a, b, f);
}
}
