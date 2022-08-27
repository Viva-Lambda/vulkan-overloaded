#pragma once
#include <external.hpp>
#include <vkargsetter.hpp>

namespace vkargsetter {

/** VkInstanceCreateInfo

\code{.cpp}

typedef struct VkInstanceCreateInfo {

VkStructureType sType;

const void* pNext;

VkInstanceCreateFlags flags;

const VkApplicationInfo* pApplicationInfo;

uint32_t enabledLayerCount;

const char* const* ppEnabledLayerNames;

uint32_t enabledExtensionCount;

const char* const* ppEnabledExtensionNames;
} VkInstanceCreateInfo;
\endcode

- sType is the type of this structure.
- pNext is NULL or a pointer to a structure extending this
structure.
- flags is reserved for future use.
- pApplicationInfo is NULL or a pointer to a
VkApplicationInfo structure. If
not NULL, this information helps implementations recognize
behavior inherent
to classes of applications. VkApplicationInfo is defined in
detail below.
- enabledLayerCount is the number of global layers to
enable.
- ppEnabledLayerNames is a pointer to an array of
enabledLayerCount null-terminated UTF-8 strings
containing the names of layers to enable for the created
instance. The layers are loaded in the
order they are listed in this array, with the first array
element being the closest to the
application, and the last array element being the closest to
the driver. See the Layers section for
further details.
- enabledExtensionCount is the number of global extensions
to enable.
- ppEnabledExtensionNames is a pointer to an array of
enabledExtensionCount
null-terminated UTF-8 strings containing the names of
extensions to enable.

 */
constexpr void setVkArg(VkInstanceCreateInfo &info) {
  info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
}

void setVkArg(VkInstanceCreateInfo &info,
              const VkApplicationInfo *appinfo) {
  info.pApplicationInfo = appinfo;
}

void setVkArg(VkInstanceCreateInfo &info,
              const void *pnext) {
  info.pNext = pnext;
}

void setVkArg(VkInstanceCreateInfo &info,
              const VkApplicationInfo &appinfo) {
  info.pApplicationInfo = &appinfo;
}
void setVkArg(VkInstanceCreateInfo &info,
              std::uint32_t enabledLayerCount,
              std::uint32_t enabledExtensionCount) {
  info.enabledLayerCount = enabledLayerCount;
  info.enabledExtensionCount = enabledExtensionCount;
}

void setVkArg(VkInstanceCreateInfo &info,
              const char *const *layerNames,
              const char *const *extensionNames) {
  info.ppEnabledLayerNames = layerNames;
  info.ppEnabledExtensionNames = extensionNames;
}

template <std::size_t N>
struct setVkArray<VkInstanceCreateInfo, N, const char *> {
  static void
  set(VkInstanceCreateInfo &info,
      const std::array<const char *, N> &layerNames,
      const std::array<const char *, N> &extensionNames) {
    info.ppEnabledLayerNames = layerNames.data();
    info.ppEnabledExtensionNames = extensionNames.data();
    info.enabledLayerCount = static_cast<std::uint32_t>(N);

    info.enabledExtensionCount =
        static_cast<std::uint32_t>(N);
  }
};

template <>
struct setVkVector<VkInstanceCreateInfo, const char *> {
  static void
  set(VkInstanceCreateInfo &info,
      const std::vector<const char *> &layerNames,
      const std::vector<const char *> &extensionNames) {
    info.ppEnabledExtensionNames = extensionNames.data();
    info.ppEnabledLayerNames = layerNames.data();
    info.enabledExtensionCount =
        to_uint32(extensionNames.size());

    info.enabledLayerCount = to_uint32(layerNames.size());
  }
};

template <std::size_t N>
struct setVkArray<VkInstanceCreateInfo, N, std::string> {
  static void
  set(VkInstanceCreateInfo &info,
      const std::array<std::string, N> &layerNames,
      const std::array<std::string, N> &extensionNames) {
    //
    std::array<const char *, N> layerChars;
    std::array<const char *, N> extChars;
    const std::function<const char *(std::string)> f =
        [](std::string s) { return s.c_str(); };
    transform_to_arr(layerNames, layerChars, f);
    transform_to_arr(extensionNames, extChars, f);

    info.ppEnabledLayerNames = layerChars.data();
    info.ppEnabledExtensionNames = extChars.data();
    info.enabledLayerCount = static_cast<std::uint32_t>(N);

    info.enabledExtensionCount =
        static_cast<std::uint32_t>(N);
  }
};
void setVkArg(
    VkInstanceCreateInfo &info,
    const std::vector<std::string> &layerNames,
    const std::vector<std::string> &extensionNames) {
  std::vector<const char *> layerChars;
  std::vector<const char *> extChars;
  std::function<const char *(std::string)> f =
      [](std::string s) { const char* str = s.c_str(); return str;};
  transform_to_vec(layerNames, layerChars, f);
  transform_to_vec(extensionNames, extChars, f);

  info.ppEnabledExtensionNames = layerChars.data();
  info.ppEnabledLayerNames = extChars.data();
  info.enabledExtensionCount =
      to_uint32(extensionNames.size());

  info.enabledLayerCount = to_uint32(layerNames.size());
}
}
