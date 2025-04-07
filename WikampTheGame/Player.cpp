#include "Player.hpp"

enum direction {
	LEFT = 0,
	TOP,
	RIGHT,
	BOTTOM
};

Player::Player(std::string path) : sf::Drawable(), txt{ path }, sprite{ txt }
{
	hitbox.setSize( sf::Vector2f{txt.getSize()} );

	sprite.setTextureRect({ sf::Vector2i{0, 0}, sf::Vector2i{txt.getSize()} });
	sprite.setColor({ 255, 255, 255, 200 });
	sprite.setPosition({ 100.f, 25.f });
	for (int i = 0; i < 4; i++) moveDiretion[i] = 0;
	speedHorizontaly = 1;
	speedVerticaly = 1;
}

void Player::update()
{
	if (moveDiretion[direction::LEFT]) this->move(sf::Vector2f{-speedHorizontaly, 0});
	if (moveDiretion[direction::TOP]) this->move(sf::Vector2f{ 0, -speedVerticaly });
	if (moveDiretion[direction::RIGHT]) this->move(sf::Vector2f{ speedHorizontaly, 0 });
	if (moveDiretion[direction::BOTTOM]) this->move(sf::Vector2f{ 0, speedVerticaly });
}

void Player::setMovementDirection(sf::Keyboard::Scan scancode, bool pressed)
{
	if (scancode == sf::Keyboard::Scancode::W)
		this->moveDiretion[direction::TOP] = pressed;
	else if (scancode == sf::Keyboard::Scancode::S)
		this->moveDiretion[direction::BOTTOM] = pressed;
	else if (scancode == sf::Keyboard::Scancode::A)
		this->moveDiretion[direction::LEFT] = pressed;
	else if (scancode == sf::Keyboard::Scancode::D)
		this->moveDiretion[direction::RIGHT] = pressed;
}

void Player::move(sf::Vector2f offset)
{
	this->sprite.setPosition( sprite.getPosition() + offset );
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);
}