# Vulkan Overloaded

This is an attempt to overload a single function to set all the structs of
vulkan. 
The overloading is based on types. For example for a given struct like:

```
struct VkPipelineViewportStateCreateInfo {

VkStructureType sType;

const void* pNext;

VkPipelineViewportStateCreateFlags flags;

uint32_t viewportCount;

const VkViewport* pViewports;

uint32_t scissorCount;

const VkRect2D* pScissors;
}
```
The overloaded function is like
```
constexpr void vk_set(VkPipelineViewportStateCreateInfo &createInfo){
    createInfo.sType = SOMEVALUE;
    }

void vk_set(
    VkPipelineViewportStateCreateInfo &createInfo,
    uint32_t viewportCount,
    uint32_t scissorCount,
){
    createInfo.viewportCount = viewportCount;
    createInfo.scissorCount = scissorCount;
    }

void vk_set(
    VkPipelineViewportStateCreateInfo &createInfo,
    const VkRect2D* scissors){createInfo.pScissors = scissors;}

void vk_set(
    VkPipelineViewportStateCreateInfo &createInfo,
    const VkViewport* viewports){createInfo.pViewports = viewports;}

void vk_set(
    VkPipelineViewportStateCreateInfo &createInfo,
    const void* pnext){createInfo.pNext = pnext;}

void vk_set(
    VkPipelineViewportStateCreateInfo &createInfo,
    VkPipelineViewportStateCreateFlags flags){
    createInfo.flags = flags;}

void vk_set(
    VkPipelineViewportStateCreateInfo &createInfo,
    const void* pNext,
    VkPipelineViewportStateCreateFlags flags,
    uint32_t viewportCount,
    const VkViewport* pViewports,
    uint32_t scissorCount,
    const VkRect2D* pScissors,
    ){
    vk_set(createInfo);
    vk_set(createInfo,pNext);
    vk_set(createInfo,flags);
    vk_set(createInfo,viewportCount, scissorCount);
    vk_set(createInfo,pViewports, pScissors);
    }
```
