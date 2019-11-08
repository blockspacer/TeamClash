#pragma once
#include <core/Godot.hpp>
#include <Node2D.hpp>
#include <NetworkedMultiplayerENet.hpp>

namespace godot
{
	class CreateGameScene : public Node2D
	{
        GODOT_CLASS(CreateGameScene, Node2D)

    private:
        std::unique_ptr<NetworkedMultiplayerENet> networkPeer_;

	public:
		CreateGameScene() = default;
		~CreateGameScene() = default;

		static void _register_methods();
		void _init();
		void _on_StartGameButton_pressed(Variant body);


	};
}