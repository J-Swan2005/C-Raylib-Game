#include <iostream>
#include <vector> 
#include <array>
#include <string>
#include <cstdlib> 
#include <chrono> 
#include <thread>
#include "raylib.h"
#include <vector>
#include <array>


const int window_width = 400;
const int window_height = 400;

struct Sprite {
	Texture2D texture;
	int x_position;
	int y_position;
	int movement_speed = 1;
};


const int map_width = 4;
const int map_height = 4;

std::array<std::array<int,4>,4> map {{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}}
};

std::vector<Sprite> load_level(Texture2D tile_texture) {
	std::vector<Sprite> texture_map;

	for (int i = 0; i < map_width; ++i) {
		for (int y = 0; y < map_height; ++y) {
			int x_pos = i * 100;
			int y_pos = y * 100; 
			
			Sprite sprite;
			sprite.texture = tile_texture;
			sprite.x_position = x_pos;
			sprite.y_position = y_pos;
			
			texture_map.push_back(sprite);
		};
	}
	return texture_map;
};

void move_player(Sprite* player) {
	if (IsKeyDown(KEY_DOWN)) {
		player->y_position += player->movement_speed;
	};
	if (IsKeyDown(KEY_UP)) {
		player->y_position -= player->movement_speed;
	};
	
	
	if (player->y_position < 0 - 50) {
		player->y_position = -50;
	}
	
};

int main() {
	InitWindow(window_width,window_height,"Placeholder");
	SetTargetFPS(60);
	
	
	Texture2D player_idle_texture = LoadTexture("Assets/IdlePlayer.png");
	Sprite player;
	player.texture = player_idle_texture;
	player.x_position = 0;
	player.y_position = 0;
	
	Texture2D tile_texture = LoadTexture("Assets/GrassTexture.png");
	std::vector<Sprite> map_textures = load_level(tile_texture);
	

	while (!WindowShouldClose()) {
		//Update 
		move_player(&player);
		
		
		//Drawing
		BeginDrawing();
	
		ClearBackground(SKYBLUE);
		
		for (const auto &tiles : map_textures) {
			DrawTexture(tiles.texture, tiles.x_position, tiles.y_position, WHITE);
		};
		
		DrawTexture(player.texture, player.x_position, player.y_position, WHITE);
	
		std::cout << player.x_position << player.y_position;
		EndDrawing();
	
	};
	
	UnloadTexture(player_idle_texture);
	UnloadTexture(tile_texture);
	return 0;
};




















































/*
class Player{
public:
	int character_skin = 1;
	int y_position = 0;
	int x_position = 0;
public:
	std::tuple<int,int> get_current_location() {
		return std::tuple<int,int>{x_position,y_position};
	};
};

const int row_size = 4;
const int col_size = 3;

void print_map(std::array<std::array<int,row_size>,col_size>& map, Player current_player) {
	std::string res;
	if (current_player.x_position >= 0 && current_player.x_position <= row_size && current_player.y_position >= 0 && current_player.y_position <= col_size) {
		map[current_player.x_position][current_player.y_position] = current_player.character_skin;
	}
	
	for (int i = 0; i < col_size; ++ i) {
		for (int y = 0; y < row_size; ++y) {
			std::cout << map[i][y];
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));
};

void game_loop(std::array<std::array<int,row_size>,col_size>& map, Player current_player) {	
	//Printing
	print_map(map, current_player);
	std::system("clear");

};


int main() {
	bool game_running = true;
	Player current_player;
	std::array<std::array<int,row_size>,col_size> map = {{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}}};	
	while (game_running) {
		game_loop(map, current_player);
	};	
}
*/
//User Input Would be done With Raylib Anyways.
