#pragma once
#include <external.hpp>
#include <vkargsetter.hpp>

namespace vkargsetter {

/** VkPhysicalDeviceProperties

  \code{.cpp}
typedef struct VkPhysicalDeviceProperties {

uint32_t apiVersion;

uint32_t driverVersion;

uint32_t vendorID;

uint32_t deviceID;

VkPhysicalDeviceType deviceType;

char deviceName[VK_MAX_PHYSICAL_DEVICE_NAME_SIZE];

uint8_t pipelineCacheUUID[VK_UUID_SIZE];

VkPhysicalDeviceLimits limits;

VkPhysicalDeviceSparseProperties sparseProperties;
} VkPhysicalDeviceProperties;
  \endcode

- apiVersion is the version of Vulkan supported by the
device, encoded as described in Version
Numbers.
- driverVersion is the vendor-specified version of the
driver.
- vendorID is a unique identifier for the vendor (see below)
of the physical device.
- deviceID is a unique identifier for the physical device
among devices available from the vendor.
- deviceType is a VkPhysicalDeviceType specifying the type
of device.
- deviceName is an array of VK_MAX_PHYSICAL_DEVICE_NAME_SIZE
char containing a null-terminated
UTF-8 string which is the name of the device.
- pipelineCacheUUID is an array of VK_UUID_SIZE uint8_t
values representing a universally unique
identifier for the device.
- limits is the VkPhysicalDeviceLimits structure specifying
device-specific limits of the physical
device. See Limits for details.
- sparseProperties is the VkPhysicalDeviceSparseProperties
structure specifying various sparse
related properties of the physical device. See Sparse
Properties for details.
 */
constexpr void setVkArg(VkPhysicalDeviceProperties2 &prop) {
  prop.sType =
      VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;
}

void setVkArg(VkPhysicalDeviceProperties2 &prop,
              const VkPhysicalDeviceProperties &p) {
  prop.properties = p;
}
}
