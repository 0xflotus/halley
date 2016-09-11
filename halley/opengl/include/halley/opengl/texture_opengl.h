#pragma once

#include <halley/core/graphics/texture.h>
#include <halley/core/graphics/texture_descriptor.h>

namespace Halley
{
	enum class TextureFormat;

	class TextureOpenGL final : public Texture
	{
	public:
		explicit TextureOpenGL(const TextureDescriptor& descriptor, bool async);

		void bind(int textureUnit) override;

	private:
		void loadImage(const char* px, size_t w, size_t h, size_t stride, TextureFormat format, bool useMipMap);
		unsigned int create(size_t w, size_t h, TextureFormat format, bool useMipMap, bool useFiltering);

		static unsigned int getGLFormat(TextureFormat format);

		GLsync fence;
	};
}
