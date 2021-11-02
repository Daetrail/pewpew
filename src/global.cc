#include <string>
#include <vector>
#include <array>

#include "Global.hh"

const std::vector<sf::IntRect> Global::jumpAnimations = {
    sf::IntRect(13, 7, 28, 31),
    sf::IntRect(61, 5, 28, 34)
};

const std::vector<sf::IntRect> Global::idleAnimations = {
    sf::IntRect(12, 7, 28, 32),
    sf::IntRect(60, 6, 28, 33),
    sf::IntRect(108, 6, 28, 33),
    sf::IntRect(156, 7, 28, 32),
    sf::IntRect(204, 7, 28, 32)
};

const std::vector<sf::IntRect> Global::runAnimations = {
    sf::IntRect(8, 5, 32, 34),
    sf::IntRect(53, 3, 35, 31),
    sf::IntRect(102, 5, 34, 34),
    sf::IntRect(152, 4, 32, 34),
    sf::IntRect(196, 3, 36, 31),
    sf::IntRect(248, 5, 32, 34),
};

// const std::vector<sf::IntRect> Global::jumpAnimations = {
//     sf::IntRect(13, 7, 40, 40),
//     sf::IntRect(61, 5, 40, 40)
// };

// const std::vector<sf::IntRect> Global::idleAnimations = {
//     sf::IntRect(12, 7, 40, 40),
//     sf::IntRect(60, 6, 40, 40),
//     sf::IntRect(108, 6, 40, 40),
//     sf::IntRect(156, 7, 40, 40),
//     sf::IntRect(204, 7, 40, 40)
// };

// const std::vector<sf::IntRect> Global::runAnimations = {
//     sf::IntRect(8, 5, 40, 40),
//     sf::IntRect(53, 3, 40, 40),
//     sf::IntRect(102, 5, 40, 40),
//     sf::IntRect(152, 4, 40, 40),
//     sf::IntRect(196, 3, 40, 40),
//     sf::IntRect(248, 5, 40, 40),
// };

const std::vector<sf::IntRect> Global::deathAnimations = {
    sf::IntRect(12, 7, 29, 32),
    sf::IntRect(62, 9, 29, 30),
    sf::IntRect(111, 12, 26, 30),
    sf::IntRect(155, 10, 29, 29),
    sf::IntRect(198, 16, 30, 23),
    sf::IntRect(244, 26, 35, 14),
    sf::IntRect(292, 25, 35, 15),
    sf::IntRect(340, 26, 35, 14)
};

const std::vector<sf::IntRect> Global::crouchAnimations = {
    sf::IntRect(12, 6, 28, 33),
    sf::IntRect(60, 7, 28, 32),
    sf::IntRect(109, 10, 28, 29)
};

const std::string Global::jumpFile = "res/images/player/jump.png";
const std::string Global::idleFile = "res/images/player/idle.png";
const std::string Global::runFile = "res/images/player/run.png";
const std::string Global::deathFile = "res/images/player/death.png";
const std::string Global::crouchFile = "res/images/player/crouch.png";

unsigned int Global::currentGameState = Global::mainMenu;

const std::string Global::TITLE = "Pew Pew";
const std::string Global::VERSION = "0.0.1";

const sf::Vector2f Global::VIEW_RESOLUTION = {640.f, 380.f};

const std::string Global::MENU_BACKGROUNDS = "res/images/background.png";
const std::string Global::GAME_BACKGROUND = "res/images/game/game-bg.jpg";
const std::string Global::FONT = "res/font/rainyhearts.ttf";

const std::vector<std::string> Global::MESSAGE = {// | <- Limit for line length, charSize = 50
    "Pew pew all your enemies! Get coins to buy better weapons! This",
    "is the first C++ SFML game that archaicfox, the developer of",
    "this game, made. Have fun and enjoy his bad pixel art drawings!",
    "Controls: W A S D, Left click to shoot, R to reload, 1 - 2 - 3",
    "to switch weapons, Esc to pause game, CTRL+P to open console." 
};
//                                                                 | <- Limit for line length, charSize = 40