#pragma once

#include <SFML/Graphics.hpp>
#include <string_view>

// Window:

namespace taic::constant
{

namespace window
{

constexpr uint32_t width = 1600;
constexpr uint32_t height = 900;
constexpr std::string_view title = "The Adventure In Caves";
constexpr uint32_t framerate = 60;

} // namespace window

namespace player
{

const sf::Vector2f bounding_box_size(40, 52);
const sf::Vector2f bounding_box_origin(20, 26);
const sf::Color bounding_box_color(255, 0, 0, 100);

const sf::Vector2i texture_size(48, 64);   // P_FRAMESIZE
const sf::Vector2f texture_origin(24, 32); // P_FRAMESIZE2

} // namespace player

namespace other
{

const sf::Color collectible_color(180, 250, 0, 100);

} // namespace other

} // namespace taic::constant

#define W_WIDTH 1600
#define W_HEIGHT 900
#define W_TITLE "Just a simple platformer"
#define W_FRAMERATE 60
#define W_BLOCKSIZE 50

// World:
#define G_COLLECTIBLE sf::Color(180, 250, 0, 100)

// Player:
#define P_FRAMESIZE sf::Vector2i(48, 64)
#define P_FRAMESIZE2 sf::Vector2f(24, 32)

// Enemy:
#define E_FRAMESIZE sf::Vector2i(64, 64)
#define E_FRAMESIZE2 sf::Vector2f(32, 32)

// Collectibles:
#define C_FRAMESIZE sf::Vector2i(200, 200)
#define H_FRAMESIZE sf::Vector2i(200, 200)
