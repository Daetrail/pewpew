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
    this->playerSprite.setPosition(Global::WINDOW_WIDTH / 2, Global::WINDOW_HEIGHT / 2);
    this->playerSprite.setScale(3.f, 3.f);
}

Player::Player() {}

Player::~Player()
{}

void Player::update(float deltaTime)
{
    this->totalTime += deltaTime;

    if (this->totalTime >= this->switchTime)
    {
        this->totalTime -= this->switchTime;
        this->playerSprite.setTextureRect(this->currectVector[this->animationIndex]);

        this->animationIndex++;
        if (this->animationIndex >= this->currectVector.size())
            this->animationIndex = 0;
    }

    if (!this->isMoving)
    {
        this->currentTexture = &this->idleTexture;
        this->playerSprite.setTexture(*this->currentTexture);
        this->animationIndex = (this->animationIndexLock) ? this->animationIndex : 0;
        this->currectVector = Global::idleAnimations;
        this->playerSprite.setScale(this->scale);
        this->animationIndexLock = true;
    }
    else
        this->animationIndexLock = false;
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

void Player::levelBoundary(unsigned int &width, unsigned int &height)
{
    if (this->playerSprite.getPosition().x - this->playerSprite.getGlobalBounds().width / 2 < 0)
    {
        this->playerSprite.move(sf::Vector2f(1, 0) * this->speed);
        this->setIdle();
    }
    else if (this->playerSprite.getPosition().x + this->playerSprite.getGlobalBounds().width / 2 > width)
    {
        this->playerSprite.move(sf::Vector2f(-1, 0) * this->speed);
    }
    else if 
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
        this->currentTexture = &this->runTexture;
        this->currectVector = Global::runAnimations;
        this->playerSprite.setTexture(*this->currentTexture);
        this->playerSprite.setScale(this->scale);
        this->isMoving = true;
    }
    if (direction == sf::Vector2f(-1.f, 0.f))
    {
        this->currentTexture = &this->runTexture;
        this->currectVector = Global::runAnimations;
        this->playerSprite.setTexture(*this->currentTexture);
        this->playerSprite.setScale(this->scale.x * -1, this->scale.y);
        this->isMoving = true;
    }

    this->playerSprite.move(direction * this->speed);
}

void Player::draw(sf::RenderWindow &window)
{
    window.draw(this->playerSprite);
}