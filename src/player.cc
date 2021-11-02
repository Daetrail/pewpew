#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Player.hh"
#include "Global.hh"

Player::Player(std::string jumpFile, std::string idleFile, std::string runFile, std::string deathFile, std::string crouchFile, float switchTime)
    : switchTime(switchTime)
{
    if (!this->jumpTexture.loadFromFile(jumpFile))
        std::cout << "Cannot load " << jumpFile << std::endl;
    if (!this->idleTexture.loadFromFile(idleFile))
        std::cout << "Cannot load " << idleFile << std::endl;
    if (!this->runTexture.loadFromFile(runFile))
        std::cout << "Cannot load " << runFile << std::endl;
    if (!this->deathTexture.loadFromFile(deathFile))
        std::cout << "Cannot load " << deathFile << std::endl;
    if (!this->crouchTexture.loadFromFile(crouchFile))
        std::cout << "Cannot load " << crouchFile << std::endl;

    this->currentTexture = &this->idleTexture;
    this->playerSprite.setTexture(*this->currentTexture);
    this->playerSprite.setTextureRect(this->currectVector[this->animationIndex]);

    this->playerSprite.setOrigin(this->playerSprite.getGlobalBounds().width / 2, this->playerSprite.getGlobalBounds().height / 2);
    this->playerSprite.setPosition(Global::GAME_BG_WIDTH / 2, Global::GAME_BG_HEIGHT - this->playerSprite.getGlobalBounds().height / 2);
    this->playerSprite.setScale(3.f, 3.f);
}

Player::Player() {}

Player::~Player()
{}

void Player::update(float deltaTime, unsigned int width, unsigned int height)
{


    if (!this->isMoving)
    {
        this->currectVector = Global::idleAnimations;
        this->currentTexture = &this->idleTexture;
        this->playerSprite.setTexture(*this->currentTexture);
        this->playerSprite.setScale(this->scale);
    }

    this->totalTime += deltaTime;

    if (this->totalTime >= this->switchTime)
    {
        this->totalTime -= this->switchTime;
        this->playerSprite.setTextureRect(this->currectVector[this->animationIndex]);

        this->animationIndex++;
        if (this->animationIndex >= this->currectVector.size())
            this->animationIndex = 0;
    }

    this->levelBoundary(width, height);
}

void Player::setSpeed(float speed)
{
    this->speed = speed;
}

void Player::notMoving()
{
    this->isMoving = false;
}

float Player::getSpeed()
{
    return this->speed;
}

sf::Vector2f Player::getPos()
{
    return sf::Vector2f(this->playerSprite.getPosition());
}

void Player::levelBoundary(unsigned int width, unsigned int height)
{
    if (this->playerSprite.getPosition().x - this->playerSprite.getGlobalBounds().width / 2 < 0)
    {
        this->playerSprite.setPosition(this->playerSprite.getGlobalBounds().width / 2, this->playerSprite.getPosition().y);
    }
    else if (this->playerSprite.getPosition().x + this->playerSprite.getGlobalBounds().width / 2 > width)
    {
        this->playerSprite.setPosition(width - this->playerSprite.getGlobalBounds().width / 2, this->playerSprite.getPosition().y);
    }
    else if (this->playerSprite.getPosition().y - this->playerSprite.getGlobalBounds().height / 2 < 0)
    {
        this->playerSprite.setPosition(this->playerSprite.getPosition().x, this->playerSprite.getGlobalBounds().height / 2);
    }
    else if (this->playerSprite.getPosition().y + this->playerSprite.getGlobalBounds().height / 2 > height)
    {
        this->playerSprite.setPosition(this->playerSprite.getPosition().x, height - this->playerSprite.getGlobalBounds().height / 2);
    }

    if (this->playerSprite.getPosition().y < Global::GAME_BG_HEIGHT  - this->playerSprite.getGlobalBounds().height / 2)
        this->playerSprite.move(0.f, this->speed);
}

void Player::setIdle()
{
    this->currentTexture = &this->idleTexture;
    this->playerSprite.setTexture(*this->currentTexture);
    this->currectVector = Global::idleAnimations;   
    this->playerSprite.setScale(this->scale);   
}

void Player::move(sf::Vector2f direction)
{
    if (direction == sf::Vector2f(1.f, 0.f))
    {
        this->currectVector = Global::runAnimations;
        this->currentTexture = &this->runTexture;
        this->playerSprite.setTexture(*this->currentTexture);
        this->playerSprite.setScale(this->scale);
        this->isMoving = true;
    }
    if (direction == sf::Vector2f(-1.f, 0.f))
    {
        this->currectVector = Global::runAnimations;
        this->currentTexture = &this->runTexture;
        this->playerSprite.setTexture(*this->currentTexture);
        this->playerSprite.setScale(this->scale.x * -1, this->scale.y);
        this->isMoving = true;
    }

    this->playerSprite.move(direction * this->speed);
}

void Player::jump()
{
    float dest = this->playerSprite.getPosition().y - this->jumpHeight;

    while (this->playerSprite.getPosition().y > dest)
        this->playerSprite.move(0.f, this->jumpSpeed * -1);
}

void Player::draw(sf::RenderWindow &window)
{
    window.draw(this->playerSprite);
}