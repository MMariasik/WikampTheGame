#pragma once

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable
{
public:
	Player(std::string path);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update();
	void setMovementDirection(sf::Keyboard::Scan scancode, bool pressed);

private:
	void move(sf::Vector2f offset);
	
	sf::RectangleShape hitbox;
	sf::Sprite sprite;
	sf::Texture txt;
	float speedVerticaly;
	float speedHorizontaly;
	bool moveDiretion[4]; // left, top, right, bottom
};