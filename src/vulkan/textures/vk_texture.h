#pragma once

#include "vulkan/system/vk_device.h"


class VkTexture
{
	VulkanDevice *vDevice;
    VkImage textureImage = VK_NULL_HANDLE;
    VmaAllocation textureImageAllocation = VK_NULL_HANDLE;
    VkImageView textureImageView = VK_NULL_HANDLE;
	
	VkResult CreateBuffer(VkDeviceSize size, VkBuffer& buffer, VmaAllocation& allocation);
	VkResult CreateImage(uint32_t width, uint32_t height, int mipmaps, VkImage& image, VmaAllocation& allocation);
	void CopyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
	void GenerateMipmaps(VkImage image, int32_t texWidth, int32_t texHeight, uint32_t mipLevels);
	VkResult CreateImageView(VkImage image, uint32_t mipLevels);
	void Destroy();

public:
	VkTexture(VulkanDevice *dev)
	{
		vDevice = dev;
	}
	~VkTexture()
	{
		Destroy();
	}

	VkResult Create(const char *pixels, int texWidth, int texHeight, bool mipmapped);

	VkImageView Handle() const { return textureImageView; }
};
	