#include <iostream>
#include <SFML/Graphics.hpp>

#include "MainMenu.hh"
#include "AboutMenu.hh"
#include "Game.hh"
#include "Global.hh"
#include "Button.hh"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(Global::WINDOW_WIDTH, Global::WINDOW_HEIGHT), Global::TITLE, sf::Style::Titlebar | sf::Style::Close, settings);
    window.setVerticalSyncEnabled(true);
    window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - Global::WINDOW_WIDTH / 2, sf::VideoMode::getDesktopMode().height / 2 - Global::WINDOW_WIDTH / 3));

    sf::View view(sf::Vector2f(0.f, 0.f), Global::VIEW_RESOLUTION);
    sf::View ordinaryView(sf::Vector2f(static_cast<float>(window.getSize().x / 2), static_cast<float>(window.getSize().y / 2)), sf::Vector2f(static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)));

    sf::Font font1;
    if (!(font1.loadFromFile(Global::FONT)))
        std::cout << "Unable to load font1!" << std::endl;

    /* ----------------------------------------------------------- */

    MainMenu mainMenu(Global::MENU_BACKGROUNDS, font1);
    AboutMenu aboutMenu(mainMenu.getTexture(), font1);
    Game game(Global::GAME_BACKGROUND, window);

    /* ----------------------------------------------------------- */

    sf::Vector2i mousePos;

    float deltaTime = 0.f;

    sf::Clock clock;

    sf::Event event;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        mousePos = sf::Mouse::getPosition(window);

        while(window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape && Global::currentGameState == Global::game)
                    {
                        Global::currentGameState = Global::mainMenu;
                    }
                    break;
            }

            if (mainMenu.buttonPressed(mousePos, event) == Global::play)
            {
                Global::currentGameState = Global::game;
            }

            else if (mainMenu.buttonPressed(mousePos, event) == Global::about)
                Global::currentGameState = Global::aboutMenu;

            else if (mainMenu.buttonPressed(mousePos, event) == Global::exit)
            {
                window.close();
                break;
            }

            if (aboutMenu.buttonPressed(mousePos, event) == Global::back)
                Global::currentGameState = Global::mainMenu;

            switch (Global::currentGameState)
            {
                case Global::game:
                    game.handlePlayerEvent(event);
                    break;
                default:
                    break;
            }
        }

        switch (Global::currentGameState)
        {
            case Global::mainMenu:

                mainMenu.detectHover(mousePos); 
                break;
            
            case Global::aboutMenu:
                aboutMenu.detectHover(mousePos);
                break;

            case Global::game:
                game.handlePlayerMovements();

                view.setCenter(game.getWinPlayerPos());

                if (view.getCenter().x - view.getSize().x / 2 < 0)
                    view.setCenter(sf::Vector2f(view.getSize().x / 2, view.getCenter().y));
                if (view.getCenter().x + view.getSize().x / 2 > Global::GAME_BG_WIDTH)
                    view.setCenter(sf::Vector2f(Global::GAME_BG_WIDTH - view.getSize().x / 2, view.getCenter().y));
                if (view.getCenter().y - view.getSize().y / 2 < 0)
                    view.setCenter(sf::Vector2f(view.getCenter().x, view.getSize().y / 2));
                if (view.getCenter().y + view.getSize().y / 2 > Global::GAME_BG_HEIGHT)
                    view.setCenter(sf::Vector2f(view.getCenter().x, Global::GAME_BG_HEIGHT - view.getSize().y / 2));

                window.setView(view);

                game.update(deltaTime, Global::GAME_BG_WIDTH, Global::GAME_BG_HEIGHT);
                break;

            default:
                break;
        }

        window.clear(sf::Color::Black);

        switch (Global::currentGameState)
        {   
            case Global::mainMenu:
                window.setView(ordinaryView);
                mainMenu.draw(window);
                break;
            
            case Global::aboutMenu:
                aboutMenu.draw(window);
                break;

            case Global::game:
                game.draw(window);
                break;

            default:
                break;
        }

        window.display();
    }

    return 0;
}
