#pragma once
#include "../utils/ntshengn_utils_math.h"
#include <cstdint>
#include <array>
#include <vector>
#include <unordered_map>

namespace NtshEngn {

	// Image
	typedef uint32_t ImageID;
	#define NTSHENGN_IMAGE_UNKNOWN 0xFFFFFFFF

	enum class ImageFormat {
		R8,
		R8G8,
		R8G8B8,
		R8G8B8A8,
		R16,
		R16G16,
		R16G16B16,
		R16G16B16A16,
		R32,
		R32G32,
		R32G32B32,
		R32G32B32A32,
		Unknown
	};

	enum class ImageColorSpace {
		Linear,
		SRGB,
		Unknown
	};

	enum class ImageSamplerFilter {
		Linear,
		Nearest,
		Unknown
	};

	enum class ImageSamplerAddressMode {
		Repeat,
		MirroredRepeat,
		ClampToEdge,
		ClampToBorder,
		Unknown
	};

	enum class ImageSamplerBorderColor {
		FloatTransparentBlack,
		IntTransparentBlack,
		FloatOpaqueBlack,
		IntOpaqueBlack,
		FloatOpaqueWhite,
		IntOpaqueWhite,
		Unknown
	};

	struct Image {
		// Image width
		uint32_t width = 0;
		
		// Image height
		uint32_t height = 0;

		// Image format
		ImageFormat format = ImageFormat::Unknown;

		// Image color space
		ImageColorSpace colorSpace = ImageColorSpace::Unknown;

		// Data
		std::vector<uint8_t> data;
	};

	// Image Sampler
	struct ImageSampler {
		// Magnification filter
		ImageSamplerFilter magFilter = ImageSamplerFilter::Unknown;

		// Minification filter
		ImageSamplerFilter minFilter = ImageSamplerFilter::Unknown;

		// Mipmap filter
		ImageSamplerFilter mipmapFilter = ImageSamplerFilter::Unknown;

		// Address mode U
		ImageSamplerAddressMode addressModeU = ImageSamplerAddressMode::Unknown;

		// Address mode V
		ImageSamplerAddressMode addressModeV = ImageSamplerAddressMode::Unknown;

		// Address mode W
		ImageSamplerAddressMode addressModeW = ImageSamplerAddressMode::Unknown;

		// Border color
		ImageSamplerBorderColor borderColor = ImageSamplerBorderColor::Unknown;

		// Anisotropy
		float anisotropyLevel = 0.0f;
	};

	// Texture
	struct Texture {
		Image* image = nullptr;
		ImageSampler imageSampler;
	};

	// Material
	struct Material {
		// Diffuse (base color) texture
		Texture diffuseTexture;

		// Normal texture
		Texture normalTexture;

		// Metalness, Roughness and Occlusion textures can be the same one
		// In that case, R = Occlusion, G = Roughness, B = Metalness
		// Metalness texture
		Texture metalnessTexture;

		// Roughness texture
		Texture roughnessTexture;
		
		// Occlusion texture
		Texture occlusionTexture;
		
		// Emissive texture
		Texture emissiveTexture;
		float emissiveFactor = 1.0f;

		// Alpha cutoff
		float alphaCutoff = 0.0f;

		// Index of refraction
		float indexOfRefraction = 1.0f;
	};

	// Animation
	enum class AnimationChannelInterpolationType {
		Step,
		Linear,
		CubicSpline,
		Unknown
	};

	enum class AnimationChannelTransformType {
		Translation,
		Rotation,
		Scale,
		Unknown
	};

	struct AnimationChannelKeyframe {
		float timestamp = 0.0f;
		Math::vec4 value;
	};

	struct AnimationChannel {
		AnimationChannelInterpolationType interpolationType = AnimationChannelInterpolationType::Unknown;
		AnimationChannelTransformType transformType = AnimationChannelTransformType::Unknown;
		std::vector<AnimationChannelKeyframe> keyframes;
	};

	struct Animation {
		float duration = 0.0f;
		std::unordered_map<uint32_t, std::vector<AnimationChannel>> jointChannels;
	};

	// Mesh
	typedef uint32_t MeshID;
	#define NTSHENGN_MESH_UNKNOWN 0xFFFFFFFF

	enum class MeshTopology {
		TriangleList,
		TriangleStrip,
		LineList,
		LineStrip,
		PointList,
		Unknown
	};

	// Vertex
	struct Vertex {
		Math::vec3 position;
		Math::vec3 normal;
		Math::vec2 uv;
		Math::vec3 color;
		Math::vec4 tangent;
		std::array<uint32_t, 4> joints = { 0, 0, 0, 0 };
		Math::vec4 weights;
	};

	// Skin
	struct Joint {
		Math::mat4 inverseBindMatrix;
		Math::mat4 localTransform;
		std::vector<uint32_t> children;
	};

	struct Skin {
		std::vector<Joint> joints;
		uint32_t rootJoint = 0;
		Math::mat4 baseMatrix;
		Math::mat4 inverseGlobalTransform;
	};

	struct Mesh {
		std::vector<Vertex> vertices;
		std::vector<uint32_t> indices;
		Skin skin;
		MeshTopology topology = MeshTopology::Unknown;
	};

	// Model
	struct ModelPrimitive {
		Mesh mesh;
		Material material;
	};

	struct Model {
		std::vector<ModelPrimitive> primitives;
		std::vector<Animation> animations;
	};

	// Font
	typedef uint32_t FontID;
	#define NTSHENGN_FONT_UNKNOWN 0xFFFFFFFF

	struct FontGlyph {
		Math::vec2 positionTopLeft = { 0.0f, 0.0f };
		Math::vec2 positionBottomRight = { 0.0f, 0.0f };
		float positionAdvance = 0.0f;
		Math::vec2 uvTopLeft = { 0.0f, 0.0f };
		Math::vec2 uvBottomRight = { 0.0f, 0.0f };
	};

	struct Font {
		Image* image = nullptr;
		ImageSamplerFilter imageSamplerFilter = ImageSamplerFilter::Unknown;
		std::unordered_map<char, FontGlyph> glyphs;
	};

}