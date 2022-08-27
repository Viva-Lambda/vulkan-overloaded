#pragma once
#include <external.hpp>
#include <vkargsetter.hpp>

namespace vkargsetter {
/** VkValidationFlagsEXT

When creating a Vulkan instance for which you wish to
disable validation
checks, add a VkValidationFlagsEXT structure to the pNext
chain of the
VkInstanceCreateInfo structure, specifying the checks to be
disabled.

\code{.cpp}
// Provided by VK_EXT_validation_flags
typedef struct VkValidationFlagsEXT {

VkStructureType sType;

const void* pNext;

uint32_t disabledValidationCheckCount;

const VkValidationCheckEXT* pDisabledValidationChecks;
} VkValidationFlagsEXT;
\endcode

- sType is the type of this structure.
- pNext is NULL or a pointer to a structure extending this
structure.
- disabledValidationCheckCount is the number of checks to
disable.
- pDisabledValidationChecks is a pointer to an array of
VkValidationCheckEXT values specifying
the validation checks to be disabled.

 */
constexpr void setVkArg(VkValidationFlagsEXT &val) {
  val.sType = VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT;
}

void setVkArg(VkValidationFlagsEXT &val,
              const void *pnext) {
  val.pNext = pnext;
}
void setVkArg(VkValidationFlagsEXT &val,
              std::uint32_t disabledValidationCheckCount) {
  val.disabledValidationCheckCount =
      disabledValidationCheckCount;
}
void setVkArg(
    VkValidationFlagsEXT &val,
    const VkValidationCheckEXT *validationChecks) {
  val.pDisabledValidationChecks = validationChecks;
}

template <std::size_t N>
struct setVkArray<VkValidationFlagsEXT, N,
                  VkValidationCheckEXT> {
  static void
  set(VkValidationFlagsEXT &val,
      const std::array<VkValidationCheckEXT, N> &checks) {
    val.pDisabledValidationChecks = checks.data();
    val.disabledValidationCheckCount =
        to_uint32(checks.size());
  }
};
void setVkArg(
    VkValidationFlagsEXT &val,
    const std::vector<VkValidationCheckEXT> &checks) {
  val.pDisabledValidationChecks = checks.data();
  val.disabledValidationCheckCount =
      to_uint32(checks.size());
}

/** VkValidationFeaturesEXT

When creating a Vulkan instance for which you wish to enable
or disable
specific validation features, add a VkValidationFeaturesEXT
structure to the
pNext chain of the VkInstanceCreateInfo structure,
specifying the features to
be enabled or disabled.

\code{.cpp}
// Provided by VK_EXT_validation_features
typedef struct VkValidationFeaturesEXT {

VkStructureType sType

const void* pNext

uint32_t enabledValidationFeatureCount

const VkValidationFeatureEnableEXT*
pEnabledValidationFeatures

uint32_t disabledValidationFeatureCount

const VkValidationFeatureDisableEXT*
pDisabledValidationFeatures
} VkValidationFeaturesEXT;
\endcode

- sType is the type of this structure.
- pNext is NULL or a pointer to a structure extending this
structure.
- enabledValidationFeatureCount is the number of features to
enable.
- pEnabledValidationFeatures is a pointer to an array of
VkValidationFeatureEnableEXT values
specifying the validation features to be enabled.
- disabledValidationFeatureCount is the number of features
to disable.
- pDisabledValidationFeatures is a pointer to an array of
VkValidationFeatureDisableEXT values specifying the
validation features to be
disabled.

 */

constexpr void setVkArg(VkValidationFeaturesEXT &val) {
  val.sType = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT;
}

void setVkArg(VkValidationFeaturesEXT &val,
              const void *pnext) {
  val.pNext = pnext;
}

void setVkArg(VkValidationFeaturesEXT &val,
              std::uint32_t enabledCount,
              std::uint32_t disabledCount) {
  val.enabledValidationFeatureCount = enabledCount;
  val.disabledValidationFeatureCount = disabledCount;
}

void setVkArg(VkValidationFeaturesEXT &val,
              const VkValidationFeatureEnableEXT *enabled) {
  val.pEnabledValidationFeatures = enabled;
}

void setVkArg(
    VkValidationFeaturesEXT &val,
    const VkValidationFeatureDisableEXT *disabled) {
  val.pDisabledValidationFeatures = disabled;
}

template <std::size_t N>
struct setVkArray<VkValidationFeaturesEXT, N,
                  VkValidationFeatureEnableEXT,
                  VkValidationFeatureDisableEXT> {
  static void
  set(VkValidationFeaturesEXT &val,
      const std::array<VkValidationFeatureEnableEXT, N>
          &enabled,
      const std::array<VkValidationFeatureDisableEXT, N>
          &disabled) {
    val.pEnabledValidationFeatures = enabled.data();
    val.pDisabledValidationFeatures = disabled.data();
    val.enabledValidationFeatureCount = to_uint32(N);
    val.disabledValidationFeatureCount = to_uint32(N);
  }
};

template <>
struct setVkVector<VkValidationFeaturesEXT,
                   VkValidationFeatureEnableEXT,
                   VkValidationFeatureDisableEXT> {
  static void
  set(VkValidationFeaturesEXT &val,
      const std::vector<VkValidationFeatureEnableEXT>
          &enabled,
      const std::vector<VkValidationFeatureDisableEXT>
          &disabled) {
    val.pEnabledValidationFeatures = enabled.data();
    val.pDisabledValidationFeatures = disabled.data();
    val.enabledValidationFeatureCount =
        to_uint32(enabled.size());
    val.disabledValidationFeatureCount =
        to_uint32(disabled.size());
  }
};
}
