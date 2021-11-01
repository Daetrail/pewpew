#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <array>

struct Global
{
    enum buttonPresses
    {
        none,
        play,
        about,
        exit,
        back,
    };

    enum state
    {
        mainMenu,
        aboutMenu,
        game,
    };

    static const std::vector<sf::IntRect> jumpAnimations;
    static const std::vector<sf::IntRect> idleAnimations;
    static const std::vector<sf::IntRect> runAnimations;
    static const std::vector<sf::IntRect> deathAnimations;
    static const std::vector<sf::IntRect> crouchAnimations;

    static const std::string jumpFile;
    static const std::string idleFile;
    static const std::string runFile;
    static const std::string deathFile;
    static const std::string crouchFile;

    static unsigned int currentGameState;

    static const unsigned int WINDOW_WIDTH = 1280;
    static const unsigned int WINDOW_HEIGHT = 760;
    static const std::string TITLE;
    static const std::string VERSION;

    static const sf::Vector2f VIEW_RESOLUTION;

    static const unsigned int GAME_BG_WIDTH = 1920;
    static const unsigned int GAME_BG_HEIGHT = 1080;

    static const std::string MENU_BACKGROUNDS;
    static const std::string GAME_BACKGROUND;
    static const std::string FONT;

    static const std::vector<std::string> MESSAGE;
};