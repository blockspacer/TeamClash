#pragma once

#include "Block.h"

#include <Godot.hpp>
#include <WorldEnvironment.hpp>
#include <Vector2.hpp>
#include <ResourceLoader.hpp>

#include <map>
#include <memory>

namespace godot
{
	class World : public WorldEnvironment
	{
		GODOT_CLASS(World, WorldEnvironment)

	public:
		static void _register_methods();

		World() = default;
		~World() = default;

		void _init();
		void _ready();
		void generateMap();

	private:
		void placeBlock(BlockType blockType, Vector2 position);

		std::map<Vector2, std::unique_ptr<godot::Block>> blocks_;

		const int blockSize_ = 32;
		const int amplitude_ = 4;
		const int stretch_ = 10;
		const int worldLengthInBlocks_ = 1000;
		const double degToRadCoefficient = Math_PI / 180;
		const int worldDepth_ = 50;
		ResourceLoader* resourceLoader_;
	};
}