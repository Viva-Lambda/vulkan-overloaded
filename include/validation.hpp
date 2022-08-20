#pragma once
#include <external.hpp>
#include <vkargsetter.hpp>

namespace vkargsetter {
constexpr void setVkArg(VkValidationFlagsEXT &val) {
  val.sType = VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT;
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

constexpr void setVkArg(VkValidationFeaturesEXT &val) {
  val.sType = VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT;
}

void setVkArg(VkValidationFeaturesEXT &val,
              std::uint32_t enabledCount,
              std::uint32_t disabledCount) {
  val.enabledValidationFeatureCount = enabledCount;
  val.disabledValidationFeatureCount = disabledCount;
}

void setVkArg(
    VkValidationFeaturesEXT &val,
    const VkValidataionFeatureEnableEXT *enabled) {
  val.pEnabledValidationFeatures = enabled;
}

void setVkArg(
    VkValidationFeaturesEXT &val,
    const VkValidataionFeatureDisableEXT *disabled) {
  val.pDisabledValidationFeatures = disabled;
}

template <std::size_t N>
struct setVkArray<VkValidationFeaturesEXT, N,
                  VkValidataionFeatureEnableEXT,
                  VkValidationFeatureDisableEXT> {
  static void
  set(VkValidationFeaturesEXT &val,
      const std::array<VkValidataionFeatureEnableEXT, N>
          &enabled,
      const std::array<VkValidataionFeatureDisableEXT, N>
          &disabled) {
    val.pEnabledValidationFeatures = enabled.data();
    val.pDisabledValidationFeatures = disabled.data();
    val.enabledValidationFeatureCount = to_uint32(N);
    val.disabledValidationFeatureCount = to_uint32(N);
  }
};

template <>
struct setVkVector<VkValidationFeaturesEXT,
                   VkValidataionFeatureEnableEXT,
                   VkValidataionFeatureDisableEXT> {
  static void
  set(VkValidationFeaturesEXT &val,
      const std::vector<VkValidataionFeatureEnableEXT>
          &enabled,
      const std::vector<VkValidataionFeatureDisableEXT>
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
