#include <SFML/Graphics.hpp>
#include <vector>

#include "Bullet.hh"

Bullet::Bullet(float scale)
{
    this->bulletSprite.setTexture(this->bulletTex);
    this->muzzleFlashSprite.setTexture(this->muzzleFlashTex);
    this->bulletSprite.setScale(scale, scale);
    this->muzzleFlashSprite.setScale(scale, scale);
    this->bulletSprite.setOrigin(this->bulletSprite.getGlobalBounds().width / 2, this->bulletSprite.getGlobalBounds().height);
}

void Bullet::update(Player &player, sf::Vector2f direction, float deltaTime)
{
    std::vector<float> size = player.getPosAndBounds();
    if (!this->posLock)
    {
        if (direction == sf::Vector2f(1.f, 0.f))
        {
            this->bulletSprite.setPosition(
                size[0] + (size[2] / 2) + (this->bulletSprite.getGlobalBounds().width / 2),
                size[1]
            );
        }
        else if (direction == sf::Vector2f(-1.f, 0.f))
        {
            this->bulletSprite.setPosition(
                size[0] - (size[2] / 2) - (this->bulletSprite.getGlobalBounds().width / 2),
                size[1]
            );
        }
        this->posLock = true;
    }

    this->totalTime += deltaTime;
}

void Bullet::draw(sf::RenderWindow &window, sf::Vector2f direction)
{
    if (this->isFired)
    {
        if (this->totalTime >= this->switchTime)
        {
            this->totalTime -= this->switchTime;

            if (direction == sf::Vector2f(1.f, 0.f))
                this->bulletSprite.move(this->speed, 0.f);
            else if (direction == sf::Vector2f(-1.f, 0.f))
                this->bulletSprite.move(this->speed * -1, 0.f);
        }

        window.draw(this->bulletSprite);

        if (this->bulletSprite.getPosition().x - this->bulletSprite.getGlobalBounds().width / 2 < 0 || 
            this->bulletSprite.getPosition().x + this->bulletSprite.getGlobalBounds().width / 2 > Global::GAME_BG_WIDTH)
            this->isFired = false;
    }

    
}