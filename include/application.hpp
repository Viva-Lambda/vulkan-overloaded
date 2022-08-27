#pragma once
#include <external.hpp>
#include <vkargsetter.hpp>

namespace vkargsetter {

/** VkApplicationInfo

\code{.cpp}

// Provided by VK_VERSION_1_0
typedef struct VkApplicationInfo {

VkStructureType sType;

const void* pNext;

const char* pApplicationName;

uint32_t applicationVersion;

const char* pEngineName;

uint32_t engineVersion;

uint32_t apiVersion;
} VkApplicationInfo;
\endcode

- sType is the type of this structure.
- pNext is NULL or a pointer to a structure extending this
structure.
- pApplicationName is NULL or is a pointer to a
null-terminated UTF-8 string containing the name of
the application.
- applicationVersion is an unsigned integer variable
containing the developer-supplied version
number of the application.
- pEngineName is NULL or is a pointer to a null-terminated
UTF-8 string containing the name of the
engine (if any) used to create the application.
- engineVersion is an unsigned integer variable containing
the developer-supplied version
number of the engine used to create the application.
- apiVersion must be the highest version of Vulkan that the
application is designed to use,
encoded as described in Version Numbers. The patch version
number specified in apiVersion is
ignored when creating an instance object. Only the major and
minor versions of the instance
must match those requested in apiVersion.
Vulkan 1.0 implementations were required to return
VK_ERROR_INCOMPATIBLE_DRIVER if apiVersion
was larger than 1.0. Implementations that support Vulkan 1.1
or later must not return
VK_ERROR_INCOMPATIBLE_DRIVER for any value of apiVersion.
 */

constexpr void setVkArg(VkApplicationInfo &info) {
  info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
}

void setVkArg(VkApplicationInfo &info,
              std::uint32_t applicationVersion,
              std::uint32_t engineVersion,
              std::uint32_t apiVersion) {
  info.applicationVersion = applicationVersion;
  info.engineVersion = engineVersion;
  info.apiVersion = apiVersion;
}
void setVkArg(VkApplicationInfo &info,
              const char *applicationName,
              const char *engineName) {
  info.pApplicationName = applicationName;
  info.pEngineName = engineName;
}

void setVkArg(VkApplicationInfo &info,
              const std::string &applicationName,
              const std::string &engineName) {
  info.pApplicationName = applicationName.c_str();
  info.pEngineName = engineName.c_str();
}
}
