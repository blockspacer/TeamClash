#include "CreateGameScene.h"
#include <iostream>

#include <SceneTree.hpp>

using namespace godot;

void CreateGameScene::_register_methods()
{
	register_method((char*)"_on_StartGameButton_pressed", &CreateGameScene::_on_StartGameButton_pressed);
}

void CreateGameScene::_init()
{

}

void CreateGameScene::_on_StartGameButton_pressed(Variant body)
{
	std::cout << "Start game button pressed." << std::endl;
    String playerName = "Player1";
    get_node("/root/Network")->call("createServer", playerName);
    get_tree()->change_scene("res://scenes/Game.tscn");
}
